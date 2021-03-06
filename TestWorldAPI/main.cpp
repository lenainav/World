#include <iostream>
#include <SDL/SDL.h>
#include "WorldAPI/MondeGraph.h"
#include "WorldAPI/EntiteGraph.h"

#define NTX 20
#define NTY 20

#define STX 30
#define STY 30

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
    monde.addBlocked(2);


    entite.setWorld(monde);
    entite.addBlocked(1);

    entite.VisionRange = 4;
    entite.create();

    std::string path = "rrrddd";

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

            case SDLK_z:
                entite.VisionRange = rand() % 5 + 2;
                cout << "\n" << entite.VisionRange << "\n";
            break;

            case SDLK_e:
                entite.execChem(&path, true);
                break;

            case SDLK_a:
                std::vector<std::vector<int>> vis = monde.getVision(entite.Pos, 2);
                cout << "\n";

                for (int y = 0; y < vis[0].size(); y++)
                {
                    for (int x = 0; x < vis.size(); x++)
                        cout << vis[x][y] << " ";
                    cout << "\n";
                }
                break;




            }

            break;



        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        //monde.draw(screen);
        monde.drawVision(entite.Pos, entite.VisionRange, screen);

        entite.draw(screen);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);

    SDL_Quit();

    return 0;
}
