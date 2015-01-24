#ifndef ENTITE_H
#define ENTITE_H

#include "Point.h"
#include "Monde.h"

class Entite
{
    public:
        Entite();
        virtual ~Entite();

        Monde *World;

        Point Pos;
        int Key;
        bool Alive;

        virtual void draw();

        virtual bool moveLeft();
        virtual bool moveRight();
        virtual bool moveTop();
        virtual bool moveBottom();

        virtual bool destroy();
        virtual bool appear();


    protected:
    private:
};

#endif // ENTITE_H
