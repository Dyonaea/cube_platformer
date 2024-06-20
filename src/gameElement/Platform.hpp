#include "../util.hpp"

#define PLAWIDTH 100
#define PLAHEIGHT 15

class Platform : public sf::Drawable{
    private:    
        sf::Vector2f pos;
        sf::RectangleShape solid;
        void initPlatform();

    public:
        Platform(sf::Vector2f pos);
        ~Platform();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::RectangleShape getSolid();
        sf::Vector2f getPos();
};