#include <stdio.h>
#include <math.h>

/*
 * @brief рассчитывает расстояние между двумя шарами по закону всемирного тяготения
 * @param m масса каждого шара в тоннах
 * @param F коэффициент силы тяготения
 * @return расстояние в метрах
 */
double rasstoyanie(const double m, const double F);

/*
 * @brief точка входа в программу
 * @return возвращает 0 если программа выполнена корректно
 */
int main()
{
    double m = 0;
    double F = 0;      
    int value = 0;
    double distance = 0;
    printf("Введите массу каждого шара в тоннах: ");
    value = scanf("%lf", &m);
    if (value != 1 || m <= 0)
    {
        printf("Ошибка, введите положительное число\n");
        return 1;
    }
    printf("Введите коэффициент силы тяготения F: ");
    value = scanf("%lf", &F);
    if (value != 1 || F <= 0)
    {
        printf("Ошибка, введите положительное число\n");
        return 1;
    }
    printf("Расстояние между шарами: %.6lf метров\n", rasstoyanie(m, F));
    return 0;
}

double rasstoyanie(const double m, const double F)
{
    const double G = 6.67430e-11;
    const double mass_kg = m * 1000;
    const double force = F * 1e-5;
    return sqrt(G * mass_kg * mass_kg / force);
}
