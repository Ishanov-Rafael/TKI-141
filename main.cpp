#include <iostream>
#include "Line.h"

int main() 
{
    try 
    {
        std::cout << "--- Test 1: Static reading ---" << std::endl;
        Line userLine = Line::read();
        std::cout << "You have entered: " << userLine << std::endl;

        std::cout << "\n--- Test 2: Exceptions ---" << std::endl;
        std::cout << "An attempt to create an incorrect color (300, 0, 0)..." << std::endl;
        Color badColor(300, 0, 0);

    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
