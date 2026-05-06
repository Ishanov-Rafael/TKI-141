#include "point.h"

bool Point::operator==(const Point& other) const 
{
    const double eps = 1e-9;
    return (std::abs(x - other.x)< eps && std::abs(y - other.y) < eps);
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
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
