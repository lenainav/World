#ifndef MONDEGRAPH_H
#define MONDEGRAPH_H

#include "Monde.h"
#include <SDL/SDL.h>
#include <map>

class MondeGraph : Monde
{
    public:
        MondeGraph();
        virtual ~MondeGraph();

        virtual void generate(int x, int y, int entite);

        virtual void draw();

        SDL_Surface *Screen;


    protected:
    private:

        Point TileSize;
        std::map<int, SDL_Surface> TileColor;

        void createNewTile(int key);

};

#endif // MONDEGRAPH_H
