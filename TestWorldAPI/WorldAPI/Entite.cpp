#include "Entite.h"

#include <cstdlib>
#include <ctime>
#include <string>


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
    if (Pos.x < 0 || isBlocked(World->getCaseVal(Pos.x, Pos.y)) || World->isBlocked(World->getCaseVal(Pos)) )
    {
        Pos.x++;
        return false;
    }

    return true;
}

bool Entite::moveRight()
{
    Pos.x++;
    if (Pos.x >= World->getSize().x || isBlocked(World->getCaseVal(Pos))|| World->isBlocked(World->getCaseVal(Pos)))
    {
        Pos.x--;
        return false;
    }

    return true;
}

bool Entite::moveUp()
{
    Pos.y--;
    if (Pos.y < 0 || isBlocked(World->getCaseVal(Pos)) || World->isBlocked(World->getCaseVal(Pos)))
    {
        Pos.y++;
        return false;
    }

    return true;
}

bool Entite::moveDown()
{
    Pos.y++;

    if (Pos.y >= World->getSize().y || isBlocked(World->getCaseVal(Pos)) || World->isBlocked(World->getCaseVal(Pos)))
    {
        Pos.y--;
        return false;
    }

    return true;
}

bool Entite::execChem(std::string *chem, bool all)
{
    bool r = false;

    do
    {

    if (chem->size() == 0)
        return true;

    char c = chem->at(0);
    chem->erase(0, 1);

    r = false;

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

    }while(all);

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

bool Entite::isBlocked(int key)
{
    for (int i = 0; i < BlockedCase.size(); i++)
    {
        if (BlockedCase[i] == key)
            return true;
    }

    return false;
}
