#pragma once
#include <iostream>
#include <cstdint>

/**
 * @brief Класс Цвет в формате RGB
 */
class Color 
{
private:
    /** 
     * @brief Интенсивность красного канала.
     * Допустимый диапазон значений: [0, 255].
     */
    uint8_t red;

    /** 
     * @brief Интенсивность зеленого канала.
     * Допустимый диапазон значений: [0, 255].
     */
    uint8_t green;

    /** 
     * @brief Интенсивность синего канала.
     * Допустимый диапазон значений: [0, 255].
     */
    uint8_t blue;  

public:
    /**
     * @brief Конструктор с проверкой диапазона
     * @param r красный
     * @param g зеленый
     * @param b синий
     */
    Color(const int r = 0, const int g = 0, const int b = 0);

    /**
     * @brief Оператор для вывода цвета 
     */
    friend std::ostream& operator<<(std::ostream& os, const Color& c);

    /**
     * @brief Оператор для чтения цвета из консоли
     */
    friend std::istream& operator>>(std::istream& is, Color& c);
};
