#pragma once

#include <iostream>
#include <ctime>

#include "bird.hpp"
#include "pipe.hpp"
#include "gameState.hpp"

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

    /* Update the speed of the game and 
     * reduce the time between consecutive pipes spawning
     * @return void
     */
    void updateSpeedAndInterval();
    void update();

    //Renders
    void renderPipes();
    void renderText();
    void render();

    private:
    //Functions
    void initVariables();
    void initWindow();
    void initState();
    void initCharacter();
    void initPipes();

    //Variables
    //Window
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;
    std::string title;
    unsigned framerate_limit;

    //Game objects
    Bird* bird;
    Pipe* pipe;

    //States
    std::stack<State*> states;

    //Mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    std::vector<std::pair<Pipe*, Pipe*>> pipes;

    //Resourses

    //Game logic
    bool endGame;

    //Interval for consecutive pipes to be spawn
    float pipeSpawnTimerMax;

    /* Record the accumulation of ten seconds. It is float for easily type conversion.
       It is a fairly smooth transition */
    float oneSecond;
    /* Record the accumulation of ten seconds. It is float for easily type conversion.
       However, it is NOT a smooth transition */
    float tenSeconds;
    /* Record the accumulation of fifteen seconds. It is float for easily type conversion.
      However, it is NOT a smooth transition */
    float fifteenSeconds;

    //The timer times the given second and resets often
    sf::Clock timer; /* these two lines are causing segmentation fault right now. FIXME: */
    //The clock never resets unless at the very beginning
    sf::Clock clock;
    sf::Time time;

    //TODO:
    float dt;

    unsigned points;
    unsigned maxPipes;

    bool mouseHeld;

    //Speed of the game
    float movingSpeed;
};