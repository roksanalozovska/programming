#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    float matrix[ROWS][COLS];
    float min_element;
    int min_row = 0, min_col = 0;
    int i, j;
    FILE *file;
    printf("Введіть елементи матриці %dx%d:\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Елемент [%d][%d]: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
    min_element = matrix[0][0];
    for (i = 0; i < ROWS; i+=1) {
        for (j = 0; j < COLS; j+=1) {
            if (matrix[i][j] < min_element) {
                min_element = matrix[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }
    printf("\nМінімальний елемент: %.2f\n", min_element);
    printf("Розташований у рядку %d, стовпчику %d\n", min_row+1, min_col+1);
    if (min_element != 0) {
        for (i = 0; i < ROWS; i+=1) {
            for (j = 0; j < COLS; j+=1) {
                matrix[i][j] /= min_element;
            }
        }
    } else {
        printf("\nУвага: мінімальний елемент дорівнює 0. Ділення неможливе.\n");
    }
    file = fopen("exit.txt", "w");
    if (file == NULL) {
        printf("Помилка відкриття файлу для запису!\n");
        return 1;
    }
    fprintf(file, "Матриця після ділення на %.2f:\n", min_element);
    for (i = 0; i < ROWS; i+=1) {
        for (j = 0; j < COLS; j+=1) {
            fprintf(file, "%.4f\t", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("\nРезультати записано у файл 'exit.txt'\n");
    return 0;
}