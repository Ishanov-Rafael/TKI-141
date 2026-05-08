#pragma once

/**
 * @brief solid - сплошная линяя
 * @brief dash - пунктирная линия
 * @brief dot - точки
 * @brief dash_dot - точка-тире
 * @brief dashdotdot - две точки тире
 */
enum class LineType 
{
    solid,       
    dash,        
    dot,        
    dash_dot,   
    dashdotdot  
};

/**
 * @brief Класс Стиль линии (тип и толщина)
 */
class LineStyle 
{
public:
    /** 
     * @brief Тип линии. Определяет визуальный паттерн (сплошная, пунктир и т.д.)
     */
    LineType type;

    /** 
     * @brief Толщина линии, измеряется в пикселях. Должна быть больше 0
     */
    int thickness;

    /**
     * @brief Конструктор стиля
     * @param t тип линии
     * @param th толщина (должна быть > 0)
     */
    LineStyle(const LineType& t = LineType::solid, const int th = 1);
};
