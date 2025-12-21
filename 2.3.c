#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief сортирует числа в порядке возрастания
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @return возвращает сортировку в порядке возрастания
 */
void getStrypeUP(const double min_num, const double middle_num, const double max_num);
/**
 * @brief сортирует числа в порядке убывания
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @return возвращает сортировку в порядке убывания
 */
void getStrypeDOWN(const double min_num,const  double middle_num,const double max_num);
/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */

double getValue();
/**
@brief StrypeUP - сортировка по возрастанию
@brief StrypeDOWN - сортировка по убыванию
*/
enum {StrypeUP, StrypeDOWN};
/**
 * @brief точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите переменную x : ");
    double x = getValue();

    double sin_x = sin(x);
    double cos_x = cos(x);
    double ln_x = log(x); 

    printf("sin x = %.2lf\n", sin_x);
    printf("cos x = %.2lf\n", cos_x);

    if (x > 0)
    {
        printf("ln x = %.2lf\n", ln_x);
    
        double max_num = fmax(fmax(sin_x, cos_x), ln_x);
        double min_num = fmin(fmin(sin_x, cos_x), ln_x);
        double middle_num = sin_x + cos_x + ln_x - max_num - min_num;

        printf("Выберите порядок чисел: 0(по возрастанию), 1(по убыванию): ");
        int choice = (int) getValue();
        switch(choice)
        {
            case StrypeUP:
                getStrypeUP(min_num, middle_num, max_num);
                break;
            case StrypeDOWN:
                getStrypeDOWN(min_num, middle_num, max_num);
                break;
            default:
                printf("Неправильный выбор\n");
                return 1;
        }
    }
    else
    {
        printf("ln x находится за пределом области значений\n");
        double max_num = fmax(sin_x, cos_x);
        double min_num = fmin(sin_x, cos_x);

        printf("Выберите порядок чисел: 0(по возрастанию), 1(по убыванию) : ");
        int choice = (int) getValue();
        switch(choice)
        {
            case StrypeUP:
                printf("Сортировка по возрастанию: %.2lf, %.2lf\n", min_num, max_num);
                break;
            case StrypeDOWN:
                printf("Сортировка по убыванию: %.2lf, %.2lf\n", max_num, min_num);
                break;
            default:
                printf("Неправильный выбор\n");
                return 1;
        }
    }

    return 0;
}

void getStrypeUP(const double min_num, const double middle_num,const  double max_num)
{
    printf("Сортировка по возрастанию: %.2lf, %.2lf, %.2lf\n", min_num, middle_num, max_num);
}

void getStrypeDOWN(const double min_num, const double middle_num, const double max_num)
{
    printf("Сортировка по убыванию: %.2lf, %.2lf, %.2lf\n", max_num, middle_num, min_num);
}
double getValue()

{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Неверный ввод!");
        exit(1);
    }
    return value;
}
