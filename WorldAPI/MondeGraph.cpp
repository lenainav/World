#include "MondeGraph.h"

#include <SDL/SDL.h>
#include <cstdlib>
#include <vector>

MondeGraph::MondeGraph()
    : Monde()
{
    //ctor
}

MondeGraph::~MondeGraph()
{
    //dtor
}

void MondeGraph::generate(int sx, int sy, int entite)
{
    Monde::generate(sx, sy, entite);
    std::vector<int> entitePresent;

    for (int x = 0; x < sx; x++) //parcours du monde
    {
        for (int y = 0; y < sy; y++)
        {
            bool pr = false; //test si la tile a deja été référencer

            for (int i = 0; i < entitePresent.size(); i++)
            {
                if (entitePresent.at(i) == World[x][y])
                {
                    pr = true;
                    break;
                }
            }

            if (pr)
                entitePresent.push_back(World[x][y]);
        }
    }

    for (int i = 0; i < entitePresent.size(); i++) //création des surfaces
        createNewTile(entitePresent.at(i));

}


void MondeGraph::draw()
{
    for(int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {
            SDL_Rect dest = {0, 0, x * TileSize.x, y * TileSize.y};
            SDL_Rect src = {0,0, TileSize.x, TileSize.y};

            SDL_BlitSurface(&TileColor.at(World[x][y]),
                            &src,
                            Screen,
                            &dest
                            );
        }
    }
}

void MondeGraph::createNewTile(int key)
{
    int red, green, blue;
    bool alone = true;
    SDL_Surface *tile;

    do
    {
        red = rand() % 255;
        green = rand()% 255;
        blue = rand() % 255;

        if (TileColor.size() > 500)
            break;

        for (int i = 0; i < TileColor.size(); i++)
        {
            if (    TileColor.at(i).format->Rmask == red
                &&  TileColor.at(i).format->Bmask == blue
                &&  TileColor.at(i).format->Gmask == green)
            {
                alone = false;
            }
        }

    }while(!alone);

    tile = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x, TileSize.y, 32, red, green, blue, 0);

    TileColor.insert(std::pair<int, SDL_Surface>(key, *tile));
}
