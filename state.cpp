#include "state.hpp"

State::State(sf::RenderWindow* window) {
    this->window = window;
}

State::~State() {

}

bool State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    this->quit = true;
}