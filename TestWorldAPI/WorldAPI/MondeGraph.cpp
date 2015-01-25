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

    for (int i = 0; i < ListKey.size(); i++) //création des surfaces
        createNewTile(ListKey.at(i));

    Tileset = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x * entite, TileSize.y, 8, 255, 0, 0, 0);
}


void MondeGraph::draw(SDL_Surface *screen)
{
    SDL_Rect dest = {0};
    SDL_Rect src = {0};

    src.w = TileSize.x;
    src.h = TileSize.y;

    for(int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {

            dest.x = x * TileSize.x;
            dest.y = y * TileSize.y;

            src.x = /*World[x][y] **/ TileSize.x;

            //SDL_BlitSurface(Tileset, &src, screen, &dest);

            SDL_BlitSurface(&TileColor.at(World[x][y]),
                            &src,
                            Screen,
                            &dest
                            );

        }
    }

    SDL_Flip(Screen);
}

void MondeGraph::createNewTile(int key)
{
    std::cout << "\nTry " << key;

    int red = 150, green = 20, blue = 200;
    bool alone = true;
    SDL_Surface *tile;
    SDL_Rect dest = {0};
    dest.h = TileSize.y; dest.w = TileSize.x;

    TileColor.insert(std::pair<int, SDL_Surface>(key, (SDL_Surface) {0}));

    /*do
    {*
        red = rand() % 255;
        green = rand()% 255;
        blue = rand() % 255;/*

        for (int i = 0; i < ListKey.size(); i++)
        {
            if (    TileColor.at(ListKey.at(i)).format->Rmask == red
                &&  TileColor.at(ListKey.at(i)).format->Bmask == blue
                &&  TileColor.at(ListKey.at(i)).format->Gmask == green)
            {
                alone = false;
            }
        }

    }while(!alone);*/

    tile = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x, TileSize.y, 8, red, green, blue, 0);
    SDL_FillRect(tile, &dest, SDL_MapRGB(tile->format, red, green, blue));

    TileColor.at(key) = *tile;

    std::cout << " Succes\n";
}
