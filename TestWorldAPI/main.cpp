#include <iostream>
#include <SDL/SDL.h>
#include "WorldAPI/MondeGraph.h"

#define NTX 10
#define NTY 10

#define STX 50
#define STY 50

using namespace std;

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        exit(-1);

    SDL_Surface *screen;
    SDL_Event event;
    MondeGraph monde;
    bool ctn = true;

    monde.setTileSize(Point(STX, STY));
    monde.generate(NTX, NTY, 10);

    screen = SDL_SetVideoMode(NTX * STX, NTY * STY, 8, SDL_HWSURFACE);

    monde.Screen = screen;
    monde.draw(screen);
    //SDL_Flip(screen);

    while (ctn)
    {


        SDL_WaitEvent(&event);

        if (event.type == SDL_QUIT)
            ctn = false;

    }

    SDL_FreeSurface(screen);

    SDL_Quit();

    return 0;
}
