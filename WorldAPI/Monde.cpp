#include "Monde.h"

#include <cstdlib>

Monde::Monde()
{
    //ctor
}

Monde::Monde(int x, int y)
{
    create(x, y);
}

Monde::Monde(Point size)
{
    create(size.x, size.y);
}

void Monde::create(int x, int y)
{
    Size = Point(x, y);

    World =(int**) malloc(x * sizeof(int*));
    if (World == NULL)
        exit(-1);

    for(int i = 0; i < x; i++)
    {
        World[i] = (int*) malloc(y * sizeof(int));

        if (World[i] == NULL)
            exit(-1);
    }

}

void Monde::generate(int sx, int sy, int entite)
{
    int tile;
    create(sx, sy);

    for (int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {
            tile = rand() % entite;

            World[x][y] = tile;
        }
    }
}

Monde::~Monde()
{
    //dtor
}

void Monde::draw()
{
}
