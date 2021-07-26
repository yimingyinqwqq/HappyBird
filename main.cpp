#include "game.hpp"
//using namespace sf;

int main() {
    //Init scrand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init Game Engine
    Game game;

    //Game loop
    while (game.running()) 
    {
        //Update
        game.update();

        //Render
        game.render();  
        
    }

    //End of application
    return 0;
}