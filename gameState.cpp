#include "gameState.hpp"

GameState::GameState(sf::RenderWindow* window) : State(window) {
    window->isOpen();
}

GameState::~GameState() {

}

void GameState::checkForQuit() {

}

void GameState::updateKeybinds(const float& dt) {
    (void) dt; 
}

void GameState::update(const float& dt) {
    (void) dt;
}

void GameState::render(sf::RenderTarget* target) {
    target->getSize();
}