#include "bird.hpp"

Bird::Bird() : isAlive_(true) 
{
    this->initTexture();
    this->initSprite();
}

//Private functions
void Bird::initTexture() {
    this->texture.loadFromFile("textures/blue_bird3.png");
}

void Bird::initSprite() {
    this->sprite.setTexture(this->texture);
    //Adjust the size
    this->sprite.setScale(5.f, 5.f);

    this->sprite.setPosition(600.f - this->sprite.getGlobalBounds().width / 2.f, 
                             750.f - this->sprite.getGlobalBounds().height / 2.f);
}

//Public functions
void Bird::jump() {

}

bool Bird::OnEdge() {
    return true;
}

void Bird::update() {

}

void Bird::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}