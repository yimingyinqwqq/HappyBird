#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class State {
    public:
    /* default constuctor */
    State(sf::RenderWindow* window);
    virtual ~State();

    bool getQuit() const;

    virtual void checkForQuit();

    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    
    private:
    //Variables
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;
};