#include <iostream>
#include <string>
#include "Point.h"
#include "Tetrahedron.h"

/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param report - строка информации
 * @return считанное значение
 */
double getValue(std::string report = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() 
{
    Point pts[4];
    for (int i = 0; i < 4; ++i) 
    {
        std::cout << "Point " << i + 1 << ":" << std::endl;
        double x = getValue(" x: ");
        double y = getValue(" y: ");
        double z = getValue(" z: ");
        pts[i] = Point(x, y, z);
    }

    Tetrahedron myTetra(pts[0], pts[1], pts[2], pts[3]);
    
    std::cout << "\nVolume tetrahedron: " << myTetra.getVolume() << std::endl;

    return 0;
}

double getValue(std::string report) 
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail()) 
    {
        std::cout << "Input error!" << std::endl;
        exit(1);
    }
    return value;
}
