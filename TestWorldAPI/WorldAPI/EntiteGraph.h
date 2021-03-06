#ifndef ENTITEGRAPH_H
#define ENTITEGRAPH_H

#include "Entite.h"
#include "MondeGraph.h"
#include <SDL/SDL.h>

class EntiteGraph : public Entite
{
    public:
        EntiteGraph();
        virtual ~EntiteGraph();

        SDL_Surface *Screen;
        MondeGraph *WorldG;

        virtual void create();
        virtual void draw(SDL_Surface *screen);

        SDL_Rect setrp(); //def la RealPos
        void setWorld(MondeGraph &monde);


    protected:
        SDL_Surface *Graph;
        SDL_Rect RealPos;


    private:

};

#endif // ENTITEGRAPH_H
