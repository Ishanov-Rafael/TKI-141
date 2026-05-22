#include "DoubleEndedPriorityQueue.h"
#include "MenuHandler.h"
#include <iostream>

/**
 * @brief точка входа в программу 
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    std::setlocale(LC_ALL, "Russian");
    DoubleEndedPriorityQueue mainQueue;

    MenuHandler::initialize_queue(mainQueue);

    bool running = true;
    while (running)
    {
        std::cout << "\nТекущее состояние: [ " << mainQueue.to_string() << " ]" << std::endl;
        MenuHandler::show_menu_ui();
        running = MenuHandler::process_menu_choice(mainQueue);
    }

    if (!mainQueue.is_empty())
    {
        std::cout << "\n--- Демонстрация операторов сдвига (<< и >>) ---" << std::endl;
        mainQueue << 88; 
        std::cout << "Добавили 88: " << mainQueue.to_string() << std::endl;
        
        int pulledMax = 0;
        mainQueue >> pulledMax; 
        std::cout << "Извлечен максимум: " << pulledMax << std::endl;
        std::cout << "Итог: " << mainQueue.to_string() << std::endl;
    }

    std::cout << "Программа успешно завершена." << std::endl;
    return 0;
}
