#include "MondeGraph.h"

#include <SDL/SDL.h>
#include <cstdlib>
#include <vector>
#include <ctime>

#include <iostream>

MondeGraph::MondeGraph()
    : Monde()
{
    //ctor
    srand(time(NULL));
}

MondeGraph::~MondeGraph()
{
    //dtor
    SDL_FreeSurface(Tileset);
}

void MondeGraph::generate(int sx, int sy, int entite)
{
    Monde::generate(sx, sy, entite); //generation du monde

    Tileset = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x * entite, TileSize.y, 8, 255, 0, 0, 0); //creation du tileset

    for (int i = 0; i < ListKey.size(); i++) //création des surfaces correspondant a chaque entite
        createNewTile(ListKey.at(i));
}

void MondeGraph::draw(SDL_Surface *screen)
{
    if (screen != NULL) //changement de screen
        Screen = screen;

    if (Screen == NULL) //si pas de sceen pas de dessin possible
        return;

    SDL_Rect dest = {0}; //init des vars
    SDL_Rect src = {0};

    src.w = dest.w = TileSize.x;
    src.h = dest.h = TileSize.y;

    for(int x = 0; x < Size.x; x++) //parcours du monde
    {
        for (int y = 0; y < Size.y; y++)
        {
            dest.x = x * TileSize.x; //def de la destination
            dest.y = y * TileSize.y;

            src.x = World[x][y] * TileSize.x;

            SDL_BlitSurface(Tileset, &src, Screen, &dest); //blit a l'ecran
        }
    }

    //SDL_Flip(Screen); ///!!!Possiblement a enlever, a independament
}

void MondeGraph::drawVision(Point pos, int range, SDL_Surface *screen)
{
    //init pos
    SDL_Rect bcks = {0,0, TileSize.x, TileSize.y};

    //init surfaces /graphiques
    SDL_Surface *back = SDL_CreateRGBSurface(SDL_HWSURFACE, TileSize.x, TileSize.y, 8, 0, 0, 0, 0);

    SDL_FillRect(back, &bcks, SDL_MapRGB(back->format, 0,0,0));

    //dessin de la map
    draw(screen);

    for (int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {
            SDL_Rect dest = {x * TileSize.x, y * TileSize.y, TileSize.x, TileSize.y};

            if (getMinimalDist(pos, Point(x, y)) > range)
            {
                SDL_BlitSurface(back, &bcks, Screen, &dest);
            }

        }
    }

}


void MondeGraph::createNewTile(int key)
{
    int red = rand()%255, green = rand()%255, blue = rand()%255; //init couleurs
    SDL_Rect dest = {0}; //init dest
    dest.h = TileSize.y; dest.w = TileSize.x;
    dest.x = key * TileSize.x;

    SDL_FillRect(Tileset, &dest, SDL_MapRGB(Tileset->format, red, green, blue)); //remplissage
}
