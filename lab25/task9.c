#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, M, i;
    float *A, *B;
    float maxA, maxB;
    srand(time(0));
    N = rand() % 18 + 3;
    M = rand() % 19 + 1;
    printf("Згенеровано N: %d, M: %d\n", N, M);
    A = (float*)malloc(N * sizeof(float));
    B = (float*)malloc(M * sizeof(float));
    if (!A || !B) {
        puts("Помилка виділення пам'яті");
        return 1;
    }
    printf("\nМасив A (оригінальний):\n");
    for (i = 0; i < N; i+=1) {
        A[i] = (float)(rand() % 100) / 10.0f;
        printf("%.2f ", A[i]);
    }
    printf("\n\nМасив B (оригінальний):\n");
    for (i = 0; i < M; i+=1) {
        B[i] = (float)(rand() % 100) / 10.0f;
        printf("%.2f ", B[i]);
    }
    maxA = A[0];
    for (i = 1; i < N; i+=1) {
        if (A[i] > maxA) {
            maxA = A[i];
        }
    }  
    maxB = B[0];
    for (i = 1; i < M; i+=1) {
        if (B[i] > maxB) {
            maxB = B[i];
        }
    }
    printf("\n\nМаксимум в A: %.2f, Максимум в B: %.2f\n", maxA, maxB);
    for (i = 0; i < N; i+=1) {
        A[i] /= maxA;
    }
    for (i = 0; i < M; i+=1) {
        B[i] /= maxB;
    }
    printf("\nМасив A (перетворений):\n");
    for (i = 0; i < N; i+=1) {
        printf("%.2f ", A[i]);
    }   
    printf("\n\nМасив B (перетворений):\n");
    for (i = 0; i < M; i+=1) {
        printf("%.2f ", B[i]);
    }
    free(A);
    free(B);
    return 0;
}