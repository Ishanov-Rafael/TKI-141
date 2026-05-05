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
     * @brief Оператор сравнения двух точек
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор ввода точки в поток
     */
    friend std::ostream& operator<<(std::ostream& is, const Point& p);

    /**
     * @brief оператор ввода точки из потока
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};
