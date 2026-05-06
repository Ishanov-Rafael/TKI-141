#include "Point.h"
#include <cmath>  
#include <limits>

Point::Point(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getZ() const
{
    return this->z;
}

bool Point::operator==(const Point &p) const
{
    const double eps = std::numeric_limits<double>::epsilon();
    return (std::abs(x - p.x) < eps && std::abs(y - p.y) < eps && std::abs(z - p.z) < eps);
}

bool Point::operator!=(const Point &p) const
{
    return !(*this == p);
}
