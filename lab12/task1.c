#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Функція для введення елементів масиву
void input_array(double arr[], int n, char name) {
    printf("Введіть %d елементів масиву %c:\n", n, name);
    for (int i = 0; i < n; i++) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

// Функція для обчислення суми з використанням двох функцій
double calculate_sum(double arr1[], int n1, double arr2[], int n2, 
                    double (*f1)(double), double (*f2)(double)) {
    double sum = 0.0;
    
    // Обчислюємо першу суму: f1 для кожного елемента першого масиву
    for (int i = 0; i < n1; i++) {
        sum += f1(arr1[i]);
    }
    
    // Обчислюємо другу суму: f2 для кожного елемента другого масиву
    for (int i = 0; i < n2; i++) {
        sum += f2(arr2[i]);
    }
    
    return sum;
}

// Додаткова функція для обчислення D, яка використовує q²
double calculate_D(double q[], int n, double (*f1)(double), double (*f2)(double)) {
    double sum = 0.0;
    
    // Перша сума: f1 для кожного елемента масиву q
    for (int i = 0; i < n; i++) {
        sum += f1(q[i]);
    }
    
    // Друга сума: f2 для кожного елемента масиву q, помноженого на себе
    for (int i = 0; i < n; i++) {
        sum += f2(q[i]) * q[i] * q[i]; // q² * cos(q)
    }
    
    return sum;
}

int main() {
    int na, nx, nz, nq;
    
    // Введення кількості елементів для кожного масиву
    printf("Введіть кількість елементів масиву x (nₐ): ");
    scanf("%d", &na);
    printf("Введіть кількість елементів масиву y (nₓ): ");
    scanf("%d", &nx);
    printf("Введіть кількість елементів масиву z (n₂): ");
    scanf("%d", &nz);
    printf("Введіть кількість елементів масиву q (n₀): ");
    scanf("%d", &nq);
    
    // Виділення пам'яті для масивів
    double *x = (double*)malloc(na * sizeof(double));
    double *y = (double*)malloc(nx * sizeof(double));
    double *z = (double*)malloc(nz * sizeof(double));
    double *q = (double*)malloc(nq * sizeof(double));
    
    // Введення елементів масивів
    input_array(x, na, 'x');
    input_array(y, nx, 'y');
    input_array(z, nz, 'z');
    input_array(q, nq, 'q');
    
    // Обчислення A, B, C, D
    double A = calculate_sum(x, na, y, nx, sin, cos);
    double B = calculate_sum(y, nx, z, nz, cos, sin);
    double C = calculate_sum(z, nz, z, nz, sin, sin); // Друга сума також sin(y), але ми передаємо z
    double D = calculate_D(q, nq, cos, cos);
    
    // Виведення результатів
    printf("\nРезультати обчислень:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    
    // Звільнення пам'яті
    free(x);
    free(y);
    free(z);
    free(q);
    
    return 0;
}