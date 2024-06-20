#include "util.hpp"
#include "app/Application.hpp"

int main(){
    Application app;
    while (app.isrunning())
    {
        app.update();
        app.render();
    }
    
    return EXIT_SUCCESS;
}