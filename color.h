#pragma once
#include <iostream>
#include <cstdint>

/**
 * @brief Класс Цвет в формате RGB
 */
class Color 
{
private:
    uint8_t red;   
    uint8_t green; 
    uint8_t blue;  

public:
    /**
     * @brief Конструктор с проверкой диапазона
     * @param r красный
     * @param g зеленый
     * @param b синий
     */
    Color(const int r = 0, const int g = 0, const int b = 0);

    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    friend std::istream& operator>>(std::istream& is, Color& c);
};
