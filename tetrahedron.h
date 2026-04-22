#pragma once
#include "point.h"

/**
 * @brief Класс Тетраэдр
 */
class Tetrahedron 
{
private:
    /**
     * @brief Первая, вторая, третья и четвертая вершины
     */
    Point p1, p2, p3, p4;

public:
    /** 
     * @brief Конструктор по 4-м точкам
     * @param a первая точка
     * @param b вторая точка 
     * @param c третья точка 
     * @param d четвертая точка 
     */
    Tetrahedron(Point a, Point b, Point c, Point d);

    /** 
     * @brief Расчет объема тетраэдра   
     */
    double getVolume() const;
};
