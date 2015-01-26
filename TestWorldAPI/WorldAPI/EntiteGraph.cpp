
#include "EntiteGraph.h"

#include <iostream>

#define CLRAND rand() % 255

EntiteGraph::EntiteGraph()
{
    //ctor
    Entite();

    srand(NULL);
}

EntiteGraph::~EntiteGraph()
{
    //dtor
}

void EntiteGraph::create()
{
    Point pt = World->getTileSize();
    SDL_Rect dst = {0};

    Graph = SDL_CreateRGBSurface(SDL_HWSURFACE, pt.x - (pt.x * 0.2), pt.y - (pt.y * 0.2), 8, 0,255,0,0);
    dst.w = Graph->w;
    dst.h = Graph->h;

    SDL_FillRect(Graph, &dst, SDL_MapRGB(Graph->format,CLRAND, CLRAND, CLRAND));

}

void EntiteGraph::draw(SDL_Surface *screen)
{
    setrp();
    Screen = screen;
    SDL_Rect src = {0, 0, Graph->w, Graph->h};

    SDL_BlitSurface(Graph, &src, Screen, &RealPos);
}

SDL_Rect EntiteGraph::setrp()
{
    Point pt = World->getTileSize();

    RealPos.x = Pos.x * pt.x + (pt.x * 0.1);
    RealPos.y = Pos.y * pt.y + (pt.y * 0.1);
    RealPos.w = pt.x;
    RealPos.h = pt.y;

    return RealPos;
}
