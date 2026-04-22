#include <iostream>
#include <cmath>
#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(Point a, Point b, Point c, Point d)
{
    this->p1 = a;
    this->p2 = b;
    this->p3 = c;
    this->p4 = d;

    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
    {
        std::cout << "Ошибка: Точки совпадают!" << std::endl;
        exit(1);
    }

    if (this->getVolume() == 0)
    {
        std::cout << "Ошибка: Тетраэдр не существует (точки в одной плоскости)." << std::endl;
        exit(1);
    }
}


double Tetrahedron::getVolume() const
{
    double v1x = p2.getX() - p1.getX();
    double v1y = p2.getY() - p1.getY();
    double v1z = p2.getZ() - p1.getZ();

    double v2x = p3.getX() - p1.getX();
    double v2y = p3.getY() - p1.getY();
    double v2z = p3.getZ() - p1.getZ();

    double v3x = p4.getX() - p1.getX();
    double v3y = p4.getY() - p1.getY();
    double v3z = p4.getZ() - p1.getZ();

    double det = v1x * (v2y * v3z - v2z * v3y) - v1y * (v2x * v3z - v2z * v3x) + v1z * (v2x * v3y - v2y * v3x);

    return std::fabs(det) / 6.0;
}
