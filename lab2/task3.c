#include <stdio.h>

int main() {
    int n, m = 0;
    printf("Введіть кількість елементів масивів X і Y: ");
    scanf("%d", &n);
    float X[n], Y[n], Z[n];
    printf("Введіть елементи масиву X:\n");
    for(int i = 0; i < n; i+=1) {
        scanf("%f", &X[i]);
    }
    printf("Введіть елементи масиву Y:\n");
    for(int i = 0; i < n; i) {
        scanf("%f", &Y[i]);
    }
    for(int i = 0; i < n; i+=1) {
        if(X[i] * Y[i] > X[n-1] * Y[n-1]) {
            Z[m] = X[i] * Y[i];
            m++;
        }
    }
    printf("Масив Z:\n");
    for(int i = 0; i < m; i+=1) {
        printf("%4.2f ", Z[i]);
    }
    printf("\n");
    if (m > 0) {
        float minZ = Z[0]; 
        for(int i = 1; i < m; i+=1) {
            if(Z[i] < minZ) {
                minZ = Z[i];
            }
        }
        printf("Найменший елемент масиву Z: %4.2f\n", minZ);
    } else {
        printf("Немає елементів для знаходження мінімуму.\n");
    }
    return 0;
}