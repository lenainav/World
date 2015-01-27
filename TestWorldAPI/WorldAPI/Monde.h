#ifndef MONDE_H
#define MONDE_H

#include "Point.h"
#include <vector>

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
        int     getCaseVal(Point pt)            {return getCaseVal(pt.x, pt.y);}
        int     getCaseVal(int x, int y)        {return World[x][y];}

        //setters
        void    setCase(Point pt, int val)      {setCase(pt.x, pt.y, val);}
        void    setCase(int x, int y, int val)  {World[x][y] = val;}

        virtual void draw();

    protected:

        int **World;
        std::vector<int> ListKey;
        int EntitePossible;

        Point Size;

    private:
        void listKey();




};

#endif // MONDE_H
