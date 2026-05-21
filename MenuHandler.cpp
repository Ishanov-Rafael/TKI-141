#include "MenuHandler.h"
#include <iostream>
#include <cstdlib>

void MenuHandler::print_error_and_exit(const std::string &text)
{
    std::cerr << text << std::endl;
    std::exit(1);
}

int MenuHandler::safe_get_int()
{
    int number = 0;
    std::cin >> number;
    if (std::cin.fail())
    {
        print_error_and_exit("Критическая ошибка: Неверный формат ввода!");
    }
    return number;
}

void MenuHandler::show_menu_ui()
{
    std::cout << "\n=== Меню управления приоритетной очередью ===" << std::endl;
    std::cout << "1 - Вставить элемент (INSERT)" << std::endl;
    std::cout << "2 - Показать минимальный элемент (GET_MIN)" << std::endl;
    std::cout << "3 - Показать максимальный элемент (GET_MAX)" << std::endl;
    std::cout << "4 - Удалить минимальный элемент (REMOVE_MIN)" << std::endl;
    std::cout << "5 - Удалить максимальный элемент (REMOVE_MAX)" << std::endl;
    std::cout << "6 - Показать всю очередь" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

void MenuHandler::initialize_queue(DoubleEndedPriorityQueue &queue)
{
    std::cout << "Введите начальное количество элементов очереди: ";
    int count = safe_get_int();
    if (count < 0)
    {
        print_error_and_exit("Ошибка: Количество не может быть отрицательным.");
    }

    if (count > 0)
    {
        std::cout << "Введите " << count << " чисел(а) через пробел: ";
        for (int i = 0; i < count; ++i)
        {
            queue.insert(safe_get_int());
        }
    }
}

bool MenuHandler::process_menu_choice(DoubleEndedPriorityQueue &queue)
{
    int choice = safe_get_int();
    if (choice == EXIT) return false;

    try
    {
        switch (choice)
        {
        case INSERT:
            {
                std::cout << "Введите число для вставки: ";
                int val = safe_get_int();
                queue.insert(val);
                std::cout << "Успешно добавлено. Очередь: " << queue.to_string() << std::endl;
                break;
            }
        case GET_MIN:
            std::cout << "Минимум: " << queue.get_min() << std::endl;
            break;
        case GET_MAX:
            std::cout << "Максимум: " << queue.get_max() << std::endl;
            break;
        case REMOVE_MIN:
            queue.remove_min();
            std::cout << "Минимум удален. Очередь: " << queue.to_string() << std::endl;
            break;
        case REMOVE_MAX:
            queue.remove_max();
            std::cout << "Максимум удален. Очередь: " << queue.to_string() << std::endl;
            break;
        case SHOW_QUEUE:
            std::cout << "Содержимое: " << queue.to_string() << std::endl;
            break;
        default:
            std::cout << "Неверный пункт меню! Попробуйте снова." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Ошибка операции: " << e.what() << std::endl;
    }
    return true;
}
