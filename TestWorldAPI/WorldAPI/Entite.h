#ifndef ENTITE_H
#define ENTITE_H

#include "Point.h"
#include "Monde.h"
#include <lua5.1/lua.h>
#include <string>

class Entite
{
    public:
        Entite();
        virtual ~Entite();

        Monde *World;
        Point WorldSize; //le pointeur du World marche mais pas pour getSize() donc...

        Point Pos;
        int Key;
        bool Alive;

        virtual void draw();

        virtual bool moveLeft();
        virtual bool moveRight();
        virtual bool moveTop();
        virtual bool moveDown();
        virtual bool execChem(std::string *chem, bool all = false);

        virtual bool destroy();
        virtual bool appear();


        virtual void generateKey();

        bool l_initLua();
        bool l_loadScript(std::string script);
        bool l_callFunct(std::string script);

    protected:
        lua_State *Emul;
        bool LuaActive;

    private:

        int l_getLuaElem(lua_State *emul);
        int l_moveLeft(lua_State *emul);
        int l_moveRight(lua_State *emul);
        int l_moveTop(lua_State* emul);
        int l_moveDown(lua_State *emul);



};

#endif // ENTITE_H
