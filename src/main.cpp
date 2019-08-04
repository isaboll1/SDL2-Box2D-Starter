#include "game.h"

//Event Filter (for mobile devices)
int Filter(void* userdata, SDL_Event* event){
    Game * game = static_cast<Game*>(userdata);
    switch (event->type) {
        case SDL_APP_WILLENTERBACKGROUND:
            game->running = false;
            return 0;

        case SDL_APP_WILLENTERFOREGROUND:
            game->running = true;
            return 0;

        default:
            return 1;
    }
}

int main(int argc, char** argv){
    Game * PhysicsTest;
    PhysicsTest = new Game();

    if (!PhysicsTest->Start(argc, argv)){
        return -1;
    }   
    else {
        SDL_SetEventFilter(Filter, (void*)PhysicsTest);
        PhysicsTest->Loop();
    }
    return 0;   
}