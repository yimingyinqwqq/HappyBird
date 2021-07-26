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

    Pipe(float dirX, float dirY, float movement_speed);

    ~Pipe();

    /* controls the movement of the pipe */
    void move(const float dirX, const float dirY);

    /* Judges the position of the pipe.
     * @return true if the pipe has a out-of-bound y-position, false otherwise.
     */
    bool OnEdge();

    
    /* @return the position of the pipe in sf::Vector2f format. */
    const sf::Vector2f& getPosition();

    /* set the position of the pipe in sf::Vector2f format.
     * @return void
     */
    void setPosition(float PosX, float PosY);

    const sf::FloatRect getSize();


    void update();
    void render(sf::RenderTarget& target);

    private:
    //Variables
    sf::Vector2f direction;
    float movementSpeed;

    sf::Sprite sprite;
    sf::Texture* texture;

    //Functions
    void initTexture();
    void initSprite();
};