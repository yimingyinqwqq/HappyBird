#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Bird {
    public:
    /* default constuctor */
    Bird();

    /* controls the movement of the bird by using space on the keyboard */
    void jump();

    /* Judges the position of the bird.
     * @return true if the bird has a out-of-bound y-position, false otherwise.
     */
    bool OnEdge();

    /* Judges the state of the bird.
     * @return true if the bird is alive, false otherwise.
     */
    bool IsAlive() { return isAlive_; }

    void update();
    void render(sf::RenderTarget& target);

    private:
    //Variables
    bool isAlive_;

    sf::Sprite sprite;
    sf::Texture texture;

    //Functions
    void initTexture();
    void initSprite();
};