#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

/**
 * @brief ввод данных типа int
 * @return введенное значение
 */
int Value(void);

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
 * @brief заполняет массив случайными числами в пределах диапозона введеного пользователем
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief выводит элементы массива
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);


/**
 * @brief выделяет память для массива
 * @param size размер массива
 * @return указатель на выделенную память
 */
int* getArray(const size_t size);

/**
 * @brief заменяет последний отрицательный элемент на модуль первого
 * @param arr массив
 * @param size размер массива
 * @return 1 если замена выполнена, 0 если отрицательных нет
 */
int replaceLastNegativeWithAbsFirst(int* arr, const size_t size);

/**
 * @brief проверяет совпадают ли первая и вторая цифры числа по модулю
 * @param num проверяемое число.
 * @return возвращает 1 если совпадают, 0 если нет
 */
int hasSameFirstTwoDigits(const int num);

/**
 * @brief Удаляет из массива все элементы у которых первая и вторая цифры совпадают
 * @param arr массив
 * @param size размер массива
 * @param newSize указатель на переменную для нового размера
 * @return возвращает новый массив
 */
int* removeSameFirstTwoDigits(int* arr, const size_t size, size_t newSize);

/**
 * @brief Формирует массив M по правилу: четное M[i] = i * P[i], нечетное M[i] = -P[i]
 * @param arr массив
 * @param size размер массива
 * @return возвращает новый массив M
 */
int* buildMArray(int* arr, const size_t size);

/**
 * @brief RANDOM заполнение массива случайными элемантами
 * @brief MANUAL заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};
/**
 * @brief точка входа в программу
 * @return возвращает 0 если программа выполнена корректно
 */
int main(void)
{
    size_t size = getSize("Введите размер массива: ");
    int* arr = getArray(size);
    printf("Выберите способ заполнения массива:\n"
            "%d случайными числами, %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
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

    if (replaceLastNegativeWithAbsFirst(arr, size))
        printf("\nПосле замены последнего отрицательного на модуль первого:\n");
    else
        printf("\nОтрицательных элементов нет\n");
    printArray(arr, size);

    size_t newSize = 0;
    int* newArr = removeSameFirstTwoDigits(arr, size, &newSize);
    printf("\nПосле удаления элементов с одинаковыми первыми двумя цифрами (новый размер = %zu):\n", newSize);
    printArray(newArr, newSize);

    int* mArr = buildMArray(newArr, newSize);
    printf("\nМассив M (четное i*P[i], нечетное -P[i]):\n");
    printArray(mArr, newSize);

    free(mArr);
    free(newArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int v = 0;
    if (scanf_s("%d", &v) != 1)
    {
        printf("Error\n");
        exit(1);
    }
    return v;
}

size_t getSize(const char* message)
{
    printf("%s", message);
    int v = Value();
    if (v <= 0)
    {
        printf("Размер должен быть > 0\n");
        exit(1);
    }
    return (size_t)v;
}

int* getArray(const size_t size)
{
    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Error");
        exit(1);
    }
    return arr;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите A[%zu] = ", i);
        arr[i] = Value();
    }
}

void fillRandom(int* arr, const size_t size)
{
    printf("Диапозон start: ");
    int start = Value();
    printf("Диапозон end: ");
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

void printArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int replaceLastNegativeWithAbsFirst(int* arr, const size_t size)
{
    int firstAbs = abs(arr[0]);
    ssize_t lastNegIndex = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            lastNegIndex = (ssize_t)i;
    }

    if (lastNegIndex == -1)
        return 0;

    arr[lastNegIndex] = firstAbs;
    return 1;
}

int hasSameFirstTwoDigits(const int num)
{
    int n = abs(num);
    if (n < 10) return 0;
    while (n >= 100)
        n /= 10;
    int first = n / 10;
    int second = n % 10;
    return (first == second) ? 1 : 0;
}

int* removeSameFirstTwoDigits(int* arr, const size_t size, size_t newSize)
{
    for (size_t i = 0; i < size; i++)
    {
        if (!hasSameFirstTwoDigits(arr[i]))
            (newSize)++;
    }

    int* newArr = (int*) malloc((newSize) * sizeof(int));
    if (!newArr)
    {
        printf("Error\n");
        exit(1);
    }

    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!hasSameFirstTwoDigits(arr[i]))
        {
            newArr[j++] = arr[i];
        }
    }
    return newArr;
}

int* buildMArray(int* arr, const size_t size)
{
    int* mArr = (int*) malloc(size * sizeof(int));
    if (!mArr)
    {
        printf("Error\n");
        exit(1);
    }

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            mArr[i] = (int)i * arr[i];
        else
            mArr[i] = -arr[i];
    }
    return mArr;
}
