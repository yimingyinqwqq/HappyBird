#include "bird.hpp"

Bird::Bird() : isAlive_(true) 
{
    this->initTexture();
    this->initSprite();
}

//Private functions
void Bird::initTexture() {
    //Randomly initialize a texture
    int random = std::rand() % 3;

    if (random == 0) {
        this->texture.loadFromFile("textures/blue_bird1.png");
    } else if (random == 1) {
        this->texture.loadFromFile("textures/red_bird1.png");
    } else {
        this->texture.loadFromFile("textures/yellow_bird1.png");
    }
}

void Bird::initSprite() {
    this->sprite.setTexture(this->texture);
    //Adjust the size
    this->sprite.setScale(4.f, 4.f);

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