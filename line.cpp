#include "line.h"
#include "point.h" 
#include "color.h"     
#include <iostream>    

Line::Line(const Point& start, const Point& end, const Color& c, const LineStyle& s) 
    : p1(start), p2(end), color(c), style(s) {}

void Line::setAppearance(const LineStyle& s, const Color& c) 
{
    style = s;
    color = c;
}

Line Line::read() 
{
    Point a, b;
    int r, g, b_val;
    
    std::cout << "Enter the coordinates of the first point (x y): ";
    std::cin >> a;
    std::cout << "Enter the coordinates of the second point (x y): ";
    std::cin >> b;
    std::cout << "Enter a color RGB (3 numbers 0-255): ";
    std::cin >> r >> g >> b_val;

    return Line(a, b, Color(r, g, b_val));
}

std::ostream& operator<<(std::ostream& os, const Line& l) 
{
    os << "Line: " << l.p1 << " -> " << l.p2 
       << " | Color: " << l.color 
       << " | Thickness: " << l.style.thickness;
    return os;
}
