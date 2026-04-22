#pragma once
#include <iostream>

/**
 * @brief Структура Точка для представления координат на плоскости
 */
struct Point 
{
    double x;
    double y;

    /**
     * @brief Перегрузка оператора равенства (требование задания)
     */
    bool operator==(const Point& other) const 
    {
        return (x == other.x && y == other.y);
    }

    /**
     * @brief Оператор вывода точки в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p) 
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    /**
     * @brief Оператор ввода точки из потока
     */
    friend std::istream& operator>>(std::istream& is, Point& p) 
    {
        is >> p.x >> p.y;
        return is;
    }
};
