#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int** createJaggedArray(const size_t rows) {
    // Создаем массив указателей на строки
    int** jagged = (int**)malloc(rows * sizeof(int*));
    
    // Для каждой строки определяем случайное количество элементов (от 1 до 10)
    for (size_t i = 0; i < rows; i++) {
        size_t cols = rand() % 10 + 1; // от 1 до 10 элементов в строке
        jagged[i] = (int*)malloc(cols * sizeof(int));
        
        // Заполняем строку случайными числами
        for (size_t j = 0; j < cols; j++) {
            jagged[i][j] = rand() % 201 - 100; // от -100 до 100
        }
    }
    
    return jagged;
}

int** createJaggedArrayWithSizes(const size_t rows, size_t* sizes) {
    // Создаем массив указателей на строки
    int** jagged = (int**)malloc(rows * sizeof(int*));
    
    // Для каждой строки создаем массив заданного размера
    for (size_t i = 0; i < rows; i++) {
        jagged[i] = (int*)malloc(sizes[i] * sizeof(int));
        
        // Заполняем строку случайными числами
        for (size_t j = 0; j < sizes[i]; j++) {
            jagged[i][j] = rand() % 201 - 100; // от -100 до 100
        }
    }
    
    return jagged;
}

void printJaggedArray(int** jagged, const size_t rows, size_t* sizes) {    
    for (size_t i = 0; i < rows; i++) {
        printf("Строка %zu (элементов: %zu): ", i, sizes[i]);
        for (size_t j = 0; j < sizes[i]; j++) {
            printf("%4d ", jagged[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeJaggedArray(int** jagged, const size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(jagged[i]);
    }
    free(jagged);
}

void exampleWithRandomSizes() {
    printf("=== Пример со случайными размерами строк ===\n");
    
    
    size_t rows = 5;
    size_t* sizes = (size_t*)malloc(rows * sizeof(size_t));
    
    // Генерируем случайные размеры для каждой строки
    for (size_t i = 0; i < rows; i++) {
        sizes[i] = rand() % 10 + 1;
    }
    
    int** jagged = createJaggedArrayWithSizes(rows, sizes);
    printJaggedArray(jagged, rows, sizes);
    freeJaggedArray(jagged, rows);
    free(sizes);
}

void exampleWithFixedSizes() {
    printf("=== Пример с заданными размерами строк ===\n");
    
    size_t rows = 6;
    size_t sizes[] = {3, 1, 4, 2, 5, 2};
    
    int** jagged = createJaggedArrayWithSizes(rows, sizes);
    printJaggedArray(jagged, rows, sizes);
    freeJaggedArray(jagged, rows);
}

void interactiveExample() {
    printf("=== Режим ручного ввода ===\n");
    
    printf("Введите количество строк: ");
    size_t rows;
    scanf("%zu", &rows);
    
    size_t* sizes = (size_t*)malloc(rows * sizeof(size_t));
    
    // Запрашиваем размер каждой строки
    for (size_t i = 0; i < rows; i++) {
        printf("Введите количество элементов для строки %zu: ", i);
        scanf("%zu", &sizes[i]);
    }
    
    int** jagged = createJaggedArrayWithSizes(rows, sizes);
    printJaggedArray(jagged, rows, sizes);
    
    freeJaggedArray(jagged, rows);
    free(sizes);
}

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");
    
    printf("-----------------Задание 2-----------------\n");
    
    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));
    
    // Пример 1: Случайные размеры строк
    exampleWithRandomSizes();
    
    // Пример 2: Фиксированные размеры строк
    exampleWithFixedSizes();
    
    // Пример 3: Интерактивный ввод
    interactiveExample();
    
    return 0;
}
