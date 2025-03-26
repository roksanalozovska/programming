#include <stdio.h>

int main() {
    int N;
    printf("Введіть розмір масивів A і D: ");
    scanf("%d", &N);
    int A[N], D[N];
    printf("Введіть елементи масиву A:\n");
    for (int i = 0; i < N; i+=1) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    printf("Введіть елементи масиву D:\n");
    for (int i = 0; i < N; i+=1) {
        printf("D[%d] = ", i);
        scanf("%d", &D[i]);
    }
    int B[2 * N];
    for (int i = 0; i < N; i+=1) {
        B[2 * i] = A[i];    
        B[2 * i + 1] = D[i]; 
    }
    printf("Вектор B: ");
    for (int i = 0; i < 2 * N; i+=1) {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}