#include <stdio.h>
#include <stdlib.h>

/**
 * @brief выводит три числа в порядке возрастания
 * @param a первое число
 * @param b второе число
 * @param c третье число
 */
void getVozrastanie(const double a, const double b, const double c);

/**
 * @brief выводит три числа в порядке убывания
 * @param a первое число
 * @param b второе число
 * @param c третье число
 */
void getUbivanie(const double a, const double b, const double c);

/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();  

enum {VOZRASTANIE, UBIVANIE};

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите три числа a, b, c: ");
    double a = getValue();
    double b = getValue();
    double c = getValue();
    printf("Выберите порядок вывода: %d - по возрастанию, %d - по убыванию\n", VOZRASTANIE, UBIVANIE);
    int choice = (int) getValue();
    switch (choice)
    {
    case VOZRASTANIE:
        printf("Числа по возрастанию: ");
        getVozrastanie(a, b, c);
        break;
    case UBIVANIE:
        printf("Числа по убыванию: ");
        getUbivanie(a, b, c);
        break;
    default:
        printf("Неправильный выбор!\n");
        abort();
    }

    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}

void getVozrastanie(const double a, const double b, const double c)
{
    double minimum = min(min(a, b), c);
    double maximum = max(max(a, b), c);
    double average = a + b + c - minimum - maximum;
    printf("%.2lf, %.2lf, %.2lf\n", minimum, average, maximum);
}

void getUbivanie(const double a, const double b, const double c)
{
    double minimum = min(min(a, b), c);
    double maximum = max(max(a, b), c);
    double average = a + b + c - minimum - maximum;
    printf("%.2lf, %.2lf, %.2lf\n", maximum, average, minimum);
}
