#include "Application.hpp"


void Application::initWindow(){
    sf::ContextSettings context_settings;
    this->video_mode.width = WIDTH;
    this->video_mode.height = HEIGHT;
    this->window.create(this->video_mode, "Platformer", sf::Style::Resize, context_settings);
    this->window.setFramerateLimit(144);
    this->pads.push_back(Platform(sf::Vector2f(100, 300)));
    this->pads.push_back(Platform(sf::Vector2f(200, 200)));
    this->pads.push_back(Platform(sf::Vector2f(400, 350)));
    this->pads.push_back(Platform(sf::Vector2f(550, 150)));
    this->player = Player(this->pads);
    
}

void Application::handleEvent(){
    while(this->window.pollEvent(this->event)){
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            this->window.close();
        }
        
    }
}

void Application::updatePLayer(){
    this->player.update();
}

Application::Application(){
    initWindow();
}

Application::~Application(){

}

void Application::update(){
    this->handleEvent();
    this->updatePLayer();
    this->player.update();
}

void Application::render(){
    this->window.clear();
    this->window.draw(this->player);
    for(Platform pad : this->pads){
    this->window.draw(pad);
    }
    this->window.display();
}

bool Application::isrunning(){
    return this->window.isOpen();
}

