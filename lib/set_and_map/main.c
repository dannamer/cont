#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int* arr = (int*)malloc(5 * sizeof(int)); // Выделяем блок памяти для 5 целых чисел
    if (arr == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    // Заполняем массив начальными значениями
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Увеличиваем размер блока памяти до 10 элементов
    arr = (int*)realloc(arr, 10 * sizeof(int));

    // Проверяем и выводим содержимое массива
    printf("Содержимое массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Инициализируем новые элементы нулями
    memset(arr + 5, 0, 5 * sizeof(int));

    // Проверяем и выводим обновленное содержимое массива
    printf("Обновленное содержимое массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Освобождаем выделенную память
    free(arr);

    return 0;
}
