#include <stdio.h>
#include <stdlib.h>

/**
 * @brief выводит три числа в порядке возрастания
 * @param minimum первое число(минимальное)
 * @param average второе число(среднее)
 * @param maximum третье число(максимальное)
 */
void getVozrastanie(const double minimum, const double average, const double maximum);

/**
 * @brief выводит три числа в порядке убывания
 * @param maximum первое число(максимальное)
 * @param average второе число(среднее)
 * @param minimum третье число(минимальное)
 */
void getUbivanie(const double maximum, const double average, const double minimum);

/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();  

/**
 * @brief VOZRASTANIE - значения в порядке возрастания
 * @brief UBIVANIE - значения в порядке убывания
 */
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
    double minimum = min(min(a, b), c);
    double maximum = max(max(a, b), c);
    double average = a + b + c - minimum - maximum;
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
        return 1;
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

void getVozrastanie(const double minimum, const double average, const double maximum)
{
    printf("%.2lf, %.2lf, %.2lf\n", minimum, average, maximum);
}

void getUbivanie(const double maximum, const double average, const double minimum)
{
    printf("%.2lf, %.2lf, %.2lf\n", maximum, average, minimum);
}
