#include "EntiteGraph.h"

#include <cstdlib>
#include <ctime>

#define CLRAND (rand() % 245) + 10

EntiteGraph::EntiteGraph()
{
    //ctor
    Entite();

    srand(time(NULL));
}

EntiteGraph::~EntiteGraph()
{
    //dtor
    SDL_FreeSurface(Graph);
}

void EntiteGraph::setWorld(MondeGraph &monde)
{
    WorldG = &monde;
    Entite::World = (Monde*) &monde;
}


void EntiteGraph::create()
{
    Point pt = WorldG->getTileSize();
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
    Point pt = WorldG->getTileSize();

    RealPos.x = Pos.x * pt.x + (pt.x * 0.1);
    RealPos.y = Pos.y * pt.y + (pt.y * 0.1);
    RealPos.w = pt.x;
    RealPos.h = pt.y;

    return RealPos;
}

