#pragma once
#include "Point.h"
#include "Color.h"
#include "LineStyle.h"

/**
 * @brief Класс Линия
 */
class Line 
{
private:
    /**
     * @brief начальная точка линии
     */
    Point p1;

    /**
     * @brief конечная точка линии
     */
    Point p2;

    /**
     * @brief цвет линии в формате RGB
     */
    Color color;

    /**
     * @brief стиль линии(тип и толщина)
     */
    LineStyle style;

public:
    /**
     * @brief Конструктор линии с параметрами по умолчанию
     * @param start Начальная точка
     * @param end Конечная точка
     * @param c Цвет линии
     * @param s Стиль линии
     */
    Line(const Point& start, const Point& end, const Color& c = Color(0, 0, 0), const LineStyle& s = LineStyle(LineType::solid, 1));

    /**
     * @brief Метод изменения стиля и цвета
     * @param s Новый стиль
     * @param c Новый цвет
     */
    void setAppearance(const LineStyle& s, const Color& c);

    /**
     * @brief Статический метод для ввода данных о линии из консоли
     */
    static Line read();

    /**
     * @brief Оператор вывода информации о линии
     */
    friend std::ostream& operator<<(std::ostream& os, const Line& l);
};
