#include "../util.hpp"
#include "../gameElement/Player.hpp"
#define WIDTH 700
#define HEIGHT 500

class Application{
    private:
        sf::RenderWindow window;
        sf::Event event;
        sf::VideoMode video_mode;
        std::vector<Platform> pads;
        Player player;
        void initWindow();
        void handleEvent();
        void updatePLayer();

    public:
        Application();
        ~Application();
        void update();
        void render();
        bool isrunning();
};