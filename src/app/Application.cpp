#include "Application.hpp"


void Application::initWindow(){
    sf::ContextSettings context_settings;
    this->video_mode.width = WIDTH;
    this->video_mode.height = HEIGHT;
    this->window.create(this->video_mode, "Platformer", sf::Style::Resize, context_settings);
    this->window.setFramerateLimit(144);
    // sf::Vector2f v1 = sf::Vector2f(200.f, 200.f);
    // sf::Vector2f v2 = sf::Vector2f(100.f, 300.f);
    // sf::Vector2f v3 = sf::Vector2f(400.f, 350.f);
    // sf::Vector2f v4 = sf::Vector2f(550.f, 150.f);
    Platform* pad1 = new Platform(sf::Vector2f(200.f, 200.f));
    Platform* pad2 = new Platform(sf::Vector2f(100.f, 300.f));
    Platform* pad3 = new Platform(sf::Vector2f(400.f, 350.f));
    Platform* pad4 = new Platform(sf::Vector2f(550.f, 150.f));
    Platform* pad5 = new Platform(sf::Vector2f(100.f, 100.f));
    this->pads.push_back(pad1);
    this->pads.push_back(pad2);
    this->pads.push_back(pad3);
    this->pads.push_back(pad4);
    this->pads.push_back(pad5);
    // this->pads.push_back(&pad2);
    for(Platform* pad : this->pads){
        std::cout<<pad<<std::endl;
        std::cout<<this->pads.size()<<std::endl;
        this->window.draw(*pad);
    }
    // this->pads.push_back(&Platform(v2));
    // this->pads.push_back(&Platform(v3));
    // this->pads.push_back(&Platform(v4));
    this->player = Player(this->pads);
    std::cout<<this->pads[0]<<std::endl;
    std::cout<<this->pads[0]->getPos().x<<std::endl;
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

void Application::updatePads(){
    for(Platform* pad : this->pads){
        pad->update();
    }
}

Application::Application(){
    initWindow();
}

Application::~Application(){
    for (Platform* pad : this->pads) {
        delete pad;
    }
    this->pads.clear();
}

void Application::update(){
    this->handleEvent();
    this->updatePLayer();
    this->updatePads();
}

void Application::render(){

    this->window.clear();
    // this->pads[0]->goLeft();     
    this->window.draw(this->player);
    for (Platform* pad : this->pads)
    {
        this->window.draw(*pad);
    }
    
    this->window.draw(*this->pads[0]);
    
    this->window.display();
}

bool Application::isrunning(){
    return this->window.isOpen();
}

