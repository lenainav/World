#ifndef MONDE_H
#define MONDE_H

#include "Point.h"
#include <vector>
#include <map>
#include <string>

class Monde
{
    public:
        Monde();
        Monde(int x, int y);
        Monde(Point size);

        void create(int x, int y);
        void generate(int x, int y, int entite);

        virtual ~Monde();

        //getters
        Point   getSize()                       {return Size;}
        int**   getWorld()                      {return World;}
        int     getCaseVal(Point pt)            {return World[pt.x][pt.y];}
        int     getCaseVal(int x, int y)        {return World[x][y];}
        int     getEntiePossible()              {return EntitePossible;}

            //Info complementaire monde
        std::map<int, int>  getRepartition();
        std::vector<int>    getBlocked()        {return BlockedCase;}
        bool                isBlocked(int key);

            //vision
        std::vector<std::vector<int>>   getVision(Point pos, int range);
        int                             getMinimalDist(Point a, Point b);


        //setters
        void    setCase(Point pt, int val)          {setCase(pt.x, pt.y, val);}
        void    setCase(int x, int y, int val)      {World[x][y] = val;}
            //info comp
        void    addBlocked(int key)                 {BlockedCase.push_back(key);}


        virtual void draw();

    protected:

        int **World;
        std::vector<int> ListKey;
        int EntitePossible;

        std::vector<int> BlockedCase;

        Point Size;

    private:
        void listKey();
};

#endif // MONDE_H
