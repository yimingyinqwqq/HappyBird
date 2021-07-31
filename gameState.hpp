#pragma once

#include "state.hpp"

class GameState : public State {
    public:
    /* default constuctor */
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void checkForQuit();

    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    
    private:
    //Variables
    std::vector<sf::Texture> textures;
};