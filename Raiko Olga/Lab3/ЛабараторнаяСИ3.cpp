﻿/*3.2 Спираль. Дан массив a(n, n), где n – нечетное число. Вывести
элементы массива при обходе его по спирали, начиная с центра. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void spiral(int** mass, int q, int e);
int main()
{
    srand(time(NULL));//рандомное определение последующих данных
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, j = 0, q, e;
    int** arr = NULL;
    // Динамическое выделение памяти
    printf("Введите размер массива:");
    scanf_s("%d", &q);
    arr = (int**)malloc(q * sizeof(int*));
    if (arr == NULL) {
        puts("Ошибка выделения памяти");
        return  0;
    }
    for (i = 0; i < q; i++) 
    {
        arr[i] = (int*)malloc(q * sizeof(int));
        if (arr[i] == NULL) 
        {
            puts("Ошибка выделения памяти");
            for (i = 0; i < q; i++)
                free(arr[i]);
            free(arr);//освобождение динамически выделенной памяти
            return  0;
        }
    }
    // Заполнение/вывод
    for (i = 0; i < q; i++)
    {
        for (j = 0; j < q; j++)
        {
            arr[i][j] = rand() % 10 + 1;
            printf("%3d", arr[i][j]);
        }
        printf("\n\n");
    }
    // Вызов функции
    e = q;
    spiral(arr, q, e);
    //Освобождение выделенной памяти
    for (j = 0; j < q; j++)
        free(arr[j]);
    free(arr);
    return 0;
}
void spiral(int** mass, int q, int e) {
    int  z = 0, k = 0;
    int i = 0, j = 0, n, l, w;
    i = j = w = l = q - 1;
    for (n = 0; n < q * q; n++) {
        printf("%3d", mass[i][j]);
        if ((i == (w)) && (j == l - 1)) { w--; l--; z++; k++; puts(""); } //Условие перехода
        if ((j == w) && (i > z)) { i--; continue; } //Вверх
        if ((j >= 0) && (i == w)) { j++; continue; } //Вправо
        if ((j == k) && (i >= 0)) { i++; continue; } //Вниз
        if ((j <= w) && (i == z)) { j--; continue; } //Влево
    }
}

// освобождаем память
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
