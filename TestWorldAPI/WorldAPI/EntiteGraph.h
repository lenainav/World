#ifndef ENTITEGRAPH_H
#define ENTITEGRAPH_H

#include "Entite.h"
#include <SDL/SDL.h>

class EntiteGraph : Entite
{
    public:
        EntiteGraph();
        virtual ~EntiteGraph();

        SDL_Surface *Screen;


        virtual void create();
        virtual void draw(SDL_Surface *screen);




    protected:
        SDL_Surface *Graph;
        SDL_Rect RealPos;

        void setrp();

    private:
};

#endif // ENTITEGRAPH_H
