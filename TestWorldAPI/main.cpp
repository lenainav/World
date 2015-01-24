#include <iostream>
#include <SDL/SDL.h>
#include <MondeGraph.h>

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

    monde.generate(NTX, NTY, 10);

    screen = SDL_SetVideoMode(NTX * STX, NTY * STY, 32, SDL_HWSURFACE);

    monde.Screen = screen;
    monde.draw();



    return 0;
}
