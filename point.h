#pragma once

/**
 * @brief класс точка
 */
class Point 
{
private:
    /**
     * @brief координаты x, y, z
     */
    double x, y, z;

public:
    /**
     * @brief Конструктор точки
     */
    Point(double x = 0, double y = 0, double z = 0);
    /**
     * @brief получение координаты x
     */
    double getX() const;
    /**
     * @brief получение координаты y
     */
    double getY() const;
    /**
     * @brief получение координаты z
     */
    double getZ() const;

    /**
     * @brief проверка на равенство оператора
     */
    bool operator==(const Point& p) const;

    /**
     * @brief проверка на неравенство оператора
     */
    bool operator!=(const Point& p) const;
};
