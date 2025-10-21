#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue(void);

/**
 * @brief Выбирает как отсортировать: 0 — возрастание, 1 — убывание
 * @return возврщает 0 или 1
 */
int getSortOrder(void);

/**
 * @brief Сортирует три числа и выводит их в указанном порядке
 * @param a Первое число
 * @param b Второе число
 * @param c Третье число
 * @param order 0 если нужно вывести по возрастанию, 1 если нужно вывести по убыванию 
 */
void printSorted(double a, double b, double c, int order);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0 если программа выполнена корректно
 */
int main(void)
{
    printf("Введите три числа:\n");
    double a = getValue();
    double b = getValue();
    double c = getValue();

    int order = getSortOrder();
    printSorted(a, b, c, order);

    return 0;
}

double getValue(void)
{
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error\n");
        abort();
    }
    return value;
}

int getSortOrder(void)
{
    int choice = 0;
    printf("\nВыберите порядок вывода:\n");
    printf("1 - По возрастанию\n");
    printf("2 - По убыванию\n");
    printf("Выберите (1 или 2):\n");

    if (scanf("%d", &choice) != 1)
    {
        printf("Error\n");
        abort();
    }

    if (choice == 1)
        return 0;  
    else if (choice == 2)
        return 1;  
    else
    {
        printf("Error нужно выбрать 1 или 2\n");
        abort();
    }
}

void printSorted(double a, double b, double c, int order)
{
    if (a > b) 
    { 
        double t = a; 
        a = b; 
        b = t; 
    }
    if (b > c) 
    { 
        double t = b; 
        b = c; 
        c = t; 
    }
    if (a > b) 
    { 
        double t = a; 
        a = b; 
        b = t; 
    }

    if (order == 0)
    {
        printf("\nЧисла в порядке возрастания:\n");
        printf("%.2lf %.2lf %.2lf\n", a, b, c);
    }
    else 
    {
        printf("\nЧисла в порядке убывания:\n");
        printf("%.2lf %.2lf %.2lf\n", c, b, a);
    }
}
