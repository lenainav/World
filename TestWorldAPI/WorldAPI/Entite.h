#ifndef ENTITE_H
#define ENTITE_H

#include "Point.h"
#include "Monde.h"
#include <string>
#include <vector>

class Entite
{
    public:
        Entite();
        virtual ~Entite();

        Monde *World;

        Point Pos;
        int Key;
        bool Alive;
        int VisionRange;

        virtual void draw();

        virtual bool moveLeft();
        virtual bool moveRight();
        virtual bool moveUp();
        virtual bool moveDown();
        virtual bool execChem(std::string *chem, bool all = false);

        virtual bool destroy();
        virtual bool appear();


        virtual void generateKey();


        void setWorld(Monde *monde)     {World = monde;}

        bool isBlocked(int key);
        void addBlocked(int key)        {BlockedCase.push_back(key);}
        std::vector<int> getBlocked()   {return BlockedCase;}



    protected:
        std::vector<int> BlockedCase;
    private:


};

#endif // ENTITE_H
