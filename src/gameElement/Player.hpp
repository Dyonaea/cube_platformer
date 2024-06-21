#include "../util.hpp"
#include "Platform.hpp"

#define PSIDE 30
#define GROUNDLEVEL 400

enum dir{UP, DOWN, LEFT, RIGHT
};


class Player : public sf::Drawable{
    private:
        sf::Vector2f pos;
        sf::RectangleShape body;
        std::vector<Platform*> pads;
        int gravity = 0;
        int frameInAir = 0;
        void initBody();
        void move();
        void jump();
        void goLeft();
        void goRight();
        void padsLeft();
        void padsRight();
        void updateGravity();
        void updatePos();
        bool isOnTheGround();
    public:
        Player(std::vector<Platform*> pads = {});
        ~Player();
        void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};