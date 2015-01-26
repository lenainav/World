#include "MondeGraph.h"

#include <SDL/SDL.h>
#include <cstdlib>
#include <vector>

#include <iostream>

MondeGraph::MondeGraph()
    : Monde()
{
    //ctor
    srand(NULL);
}

MondeGraph::~MondeGraph()
{
    //dtor
}

void MondeGraph::generate(int sx, int sy, int entite)
{
    Monde::generate(sx, sy, entite);
    //TileSize = Point(sx, sy);

    Tileset = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x * entite, TileSize.y, 8, 255, 0, 0, 0);

    for (int i = 0; i < ListKey.size(); i++) //création des surfaces
        createNewTile(ListKey.at(i));
}


void MondeGraph::draw(SDL_Surface *screen)
{
    SDL_Rect dest = {0};
    SDL_Rect src = {0};

    src.w = dest.w = TileSize.x;
    src.h = dest.h = TileSize.y;

    for(int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {

            dest.x = x * TileSize.x;
            dest.y = y * TileSize.y;

            src.x = World[x][y] * TileSize.x;

            SDL_BlitSurface(Tileset, &src, screen, &dest);

            /*SDL_BlitSurface(&TileColor.at(World[x][y]),
                            &src,
                            Screen,
                            &dest
                            );*/

        }
    }

    SDL_Flip(Screen);
}

void MondeGraph::createNewTile(int key)
{
    std::cout << "\nTry " << key;

    int red = rand()%255, green = rand()%255, blue = rand()%255;
    bool alone = true;
    //SDL_Surface *tile;
    SDL_Rect dest = {0};
    dest.h = TileSize.y; dest.w = TileSize.x;
    dest.x = key * TileSize.x;

    /*do
    {
        red = rand() % 255;
        green = rand()% 255;
        blue = rand() % 255;

        for (int i = 0; i < ListKey.size(); i++)
        {
            if (    TileColor.at(ListKey.at(i)).format->Rmask == red
                &&  TileColor.at(ListKey.at(i)).format->Bmask == blue
                &&  TileColor.at(ListKey.at(i)).format->Gmask == green)
            {
                alone = false;
            }
        }

    }while(!alone); */

    SDL_FillRect(Tileset, &dest, SDL_MapRGB(Tileset->format, red, green, blue));

    std::cout << " Succes\n";
}
