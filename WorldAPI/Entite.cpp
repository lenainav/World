#include "Entite.h"

#include <cstdio>

Entite::Entite()
{
    //ctor
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

bool Entite::moveTop()
{
    Pos.y--;
    if (Pos.y < 0)
    {
        Pos.y = WorldSize.y -1;
        return false;
    }

    return true;
}

bool Entite::moveBottom()
{
    Pos.y++;

    if (Pos.y >= WorldSize.y)
    {
        Pos.y = 0;
        return false;
    }

    return true;
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
