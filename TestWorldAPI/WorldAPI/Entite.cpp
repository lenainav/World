#include "Entite.h"

#include <cstdlib>
#include <ctime>
#include <functional>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>


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


///scripts
/*

bool Entite::l_initLua()
{
    if ((Emul = lua_open()) == NULL)
        return false;

    luaL_openlibs(Emul);

    //lua_register(Emul, "moveLeft", std::bind(this->l_moveLeft, std::placeholders::_1)) ;

}

bool Entite::l_loadScript(std::string script)
{
    if (!luaL_loadfile(Emul, script.c_str()))
        return false;
}

bool Entite::l_callFunct(std::string script)
{

}

int Entite::l_getLuaElem(lua_State *emul)
{

}

int Entite::l_moveLeft(lua_State *emul)
{
    lua_pushboolean(emul, moveLeft());

    return 1;
}

int Entite::l_moveRight(lua_State *emul)
{
    lua_pushboolean(emul, moveRight());
    return 1;
}

int Entite::l_moveUp(lua_State* emul)
{
    lua_pushboolean(emul, moveUp());
    return 1;
}

int Entite::l_moveDown(lua_State *emul)
{
    lua_pushboolean(emul, moveDown());
    return 1;
}
*/
