#include <stdio.h>
#define M 3 

int main() {
    float A[M][M], T[M][M], max;     
    int i, j;
    printf("Введіть елементи матриці A[%d][%d]:\n", M, M);
    for(i = 0; i < M; i+=1) {
        for(j = 0; j < M; j+=1) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    for(i = 0; i < M; i+=1) {
        for(j = 0; j < M; j+=1) {
            T[j][i] = A[i][j];
        }
    }
    max = T[0][0];
    for(i = 0; i < M; i+=1) {
        for(j = 0; j < M; j+=1) {
            if(T[i][j] > max) {
                max = T[i][j];
            }
        }
    }
    printf("\nТранспонована матриця T:\n");
    for(i = 0; i < M; i+=1) {
        for(j = 0; j < M; j+=1) {
            printf("%.2f\t", T[i][j]);
        }
        printf("\n");
    } 
    printf("\nМаксимальний елемент у транспонованій матриці: %.2f\n", max);    
    return 0;
}