#pragma once

/**
 * @brief Перечисление доступных типов линий
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
    LineType type;
    int thickness;

    /**
     * @brief Конструктор стиля
     * @param t тип линии
     * @param th толщина (должна быть > 0)
     */
    LineStyle(LineType t = LineType::solid, int th = 1) : type(t), thickness(th) 
    {
        if (thickness <= 0) thickness = 1; 
    }
};
