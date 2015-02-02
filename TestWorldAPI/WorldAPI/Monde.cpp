#include "Monde.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

Monde::Monde()
{
    //ctor
    srand(time(NULL));
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

    World =(int**) malloc(x * sizeof(int*)); //malloc des x
    if (World == NULL)
        exit(-1);

    for(int i = 0; i < x; i++) //pour chaque x, malloc des y
    {
        World[i] = (int*) malloc(y * sizeof(int));

        if (World[i] == NULL)
            exit(-1);
    }

}

void Monde::generate(int sx, int sy, int entite)
{
    create(sx, sy);
    EntitePossible = entite;

    for (int x = 0; x < Size.x; x++) //generation aleatiore
    {
        for (int y = 0; y < Size.y; y++)
        {

            World[x][y] = rand() % entite;
        }
    }

    listKey(); //def de toutes les elemes générer
    Monde::draw();
}

Monde::~Monde()
{
    //dtor
}

void Monde::draw()
{
    for (int y = 0; y < Size.y; y++) //dessin console
    {
        for (int x = 0; x < Size.x; x++)
        {
            std::cout << World[x][y] << " ";
        }
        std::cout << "\n";
    }
}

void Monde::listKey()
{
    for (int x = 0; x < Size.x; x++) //parcours du monde
    {
        for (int y = 0; y < Size.y; y++)
        {
            bool find = false; //test si déja lister

            for (int i = 0; i < ListKey.size(); i++)
            {
                if (World[x][y] == ListKey.at(i))
                {
                    find = true;
                    break;
                }
            }

            if (!find) //sinon ajout
                ListKey.push_back(World[x][y]);
        }
    }
}

std::map<int, int>  Monde::getRepartition()
{
    std::map<int, int> rep;


    for (int k = 0; k < ListKey.size(); k++)
    {
        int n = 0;

        for (int x = 0; x < Size.x; x++)
        {
            for (int y = 0; y < Size.y; y++)
            {
                if (World[x][y] == ListKey.at(k))
                    n++;
            }
        }


        rep.insert(std::pair<int, int>(ListKey.at(k), n));
    }

    return rep;
}

std::vector<std::vector<int>> Monde::getVision(Point pos, int range)
{
    std::vector<std::vector<int>> vision;
    for (int x = 0; x = (2*range) + 1; x++)
    {
        for (int y = 0; y < (2*range) +1; y++)
        {
            Point pt(x + range -1, y = range - 1);

            if (getMinimalDist(pos, pt) == 0 || getMinimalDist(pos, pt) > range)
                vision[x][y] = -1;
            else
                vision[x][y] = World[pt.x][pt.y];
        }
    }

    return vision;
}

int Monde::getMinimalDist(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

