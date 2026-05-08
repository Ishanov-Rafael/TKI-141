#include <iostream>
#include <cassert>
#include "point.h"
#include "color.h"
#include "linestyle.h"
#include "line.h"

void TestPoint() 
{
    Point p(10.5, 20.0);
    assert(p.x == 10.5);
    assert(p.y == 20.0);
    
    Point p2(10.5, 20.0);
    assert(p == p2); 
    
    std::cout << "TestPoint passed!" << std::endl;
}

void TestColor() 
{
    Color c(255, 128, 0);
    try 
    {
        Color errorColor(300, 0, 0);
        assert(false && "constructor should have thrown an exception"); 
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "TestColor passed!" << std::endl;
    }
}

void TestLineStyle() 
{
    LineStyle s(LineType::dash, 5);
    assert(s.thickness == 5);
    assert(s.type == LineType::dash);
    LineStyle s2(LineType::solid, -10);
    assert(s2.thickness == 1); 
    
    std::cout << "TestLineStyle passed!" << std::endl;
}

void TestLine() 
{
    Point start(0, 0), end(10, 10);
    Color red(255, 0, 0);
    LineStyle bold(LineType::solid, 3);
    
    Line l(start, end, red, bold);
    
    Color blue(0, 0, 255);
    l.setAppearance(bold, blue);
    
    std::cout << "TestLine passed!" << std::endl;
}

int main() 
{
    TestPoint();
    TestColor();
    TestLineStyle();
    TestLine();
    return 0;
}
