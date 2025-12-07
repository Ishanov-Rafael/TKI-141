#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

/**
 * @brief ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief выводит текстовое сообщение о необзодимости ввода размера массива провераяет ввод на правильность, задает размер массива 
 * @param message текстовое сообщение о необходимости ввода массива 
 * @return выводит размер массива
 */ 
size_t getSize(char* message);

/**
 * @brief считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief выводит элементы массива
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);

/** 
 * @brief заполняет массив случайными числами в пределах диапозона введеного пользователем
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief находит произведение четных элементов значения которых по модулю меньше 5
 * @param arr массив 
 * @param size размер массива
 * @return возвращает произведение подходящих элементов при выполнении
 */
double productEvenLessThan5(const int* arr, const size_t size);

/**
 * @brief находит количество нечетных и по модулю превосходит заданное число А элементов
 * @param arr массив
 * @param size размер массива
 * @param A заданное число
 */
int countOddMoreThanA(const int* arr, const size_t size, int A);

/**
 * @brief умножает все нечетные элементы массива кратные 3 на их индекс
 * @param arr массив
 * @param size размер массива 
 */
void umnozhenieOddKratnieOf3OnIndex(int* arr, const size_t size);

/**
 * @brief RANDOM заполнение массива случайными элемантами
 * @brief MANUAL заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief точка входа в программу
 * @return возвращает 0 если программа выполнена корректно
 */
int main()
{
    size_t size = getSize("Введите размер массива:  ");
    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Error");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
            "%d случайными числами, %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, size);
                break;
            case MANUAL:
                fillArray(arr, size);
                break;
            default:
                printf("error");
                free(arr);
                return 1;
        }

    printf("\nИсходный массив: ");
    printArray(arr, size);

    
    double product = productEvenLessThan5(arr, size);
    if (product == 0) 
        printf("\nНет четных элементов с модулем меньше 5");
    else
        printf("\nПроизведение четных элементов с модулем < 5 = %f", product);

    printf("\nВведите число A: ");
    int A = Value();
    int count = countOddMoreThanA(arr, size, A);
    printf("\nКоличество нечетных элементов с модулем > %d = %d", A, count);

    umnozhenieOddKratnieOf3OnIndex(arr, size);
    printf("\nМассив после умножения нечетных кратных 3 на их индексы:");
    printArray(arr, size);

    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Vvedite A[%zu] = ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); 
}

void fillRandom(int* arr, const size_t size)
{
    printf("Диапазон start: ");
    int start = Value();
    printf("Диапазон end: ");
    int end = Value();
    if (start > end)
    {
        printf("Error: start > end\n");
        exit(1);    
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

double productEvenLessThan5(const int* arr, const size_t size)
{
    double product = 1;
    int found = 0; 

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0 && abs(arr[i]) < 5) 
        {
            product *= arr[i];
            found = 1;
        }
    }
    return found ? product : 0;
}

int countOddMoreThanA(const int* arr, const size_t size, int A)
{
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && abs(arr[i]) > A) 
        {
            count++;
        }
    }

    return count;
}

void umnozhenieOddKratnieOf3OnIndex(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && arr[i] % 3 == 0)
        {
            arr[i] *= (int)i;
        }
    }
}
