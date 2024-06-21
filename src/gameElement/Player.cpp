#include "Player.hpp"

void Player::initBody(){
    this->pos = sf::Vector2f(200.f, 200.f);
    this->body.setPosition(this->pos);
    this->body.setFillColor(sf::Color::Red);
    this->body.setSize(sf::Vector2f(PSIDE, PSIDE));
}

void Player::jump(){
    this->gravity = -7;
}
void Player::goLeft(){
    this->pos.x -= 4;
}
void Player::goRight(){
    this->pos.x += 4;
}
void Player::padsLeft(){
    for(Platform* pad : this->pads){
        pad->goLeft();
    }
}

void Player::padsRight(){
    for(Platform* pad : this->pads){
        pad->goRight();
    }
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
        if(this->pos.x < 600 )
        this->goRight();
        else{
            this->padsLeft();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         if(this->pos.x > 50 )
        this->goLeft();
        else{
            this->padsRight();
        }
    }
    
}

void Player::updatePos(){
    move();
    this->body.setPosition(pos);
    this->pos.y += this->gravity;
}

bool Player::isOnTheGround(){
    for(Platform* pad : this->pads){
        if (this->body.getGlobalBounds().intersects(pad->getSolid().getGlobalBounds()) && this->gravity > 0)
        {
            this->pos.y = pad->getPos().y - PSIDE +1;
            return true;
        }
        else{
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
            this->gravity += this->frameInAir/30 + 2;
        } 

    }
    else {
        this->gravity = 0;
        this->frameInAir = 0;
    }
}

Player::Player(std::vector<Platform*> pads){
    this->pads = pads;
    // std::cout <<  &((*this->pads)[0]) <<std::endl;
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