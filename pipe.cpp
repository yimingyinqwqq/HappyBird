#include "pipe.hpp"

Pipe::Pipe() {}

Pipe::Pipe(float dirX, float dirY, float movement_speed) :
    direction(sf::Vector2f(dirX, dirY)) , movementSpeed(movement_speed), UpOrDownward(false)
{
    this->initTexture();
    this->initSprite();
}

Pipe::Pipe(const Pipe& pipe) {
    this->direction = pipe.direction;
    this->movementSpeed = pipe.movementSpeed;
    this->positionOfFirstPipe = pipe.positionOfFirstPipe;
    this->heightOfFirstPipe = pipe.heightOfFirstPipe;
    this->UpOrDownward = true;

    this->initTexture();
    this->initSprite();
}

Pipe::~Pipe() {
    delete this->texture;
}

void Pipe::initTexture() {
    this->texture = new sf::Texture();

    //Pick the right texture
    if (UpOrDownward) {
        //Upward
        this->texture->loadFromFile("textures/green_upward_pipe.png");
    } else {
        //Downward
        this->texture->loadFromFile("textures/green_downward_pipe.png");
    }
}

void Pipe::initSprite() {
    this->sprite.setTexture(*this->texture);
    
    //Adjust the size
    this->sprite.setScale(3.f, 3.f);

    if (!UpOrDownward) {
        //TODO: later it should be set as random numbers with different probabilities
        //Set the pipe downward
        this->sprite.setPosition(1200.f, -1 * static_cast<float>(std::rand() % 700));
        positionOfFirstPipe = this->sprite.getPosition().y;
        heightOfFirstPipe = this->sprite.getGlobalBounds().height;
    } else {
        //Set the pipe upward
        this->sprite.setPosition(1200.f, 
            positionOfFirstPipe + heightOfFirstPipe + disBetTwoPipes
        );
        //this->sprite.setPosition(1200.f, 
        //    1500.f - this->sprite.getGlobalBounds().height + static_cast<float>(std::rand() % 800));
    }
}

const sf::Vector2f& Pipe::getPosition() const {
    return this->sprite.getPosition();
}

/*
void Pipe::setPosition(float PosX, float PosY) {
    this->sprite.setPosition(PosX, PosY);
}
*/

const sf::FloatRect Pipe::getGlobalBounds() const {
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