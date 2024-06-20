#include "Platform.hpp"


void Platform::initPlatform(){
    this->solid.setPosition(this->pos);
    this->solid.setFillColor(sf::Color::Green);
    this->solid.setSize(sf::Vector2f(sf::Vector2f(PLAWIDTH, PLAHEIGHT)));
}

Platform::Platform(sf::Vector2f pos){
    this->pos = pos;
    initPlatform();
}

Platform::~Platform(){
}
void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->solid, states);
}
sf::RectangleShape Platform::getSolid(){
    return this->solid;
}
sf::Vector2f Platform::getPos(){
    return this->pos;
}