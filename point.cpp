#include "point.h"

bool Point::operator==(const Point& other) const 
{
    return (x == other.x && y == other.y);
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) 
{
    is >> p.x >> p.y;
    return is;
}
