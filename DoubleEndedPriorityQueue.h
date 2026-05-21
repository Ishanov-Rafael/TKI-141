#pragma once

#include <initializer_list>
#include <string>

/**
 * @brief Класс Двусторонняя очередь с приоритетом (Double-Ended Priority Queue)
 */
class DoubleEndedPriorityQueue
{
private:
    /**
     * @brief Указатель на динамический массив элементов очереди
     */
    int *m_elements;

    /**
     * @brief Текущее количество элементов в очереди
     */
    size_t m_count;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    DoubleEndedPriorityQueue();

    /**
     * @brief Конструктор со списком инициализации
     * @param items Список элементов для инициализации
     */
    DoubleEndedPriorityQueue(const std::initializer_list<int>& items);

    /**
     * @brief Конструктор копирования
     * @param other Ссылка на копируемый объект очереди
     */
    DoubleEndedPriorityQueue(const DoubleEndedPriorityQueue &other);

    /**
     * @brief Конструктор перемещения
     * @param other Rvalue-ссылка на перемещаемый объект очереди
     */
    DoubleEndedPriorityQueue(DoubleEndedPriorityQueue &&other) noexcept;

    /**
     * @brief Деструктор класса
     */
    ~DoubleEndedPriorityQueue();

    /**
     * @brief Преобразование содержимого очереди в строковый формат
     * @return Возвращает строку со всеми элементами очереди через пробел, либо "Empty"
     */
    std::string to_string() const;

    /**
     * @brief Получить текущее количество элементов в очереди
     * @return Количество элементов
     */
    size_t get_size() const;

    /**
     * @brief Проверить, пуста ли очередь
     * @return true если в очереди нет элементов, false если в очереди есть хотя бы один элемент
     */
    bool is_empty() const;

    /**
     * @brief Вставка нового элемента в очередь
     * @param value Значение целого числа для вставки
     */
    void insert(int value);

    /**
     * @brief Получить элемент с наименьшим приоритетом (минимальный)
     * @return Значение минимального элемента
     */
    int get_min() const;

    /**
     * @brief Получить элемент с наибольшим приоритетом (максимальный)
     * @return Значение максимального элемента
     */
    int get_max() const;

    /**
     * @brief Удалить элемент с наименьшим приоритетом из очереди
     */
    void remove_min();

    /**
     * @brief Удалить элемент с наибольшим приоритетом из очереди
     */
    void remove_max();

    /**
     * @brief Оператор присваивания копированием
     * @param other Ссылка на источник для копирования
     */
    DoubleEndedPriorityQueue &operator=(const DoubleEndedPriorityQueue &other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Cсылка на источник для перемещения ресурсов
     */
    DoubleEndedPriorityQueue &operator=(DoubleEndedPriorityQueue &&other) noexcept;

    /**
     * @brief Оператор сдвига влево
     * @param value Значение для вставки в очередь
     */
    DoubleEndedPriorityQueue &operator<<(int value);

    /**
     * @brief Оператор сдвига вправо
     * @param value Ссылка на переменную, куда будет помещено извлеченное значение
     */
    DoubleEndedPriorityQueue &operator>>(int &value);
};
