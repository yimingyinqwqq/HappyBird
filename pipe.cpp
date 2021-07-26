#include "pipe.hpp"

Pipe::Pipe() {}

Pipe::Pipe(float dirX, float dirY, float movement_speed) :
direction(sf::Vector2f(dirX, dirY)) , movementSpeed(movement_speed)
{
    this->initTexture();
    this->initSprite();
}

Pipe::~Pipe() {

}

void Pipe::initTexture() {
    this->texture = new sf::Texture();
    this->texture->loadFromFile("textures/green_upward_pipe.png");
}

void Pipe::initSprite() {
    this->sprite.setTexture(*this->texture);
    
    //Adjust the size
    this->sprite.setScale(1.f, 1.f);

    this->sprite.setPosition(direction.x - this->sprite.getGlobalBounds().width / 2.f, 
                             direction.y - this->sprite.getGlobalBounds().height / 2.f);
}

void Pipe::move(const float dirX, const float dirY) {
    this->sprite.move(dirX, dirY);
}

const sf::Vector2f& Pipe::getPosition() {
    return this->sprite.getPosition();
}

void Pipe::setPosition(float PosX, float PosY) {
    this->sprite.setPosition(PosX, PosY);
}

const sf::FloatRect Pipe::getSize() {
    return this->sprite.getGlobalBounds();
}

bool Pipe::OnEdge() {
    return true;
}

void Pipe::update() {
    this->sprite.move(this->movementSpeed * this->direction);
}

void Pipe::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}