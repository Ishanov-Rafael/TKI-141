#pragma once
#include <iostream>

/**
 * @brief Структура Точка для представления координат на плоскости
 */
struct Point 
{
    /** 
     * @brief Координата точки по оси абсцисс (X).
     */
    double x;

    /** 
     * @brief Координата точки по оси ординат (Y).
     */
    double y;

   /**
     * @brief Оператор сравнения двух точек на равенство
     * @param other Другая точка для сравнения
     * @return true, если точки совпадают с учетом погрешности
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения двух точек на неравенство
     * @param other Другая точка для сравнения
     * @return true, если точки не совпадают
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор для вывода точки в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Оператор для чтения точки из потока
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};
