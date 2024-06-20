#include "Player.hpp"

void Player::initBody(){
    this->pos = sf::Vector2f(200.f, 200.f);
    this->body.setPosition(this->pos);
    this->body.setFillColor(sf::Color::Red);
    this->body.setSize(sf::Vector2f(PSIDE, PSIDE));
}

void Player::jump(){
    this->gravity = -10;
}
void Player::goLeft(){
    this->pos.x -= 2;
}
void Player::goRight(){
    this->pos.x += 2;
}

void Player::move(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (isOnTheGround())
        {
            this->jump();
        }
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->goRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->goLeft();
    }
    
}

void Player::updatePos(){
    move();
    if (this->frameInAir % 3 == 0)
    {
        this->pos.y += this->gravity;
    }
    this->body.setPosition(pos);
}

bool Player::isOnTheGround(){
    for(Platform pad : this->pads){
        if (this->body.getGlobalBounds().intersects(pad.getSolid().getGlobalBounds()) && this->gravity > 0)
        {
            this->pos.y = pad.getPos().y - PSIDE +1;
            return true;
        }
    }
    if (this->pos.y + this->gravity >= GROUNDLEVEL)
    {
        this->pos.y = GROUNDLEVEL;
        return true;
    }
    return false;
}

void Player::updateGravity(){
    if (!isOnTheGround())
    {
        this->frameInAir++;
        if (this->gravity == 0)
        {
            this->gravity = 1;
        }
        else if (this->frameInAir % 15 == 0)
        {
            this->gravity += this->frameInAir/30 +1;
        } 

    }
    else {
        this->gravity = 0;
        this->frameInAir = 0;
    }
}

Player::Player(std::vector<Platform> pads){
    this->pads = pads;
    initBody();
}

Player::~Player(){

}

void Player::update(){
    updateGravity();
    updatePos();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->body, states);
}