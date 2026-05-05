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
    Point p1, p2;
    Color color;
    LineStyle style;

public:
    /**
     * @brief Конструктор линии с параметрами по умолчанию
     */
    Line(const Point& start, const Point& end, const Color& c = Color(0, 0, 0), const LineStyle& s = LineStyle(LineType::solid, 1));

    /**
     * @brief Метод изменения стиля и цвета
     */
    void setAppearance(const LineStyle& s, const Color& c);

    /**
     * @brief Статический метод для чтения данных линии из консоли
     */
    static Line read();

    /**
     * @brief Оператор вывода информации о линии
     */
    friend std::ostream& operator<<(std::ostream& os, const Line& l);
};
