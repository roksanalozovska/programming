#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void neg_product(int *mat, int rows, int cols, long long *res) {
    for (int i = 0; i < rows; i+=1) {
        res[i] = 1;
        for (int j = 0; j < cols; j+=1)
            if (mat[i * cols + j] < 0) res[i] *= mat[i * cols + j];
        if (res[i] == 1) res[i] = 0; 
    }
}
int main() {
    srand(time(0));
    int a[10][15], b[15][12];
    long long a_res[10], b_res[15];
    for (int i = 0; i < 10; i+=1)
        for (int j = 0; j < 15; j+=1)
            a[i][j] = rand() % 21 - 10;

    for (int i = 0; i < 15; i+=1)
        for (int j = 0; j < 12; j+=1)
            b[i][j] = rand() % 21 - 10;
    neg_product((int*)a, 10, 15, a_res);
    neg_product((int*)b, 15, 12, b_res);
    printf("Матриця A:\n");
    for (int i = 0; i < 10; i+=1)
        printf("Рядок %d: %lld\n", i+1, a_res[i]);
    printf("\nМатриця B:\n");
    for (int i = 0; i < 15; i++)
        printf("Рядок %d: %lld\n", i+1, b_res[i]);
    return 0;
}