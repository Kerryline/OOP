#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int** createMatrix(const size_t N) {
    int** mat = (int**)malloc(N * sizeof(int*));
    for (size_t i = 0; i < N; i++) {
        mat[i] = (int*)malloc(N * sizeof(int));
        for (size_t j = 0; j < N; j++)
            mat[i][j] = rand() % 201 - 100; // от -100 до 100
    }
    return mat;
}

void printArr(int* arr, const size_t N) {
    for (size_t i = 0; i < N; i++)
        printf("%4d ", arr[i]);
    printf("\n");
}

void printMat(int** mat, const size_t N) {
    printf("Матрица:\n");

    for (size_t i = 0; i < N; i++)
        printArr(mat[i], N);
    printf("\n");
}

void getRightDiagonal(int** mat, const size_t N) {
    int* D = (int*)malloc(N * sizeof(int));

    for (size_t i = 0; i < N; i++)
        D[i] = mat[i][N - i - 1];

    printf("Правая диагональ: ");
    printArr(D, N);

    free(D);
}

void getLeftDiagonal(int** mat, const size_t N) {
    int* D = (int*)malloc(N * sizeof(int));

    for (size_t i = 0; i < N; i++)
        D[i] = mat[i][i];

    printf("Левая диагональ: ");
    printArr(D, N);

    free(D);
}

void spiralFromCenter(int** mat, const size_t N) {
    int* D = (int*)malloc(N * N * sizeof(int));

    size_t x = N / 2, y = N / 2;
    size_t line = 1, max_line = 1;
    
    enum Dir {
        up,
        left,
        down,
        right
    };
    enum Dir dir = up;

    for (size_t i = 0; i < N * N; i++) {
        D[i] = mat[y][x];

        switch (dir) {
            case up:
                y--;
                line--;
                if (line == 0) {
                    dir = left;
                    line = max_line;
                }
                break;

            case left:
                x--;
                line--;
                if (line == 0) {
                    dir = down;
                    max_line += (i == 3) ? 2 : 1;
                    line = max_line;
                }
                break;

            case down:
                y++;
                line--;
                if (line == 0) {
                    dir = right;
                    line = max_line;
                }
                break;

            case right:
                x++;
                line--;
                if (line == 0) {
                    dir = up;
                    max_line++;
                    line = max_line;
                }
                break;
        }
    }

    printf("Спираль из центра: ");
    printArr(D, N * N);

    free(D);
}

void spiralFromTopLeft(int** mat, const size_t N) {
    int* D = (int*)malloc(N * N * sizeof(int));

    size_t x = 0, y = 0;
    size_t line = N - 1, max_line = N;
    
    enum Dir {
        up,
        left,
        down,
        right
    };
    enum Dir dir = down;

    for (size_t i = 0; i < N * N; i++) {
        D[i] = mat[y][x];

        switch (dir) {
            case up:
                y--;
                line--;
                if (line == 0) {
                    dir = left;
                    max_line--;
                    line = max_line;
                }
                break;

            case left:
                x--;
                line--;
                if (line == 0) {
                    dir = down;
                    line = max_line;
                }
                break;

            case down:
                y++;
                line--;
                if (line == 0) {
                    dir = right;
                    max_line--;
                    line = max_line;
                }
                break;

            case right:
                x++;
                line--;
                if (line == 0) {
                    dir = up;
                    line = max_line;
                }
                break;
        }
    }

    printf("Спираль из левого верхнего угла: ");
    printArr(D, N * N);

    free(D);
}

void freeMem(int** mat, const size_t N) {
    for (size_t i = 0; i < N; i++) free(mat[i]);
    free(mat);
}

int main() {
    
    printf("-----------------Задание 1-----------------\n");

    printf("Введите число N: ");
    size_t N;
    scanf("%zu", &N);
    printf("\n");
    
    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));
    
    int** mat = createMatrix(N);
    printMat(mat, N);
    
    getRightDiagonal(mat, N);
    getLeftDiagonal(mat, N);
    spiralFromCenter(mat, N);
    spiralFromTopLeft(mat, N);

    freeMem(mat, N);
    
    return 0;
}
