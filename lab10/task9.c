#include <stdio.h>
#include <math.h>

#define Nx 5
#define Ny 6
#define Nz 4

void vvod(float x[], int n, char q);
void analiz(float x[], int n, float limit, float *sum, float *geom_avg);

int main() {
    float x[Nx], y[Ny], z[Nz];
    float sum, geom_avg, limit;

    printf("Введіть максимальне значення для фільтрації елементів: ");
    scanf("%f", &limit);

    vvod(x, Nx, 'x');
    analiz(x, Nx, limit, &sum, &geom_avg);
    printf("Для x: сума = %.2f, середнє геометричне = %.2f\n", sum, geom_avg);

    vvod(y, Ny, 'y');
    analiz(y, Ny, limit, &sum, &geom_avg);
    printf("Для y: сума = %.2f, середнє геометричне = %.2f\n", sum, geom_avg);

    vvod(z, Nz, 'z');
    analiz(z, Nz, limit, &sum, &geom_avg);
    printf("Для z: сума = %.2f, середнє геометричне = %.2f\n", sum, geom_avg);

    return 0;
}

void vvod(float x[], int n, char q) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Введіть %c[%d]: ", q, i + 1);
        scanf("%f", &x[i]);
    }
}

void analiz(float x[], int n, float limit, float *sum, float *geom_avg) {
    int i, count = 0;
    float product = 1.0;
    *sum = 0;

    for (i = 0; i < n; i+=1) {
        if (x[i] > 0 && x[i] < limit) {
            *sum += x[i];
            product *= x[i];
            count++;
        }
    }

    if (count > 0) {
        *geom_avg = pow(product, 1.0 / count);
    } else {
        *geom_avg = 0; 
    }
}
