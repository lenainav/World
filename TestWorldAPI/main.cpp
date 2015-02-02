#include <iostream>
#include <SDL/SDL.h>
#include "WorldAPI/MondeGraph.h"
#include "WorldAPI/EntiteGraph.h"

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
    EntiteGraph entite;
    bool ctn = true;

    monde.setTileSize(Point(STX, STY));
    monde.generate(NTX, NTY, 10);

    //entite.World = &monde;
    entite.World = &monde;
    entite.WorldSize = monde.getSize();
    entite.create();

    cout << "\nx:" << entite.World->getSize().x << " y:" << entite.World->getSize().y;


    screen = SDL_SetVideoMode(NTX * STX, NTY * STY, 8, SDL_HWSURFACE);


    while (ctn)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            ctn = false;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
                entite.moveUp();
                break;
            case SDLK_DOWN:
                entite.moveDown();
                break;
            case SDLK_LEFT:
                entite.moveLeft();
                break;
            case SDLK_RIGHT:
                entite.moveRight();
                break;
            default:
                break;
            }

        }

        SDL_FillRect(screen, NULL, 0x000000);
        monde.draw(screen);
        entite.draw(screen);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);

    SDL_Quit();

    return 0;
}
