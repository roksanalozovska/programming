#include <stdio.h>
#include <math.h>

#define N 3  
#define M 4  

void inputArray(float array[], int size, char name);
void processX(float x[], int size, float* A, float* B, float* C);
void processY(float y[], int size, float* D, float* E, float* F);

int main() {
    float x[N], y[M];
    float sumX = 0, prodX = 1;
    float A, B, C;
    float D, E, F;
    float psi, numerator, denominator;

    inputArray(x, N, 'x');
    inputArray(y, M, 'y');
    processX(x, N, &A, &B, &C);
    processY(y, M, &D, &E, &F);

    numerator = A * sin(B) + B * cos(C);
    denominator = D + E * sin(F);
    if (denominator != 0) {
        psi = numerator / denominator;
        printf("Результат: ψ = %f\n", psi);
    } else {
        printf("Помилка: Ділення на ноль.\n");
    }
    return 0;
}
void inputArray(float array[], int size, char name) {
    for (int i = 0; i < size; i+=1) {
        printf("Введіть %c[%d] = ", name, i + 1);
        scanf("%f", &array[i]);
    }
}
void processX(float x[], int size, float* A, float* B, float* C) {
    float sum = 0.0f, prod = 1.0f;
    float sumSin = 0.0f, sumCos = 0.0f, sumTan = 0.0f;
    for (int i = 0; i < size; i+=1) {
        sum += x[i];
        prod *= x[i];
        sumSin += x[i] * sin(x[i]);
        sumCos += x[i] * cos(x[i]);
        sumTan += x[i] * tan(x[i]);
    }
    *A = prod * sumSin;
    *B = sum * sumCos;
    *C = (prod + sum) * sumTan;
}
void processY(float y[], int size, float* D, float* E, float* F) {
    float sumTan = 0.0f, sumExp = 0.0f, sumCos = 0.0f;
    for (int i = 0; i < size; i++) {
        sumTan += y[i] * tan(y[i]);
        sumExp += y[i] * exp(y[i]);
        sumCos += y[i] * cos(y[i]);
    }
    *D = sumTan;
    *E = sumExp;
    *F = sumCos;
}
