#ifndef ENTITE_H
#define ENTITE_H

#include "Point.h"
#include "Monde.h"
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
        virtual bool moveUp();
        virtual bool moveDown();
        virtual bool execChem(std::string *chem, bool all = false);

        virtual bool destroy();
        virtual bool appear();


        virtual void generateKey();


    protected:

    private:


};

#endif // ENTITE_H
