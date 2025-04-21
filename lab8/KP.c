#include <stdio.h>
#define ROWS 3  
#define COLS 4  

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int vector[COLS] = {1, 1, 1, 1};
    int result[ROWS];
    for (int i = 0; i < ROWS; i+=1) {
        result[i] = 0;
        for (int j = 0; j < COLS; j+=1) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    int max = result[0];
    int maxIndex = 0;
    for (int i = 1; i < ROWS; i+=1) {
        if (result[i] > max) {
            max = result[i];
            maxIndex = i;
        }
    }
    printf("Результат множення матриці на вектор:\n");
    for (int i = 0; i < ROWS; i+=1) {
        printf("result[%d] = %d\n", i, result[i]);
    }
    printf("\nНайбільше значення: %d, індекс: %d\n", max, maxIndex);
    return 0;
}