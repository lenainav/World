#ifndef POINT_H
#define POINT_H


class Point //Un Point.
{
    public:
        Point();
        Point(int, int);
        virtual ~Point();

        bool equal(Point &b);
        bool operator==(Point &pb);
        Point operator+(Point &pb);
        Point operator-(Point &pb);

        int x;
        int y;

    protected:
    private:
};

#endif // POINT_H
