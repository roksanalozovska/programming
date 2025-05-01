#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input_array(double arr[], int n, char name) {
    printf("Введіть %d елементів масиву %c:\n", n, name);
    for (int i = 0; i < n; i+=1) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}
double calculate_sum(double arr1[], int n1, double arr2[], int n2, 
                    double (*f1)(double), double (*f2)(double)) {
    double sum = 0.0;
    for (int i = 0; i < n1; i+=1) {
        sum += f1(arr1[i]);
    }
    for (int i = 0; i < n2; i+=1) {
        sum += f2(arr2[i]);
    }
    return sum;
}
double calculate_D(double q[], int n, double (*f1)(double), double (*f2)(double)) {
    double sum = 0.0;
    for (int i = 0; i < n; i+=1) {
        sum += f1(q[i]);
    }
    for (int i = 0; i < n; i+=1) {
        sum += f2(q[i]) * q[i] * q[i]; 
    }
    return sum;
}
int main() {
    int na, nx, nz, nq;
    printf("Введіть кількість елементів масиву x (nₐ): ");
    scanf("%d", &na);
    printf("Введіть кількість елементів масиву y (nₓ): ");
    scanf("%d", &nx);
    printf("Введіть кількість елементів масиву z (n₂): ");
    scanf("%d", &nz);
    printf("Введіть кількість елементів масиву q (n₀): ");
    scanf("%d", &nq);
    
    double *x = (double*)malloc(na * sizeof(double));
    double *y = (double*)malloc(nx * sizeof(double));
    double *z = (double*)malloc(nz * sizeof(double));
    double *q = (double*)malloc(nq * sizeof(double));

    input_array(x, na, 'x');
    input_array(y, nx, 'y');
    input_array(z, nz, 'z');
    input_array(q, nq, 'q');

    double A = calculate_sum(x, na, y, nx, sin, cos);
    double B = calculate_sum(y, nx, z, nz, cos, sin);
    double C = calculate_sum(z, nz, z, nz, sin, sin);
    double D = calculate_D(q, nq, cos, cos);

    printf("\nРезультати обчислень:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);

    free(x);
    free(y);
    free(z);
    free(q);
    
    return 0;
}