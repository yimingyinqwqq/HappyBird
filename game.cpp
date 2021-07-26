#include "game.hpp"

//Constructors / Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPipes();
    this->initCharacter();
}

Game::~Game() {
    
    delete this->window;
    this->window = nullptr;
    delete this->bird;
    this->bird = nullptr;

    //FIXME: check!
    for (auto & pi : pipes) {
        delete pi;
        pi = nullptr;
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

}

void Game::spawnPipes() {
    float randomYPosUpOrDown = 0.f;
    if (std::rand() % 2 == 0) {
        randomYPosUpOrDown = 950.f;
    }

    //Construct a new pipe
    this->pipe = new Pipe(0.f, 0.f, 1.f);
    //SetPostion of the pipe at the rightmost of the screen
    this->pipe->setPosition(
        static_cast<float>(this->window->getSize().x),
        randomYPosUpOrDown + static_cast<float>(std::rand() % 100)
    );
    /*
    this->pipe->setPosition(
        static_cast<float>(std::rand() % static_cast<int>(this->window->getSize().x - this->pipe->getSize().width)),
        randomYPosUpOrDown + static_cast<float>(std::rand() % 100)
    );
    */
    this->pipes.push_back(this->pipe);
    
    //Remove pipes if they reach the end of screen
    //TODO:
}

void Game::updatePipes() {
    //Update the timer for pipe spawning
    if (this->pipes.size() < this->maxPipes) {
        if (this->pipeSpawnTimer >= this->pipeSpawnTimerMax) {
            //Spawn the pipe and reset the timer
            //TODO:
            this->spawnPipes();
            this->pipeSpawnTimer = 0.f;
        } else {
            this->pipeSpawnTimer += 1.f;
        }
    }

    //Move and update pipes
    for (unsigned i = 0; i < this->pipes.size(); ++i) {
        //bool deleted = false;

        this->pipes[i]->update();
        //Remove the pipe if it goes beyond the left of the screen
        if (this->pipes[i]->getPosition().x < -99.f) {
            this->pipes.erase(this->pipes.begin() + i);
        }
        //Add points if the bird jumps through the pipe
        if (this->pipes[i]->getPosition().x == 599.f) {
            ++points;
            //std::cout << this->points << std::endl;
        }
    }

    //Check is the mouse button is pressed but not holding all the time
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {
        if (this->mouseHeld == false) {
            this->mouseHeld = true;
            //TODO:
            //bool donext;

            if (this->pipes[0]->getSize().contains(this->mousePosView))
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

void Game::update() {
    this->pollEvents();
    

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
    }

}

void Game::renderPipes() {
    for (auto & pi : this->pipes) {
        pi->render(*this->window);
    }

}

void Game::renderText() {

}

void Game::render() {
    this->window->clear(sf::Color(100,23,230,0)); // Clear old frames

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
    this->videoMode.height = 1500;
    this->videoMode.width = 1200;
    
    this->window = nullptr;

    this->points = 0;
    this->pipeSpawnTimerMax = 30.f;
    this->pipeSpawnTimer = this->pipeSpawnTimerMax;
    
    this->maxPipes = 5;
    this->mouseHeld = false;
    this->endGame = false;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(this->videoMode, "Happy Bird!", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

void Game::initCharacter() {
    this->bird = new Bird();
}

void Game::initPipes() {
    this->pipe = new Pipe(0.f, 0.f, 1.f);
    this->pipes.push_back(this->pipe);
}