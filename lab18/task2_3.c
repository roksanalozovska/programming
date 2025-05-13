#include <stdio.h>
#include <math.h>

#define N 3   
#define M 5   

void inputArray(float array[], int size, char name);
void processArray(float array[], int size, double func1(double), double func2(double), float* result1, float* result2);
float sumArray(float array[], int size);

int main() {
    float alpha[N], beta[M];
    float sumAlpha, A, B, C;
    float sumBeta, D, E, F;
    float omega, numerator, denominator;

    inputArray(alpha, N, 'α');
    inputArray(beta, M, 'β');
    sumAlpha = sumArray(alpha, N);
    processArray(alpha, N, tan, sin, &A, &C);
    B = 1.0f;
    for (int i = 0; i < N; i+=1) {
        B *= alpha[i];
    }
    A *= sumAlpha;
    C *= sumAlpha;
    sumBeta = sumArray(beta, M);
    processArray(beta, M, cos, fabs, &D, &F);
    E = 1.0f;
    for (int i = 0; i < M; i+=1) {
        E *= beta[i];
    }
    numerator = A * cos(B) + C;
    denominator = D + E * sin(F);
    if (denominator != 0) {
        omega = numerator / denominator;
        printf("Результат: ω = %f\n", omega);
    } else {
        printf("Помилка: Ділення на 0!\n");
    }
    printf("Finish.\n");
    return 0;
}
void inputArray(float array[], int size, char name) {
    for (int i = 0; i < size; i+-1) {
        printf("Введіть %c[%d] = ", name, i + 1);
        scanf("%f", &array[i]);
    }
}
void processArray(float array[], int size, double func1(double), double func2(double), float* result1, float* result2) {
    float sum = 0.0f;
    *result1 = 0.0f;
    *result2 = 1.0f;

    for (int i = 0; i < size; i+=1) {
        sum += array[i];
        *result1 += array[i] * func1(array[i]);
        *result2 *= array[i] * func2(array[i]);
    }
    *result1 *= sum;
}
float sumArray(float array[], int size) {
    float total = 0.0f;
    for (int i = 0; i < size; i+=1) {
        total += array[i];
    }
    return total;
}
