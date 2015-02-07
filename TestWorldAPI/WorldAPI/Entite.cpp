#include "Entite.h"

#include <cstdlib>
#include <ctime>


Entite::Entite()
{
    //ctor
    srand(time(NULL));
}

Entite::~Entite()
{
    //dtor
}

void Entite::draw()
{}

bool Entite::moveLeft()
{
    Pos.x--;
    if (Pos.x < 0)
    {
        Pos.x = WorldSize.x -1;
        return false;
    }

    return true;
}

bool Entite::moveRight()
{
    Pos.x++;
    if (Pos.x >= WorldSize.x)
    {
        Pos.x = 0;
        return false;
    }

    return true;
}

bool Entite::moveUp()
{
    Pos.y--;
    if (Pos.y < 0)
    {
        Pos.y = WorldSize.y -1;
        return false;
    }

    return true;
}

bool Entite::moveDown()
{
    Pos.y++;

    if (Pos.y >= WorldSize.y)
    {
        Pos.y = 0;
        return false;
    }

    return true;
}

bool Entite::execChem(std::string *chem, bool all)
{

deb:

    if (chem->size() == 0)
        return true;

    char c = chem->at(0);
    bool r = false;

    switch(c)
    {
    case 'l':
        r = moveLeft();
        break;

    case 'r':
        r = moveRight();
        break;

    case 'u':
        r = moveUp();
        break;

    case 'd':
        r = moveDown();
        break;

    default:
        r = false;
        break;
    }

    if (all)
        goto deb;
    else
        return r;
}

bool Entite::destroy()
{
    Alive = false;

    return true;
}

bool Entite::appear()
{
    Alive = true;

    return true;
}

void Entite::generateKey()
{
    Key = rand() % 65536;
}

