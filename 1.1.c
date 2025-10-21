#include <math.h>
#include <stdio.h>
/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */

double getB(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */ 

int main()
{
    const double x = 0.61;
    const double y = 0.9;
    const double z = 0.3;
    printf("A = %lf", getA(x, y, z));
    printf("B = %lf", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (pow(z, 2 * x) + pow(y, -x) * cos(z + y) * x)/(x + 1);
}

double getB(const double x, const double y, const double z)
{
    return sqrt(x * x + y) - y * y * pow(sin((x + z)/x), 3);
}
