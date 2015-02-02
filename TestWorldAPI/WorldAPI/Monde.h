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
        int     getCaseVal(Point pt)            {return getCaseVal(pt.x, pt.y);}
        int     getCaseVal(int x, int y)        {return World[x][y];}
        int     getEntiePossible()              {return EntitePossible;}

            //Info complementaire monde
        std::vector<std::string>    getTypes()          {return Types;}
        std::map<int, int>          getRepartition();

            //vision
        std::vector<std::vector<int>> getVision(Point pos, int range);
        int     getMinimalDist(Point a, Point b);


        //setters
        void    setCase(Point pt, int val)          {setCase(pt.x, pt.y, val);}
        void    setCase(int x, int y, int val)      {World[x][y] = val;}
            //info comp
        void    addType(std::string s)              {Types.push_back(s);}
        void    corresElem(std::string elem, int k) {TypesCorres.at(elem).push_back(k);}

        virtual void draw();

    protected:

        int **World;
        std::vector<int> ListKey;
        int EntitePossible;

        std::vector<std::string> Types;
        std::map<std::string, std::vector<int> > TypesCorres;

        Point Size;

    private:
        void listKey();
};

#endif // MONDE_H
