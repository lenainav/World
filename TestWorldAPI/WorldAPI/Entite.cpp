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
        Pos.x = 0;
        return false;
    }

    return true;
}

bool Entite::moveRight()
{
    Pos.x++;
    if (Pos.x > World->getSize().x)
    {
        Pos.x = World->getSize().x;
        //printf("x:%d\n", Pos.x);
        return false;
    }

    return true;
}

bool Entite::moveTop()
{
    Pos.y--;
    if (Pos.y < 0)
    {
        Pos.y = 0;
        return false;
    }

    return true;
}

bool Entite::moveBottom()
{
    Pos.y++;
    printf("\ny:%d sy:%d", Pos.y, World->getSize().y);

    if (Pos.y > World->getSize().y)
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
