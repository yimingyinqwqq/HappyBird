#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Pipe {
    public:
    /* default constuctor */
    Pipe();

    /* paramatrized constructor
     * @param dirX,dirY: directions of movement
     * @param movement_speed: speed of movement
     * @return NOTE that the pipe is set defaultly DOWNWARD, use COPY CONSTRUCTOR to set it UPWARD.
     */
    Pipe(float dirX, float dirY, float movement_speed);

    /* copy constructor
     * @param pipe: the thing to be copied.
     * @return NOTE that the pipe is set UPWARD using this copy constructor to form a pair.
     */
    Pipe(const Pipe& pipe);

    ~Pipe();

    /* Judges the position of the pipe.
     * @return true if the pipe has a out-of-bound y-position, false otherwise.
     */
    bool OnEdge();

    
    /* @return the position of the pipe in sf::Vector2f format. */
    const sf::Vector2f& getPosition() const;

    /* set the position of the pipe in sf::Vector2f format.
     * @return void
     */
    //void setPosition(float PosX, float PosY);

    const sf::FloatRect getGlobalBounds() const;


    void update();
    void render(sf::RenderTarget& target);

    private:
    //Variables
    sf::Vector2f direction;
    float movementSpeed;
    bool UpOrDownward;

    float positionOfFirstPipe;
    float heightOfFirstPipe;
    //distance between two pipes
    const float disBetTwoPipes = 400.f;

    sf::Sprite sprite;
    sf::Texture* texture;

    //Functions
    void initTexture();
    void initSprite();
};