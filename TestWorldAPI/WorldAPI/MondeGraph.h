#ifndef MONDEGRAPH_H
#define MONDEGRAPH_H

#include "Monde.h"
#include <SDL/SDL.h>
#include <map>

class MondeGraph : public Monde
{
    public:
        MondeGraph();
        virtual ~MondeGraph();

        virtual void generate(int x, int y, int entite);

        virtual void draw(SDL_Surface *screen = NULL);

        virtual void setTileSize(Point sz) {TileSize = sz;}
        virtual Point getTileSize() {return TileSize;}


        SDL_Surface *Screen;


    protected:
    private:

        Point TileSize;
        SDL_Surface *Tileset;

        void createNewTile(int key); //crée graphiquement une tile dans le Tileset, 0 < key < EntitePossible

};

#endif // MONDEGRAPH_H
