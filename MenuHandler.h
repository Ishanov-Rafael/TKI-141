#pragma once
#include "DoubleEndedPriorityQueue.h"
#include <string>

/**
 * @brief EXIT - Выход из демонстрационной программы
 * @brief INSERT - Операция вставки нового элемента
 * @brief GET_MIN - Операция просмотра минимального элемента
 * @brief GET_MAX - Операция просмотра максимального элемента
 * @brief REMOVE_MIN - Операция удаления минимального элемента
 * @brief REMOVE_MAX - Операция удаления максимального элемента
 * @brief SHOW_QUEUE - Операция вывода всей очереди на экран
 */
enum MenuActions
{
    EXIT = 0, 
    INSERT = 1,
    GET_MIN,
    GET_MAX,
    REMOVE_MIN,
    REMOVE_MAX,
    SHOW_QUEUE
};

/**
 * @brief Статический класс-контроллер для управления пользовательским интерфейсом
 */
class MenuHandler
{
private:
    /**
     * @brief Выводит критическую ошибку в поток cerr и экстренно завершает приложение
     * @param text Текст сообщения об ошибке
     */
    static void print_error_and_exit(const std::string &text);
    /**
     * @brief Выполняет безопасное чтение целого числа из стандартного потока ввода
     */
    static int safe_get_int();

public:
    /**
     * @brief Отображает в консоли текстовый интерфейс главного меню программы
     */
    static void show_menu_ui();
    /**
     * @brief Выполняет первоначальное интерактивное заполнение очереди элементами
     * @param queue Ссылка на инициализируемую очередь с приоритетом
     */
    static void initialize_queue(DoubleEndedPriorityQueue &queue);
    /**
     * @brief Считывает выбор пользователя и выполняет соответствующее действие над очередью
     * @param queue Ссылка на обрабатываемый объект очереди
     */
    static bool process_menu_choice(DoubleEndedPriorityQueue &queue);
};
