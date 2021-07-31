#include "game.hpp"

//Constructors / Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initState();
    this->initPipes();
    this->initCharacter();
}

Game::~Game() {
    
    delete this->window;
    this->window = nullptr;

    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
    
    delete this->bird;
    this->bird = nullptr;

    //FIXME: check!
    for (auto & pi : pipes) {
        delete pi.first;
        delete pi.second;
        pi.first = nullptr;
        pi.second = nullptr;
    }
}


//public functions
void Game::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                } else if (this->event.key.code == sf::Keyboard::Space) {
                    //TODO: bird jump  should solve the issue with holding the space button
                    this->bird->jump();
                }
                break;


            default:
                break;
        }
    }
}

void Game::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateCharacter() {
    //Changing frame of the bird
}

void Game::spawnPipes() {
    //Construct a pair of new pipe
    Pipe* first = new Pipe(-2.f, 0.f, this->movingSpeed);
    Pipe* second = new Pipe(*first);

    this->pipes.push_back(std::make_pair(first, second));
}

void Game::updatePipes() {
    //Update the timer for pipe spawning
    if (this->pipes.size() < this->maxPipes) {
        this->time = timer.getElapsedTime();
        if (this->time.asSeconds() >= this->pipeSpawnTimerMax) {
            //Spawn the pipe and reset the timer
            this->spawnPipes();
            this->timer.restart();
        }
    }

    //Move and update pipes
    for (unsigned i = 0; i < this->pipes.size(); ++i) {
        this->pipes[i].first->update();
        this->pipes[i].second->update();
        //Remove the pipe if it goes beyond the left of the screen
        if (this->pipes[i].first->getPosition().x < -1 * this->pipes[i].first->getGlobalBounds().width) {
            delete this->pipes[i].first;
            delete this->pipes[i].second;
            this->pipes.erase(this->pipes.begin() + i);
        }
        //Add points if the bird jumps through the pipe
        if (this->pipes[i].first->getPosition().x == static_cast<float>(this->window->getSize().x) / 2.f) {
            ++points;
        }
    }

    //Check is the mouse button is pressed but not holding all the time
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {
        if (this->mouseHeld == false) {
            this->mouseHeld = true;
            //TODO:
            //bool donext;

            if (this->pipes[0].first->getGlobalBounds().contains(this->mousePosView) ||
                this->pipes[0].second->getGlobalBounds().contains(this->mousePosView))
            {
                //DO THINGS
            }

        }
    }
    else
    {
        this->mouseHeld = false;
    }
}

void Game::updateText() {

}

void Game::updateSpeedAndInterval() {
    //Speed up the game
    this->time = clock.getElapsedTime();
    //The game will speed up to 130s and then stop speeding
    if (this->time.asSeconds() > oneSecond && oneSecond <= 100.f) {
        //Accelerating every second for smooth transition
        this->movingSpeed += 0.01f * this->movingSpeed;
        oneSecond += 1.f;
    }

    //TODO: create not smooth transition using tenSeconds


    //Reduce the interval
    this->time = clock.getElapsedTime(); //Get time again to increase accuracy
    if (this->time.asSeconds() > fifteenSeconds && fifteenSeconds <= 90.f) {
        this->pipeSpawnTimerMax -= 0.45f;
        fifteenSeconds += 15.f;
    }
}

void Game::update() {
    this->pollEvents();

    //Update the state
    
    if (!this->states.empty()) {
        this->states.top()->update(this->dt);
    }
    

    if (!this->endGame) {
        //Update mouse position
        /* Relative to the screen */
        //std::cout << "mouse: " << sf::Mouse::getPosition().x 
        //          << " " << sf::Mouse::getPosition().y << std::endl;

        /* Relative to the window */
        //std::cout << "mouse: " << sf::Mouse::getPosition(*this->window).x 
        //          << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
        
        this->updateMousePos();
        this->updateCharacter();
        this->updatePipes();
        this->updateText();
        this->updateSpeedAndInterval();
    }

}

void Game::renderPipes() {
    for (auto & pi : this->pipes) {
        pi.first->render(*this->window);
        pi.second->render(*this->window);
    }

}

void Game::renderText() {

}

void Game::render() {
    this->window->clear(sf::Color(100,23,230,0)); // Clear old frames

    //Render the current state
    if (!this->states.empty()) {
        this->states.top()->render(this->window);
    }

    //Draw game objects
    this->bird->render(*this->window);
    this->renderPipes();
    this->renderText();

    this->window->display(); // Tell app that window is done drawing
    
}

//accessors
bool Game::running() const {
    return this->window->isOpen();
}

///////////////////////////////////////////////////////////////////////////////////
//private functions
void Game::initVariables() {
    //Set default like that. But the actually setting is in config/window.ini file
    this->videoMode.height = 1500;
    this->videoMode.width = 1200;
    this->title = "Happy Bird!";
    this->framerate_limit = 144;
    this->window = nullptr;
    
    this->points = 0;

    //Set the pipe such that it spawns three second at a time. Will be adjusted for faster pace later.
    this->pipeSpawnTimerMax = 4.f;

    //Speed up after first 1s has passed
    this->oneSecond = 1.f;
    //Speed up after first 10s has passed
    this->tenSeconds = 10.f;
    //Reduce interval after first 15s has passed
    this->fifteenSeconds = 15.f;

    this->timer.restart();
    this->clock.restart();
    this->time = clock.getElapsedTime();

    //TODO:
    this->dt = 0.1f;
    
    this->maxPipes = 5;
    this->mouseHeld = false;
    this->endGame = false;

    this->movingSpeed = 1.f;
}

void Game::initWindow() {
    /* Create a SFML window using a window.ini file */
    std::ifstream ifs("config/window.ini");

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> videoMode.height >> videoMode.width;
        ifs >> framerate_limit;
    }

    ifs.close();
    
    this->window = new sf::RenderWindow(this->videoMode, title, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(framerate_limit);
}

void Game::initState() {
    this->states.push(new GameState(this->window));
}

void Game::initCharacter() {
    this->bird = new Bird();
}

void Game::initPipes() {
    this->spawnPipes();
}