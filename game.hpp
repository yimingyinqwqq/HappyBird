#pragma once

#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <ctime>

#include "bird.hpp"
#include "pipe.hpp"

/*
    Class that acts as a game engine
*/

class Game {
    public:
    //Constructors / Destructors
    Game();
    ~Game();

    //Accessors
    bool running() const;
    bool getEndGame() const;

    //Functions
    void pollEvents();



    //Updates
    /* Updates the mouse position relative to window
     * @return void
     */
    void updateMousePos();

    /* Spawns Pipes and set their positions\n
     * Set a random position and random headings
     * @return void
     */
    void spawnPipes();

    void updateCharacter();
    void updatePipes();
    void updateText();
    void update();

    //Renders
    void renderPipes();
    void renderText();
    void render();

    private:
    //Functions
    void initVariables();
    void initWindow();
    void initCharacter();
    void initPipes();

    //Variables
    //Window
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    //Game objects
    Pipe* pipe;
    //Pipe* pipe;
    Bird* bird;

    //Mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    std::vector<std::pair<Pipe*, Pipe*>> pipes;

    //Resourses

    //Game logic
    bool endGame;

    float pipeSpawnTimer;
    float pipeSpawnTimerMax;

    sf::Clock clock;
    sf::Time time;

    unsigned points;
    unsigned maxPipes;

    bool mouseHeld;

    //Speed of the game
    float movingSpeed;
};