#include "Point.h"

Point::Point()
{
    //ctor
    x = y = 0;
}

Point::Point(int vx, int vy) //Point point point...
{
    x = vx;
    y = vy;
}

Point::~Point()
{
    //dtor
}

bool Point::equal(Point &b)
{
    return b.x == x && b.y == y;
}

bool Point::operator==( Point &pb)
{
    return equal(pb);
}

Point Point::operator+(Point &pb)
{
    return Point(x +pb.x, y + pb.y);
}

Point Point::operator-(Point &pb)
{
    return Point(x - pb.x, y - pb.y);
}
