#include "Monde.h"

#include <cstdlib>
#include <iostream>

Monde::Monde()
{
    //ctor
    srand(NULL);
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

    listKey();
    Monde::draw();
}

Monde::~Monde()
{
    //dtor
}

void Monde::draw()
{
    for (int y = 0; y < Size.y; y++)
    {
        for (int x = 0; x < Size.x; x++)
        {
            std::cout << World[x][y] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "LK:";
    for (int i = 0; i < ListKey.size(); i++)
        std::cout << ListKey.at(i) << " ";

}

void Monde::listKey()
{
    for (int x = 0; x < Size.x; x++)
    {
        for (int y = 0; y < Size.y; y++)
        {
            bool find = false;

            for (int i = 0; i < ListKey.size(); i++)
            {
                if (World[x][y] == ListKey.at(i))
                {
                    find = true;
                    break;
                }
            }

            if (!find)
                ListKey.push_back(World[x][y]);
        }
    }
}
