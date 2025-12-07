#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int getValue(void);

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getDouble(void);

/**
 * @brief вычисляет сумму членов ряда
 * @param n число членов
 * @return возвращает рассчитанную сумму
 */
double getSumN(const int n);

/**
 * @brief вычисляет сумму ряда с заданной точностью e
 * @param e требуемая точность
 * @return возвращает рассчитанную сумму
 */
double getSumE(const double e);

/**
 * @brief высчитавает коэффициент рекуррентного выражения
 * @param i текущий индекс члена ряда
 * @return возвращает рассчитанное значения коэффициента
 */
double getRecurent(const int i);

/**
 * @brief проверяет что значение неотрицательное
 * @param value проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief точка входа в программу
 * @return возвращает 0 если программа выполнена корректно
 */
int main(void)
{
    printf("Введите n:\n");
    int n = getValue();
    checkPositive(n);

    double sumN = getSumN(n);
    printf("Сумма %d чисел последовательности равна %.6lf\n", n + 1, sumN);

    printf("Введите e:\n");
    double e = getDouble();
    checkPositive(e);

    double sumE = getSumE(e);
    printf("Сумма последовательности с точностью %lf равна %.6lf\n", e, sumE);

    return 0;
}

int getValue(void)
{
    int value = 0;
    if (scanf("%d", &value) != 1) 
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getDouble(void)
{
    double value = 0;
    if (scanf("%lf", &value) != 1) 
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getSumN(const int n)
{
    double current = 1.0;
    double result = current;    
    for (int i = 0; i < n; i++) 
    {
        current *= getRecurent(i);
        result += current;
    }
    return result;
}

double getRecurent(const int i)
{
    return -1.0 / ((2*i + 1) * (2*i + 2));
}

void checkPositive(const double value)
{
    if (value < 0) 
    {
        printf("Error.\n");
        exit(1);
    }
}

double getSumE(const double e)
{
    double current = 1.0;
    double result = 0.0;
    for (int i = 0; fabs(current) > e; i++) 
    {
        result += current;
        current *= getRecurent(i);
    }
    return result;
}
