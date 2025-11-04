#include <stdio.h>

/**
 * @brief рассчитывает число из сантиметров в дюймах
 * @param number число введенное пользователем
 * @return возвращает число рассчитанное в дюймах
 */
double getResult(const double number);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите число\n");
    double number = 0;
    scanf("%lf",&number);
    printf("Число равное в см %.2lf\n", number);
    printf("Число равное в дюймах %.2lf",getResult(number));

    return 0;
}

double getResult(const double number)
{
    return number / 2.5;
}
