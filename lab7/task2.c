#include <stdio.h>
#include <math.h>
#define N 3 

int main() {
    double points[N][2];  
    double x1, y1, x2, y2, y;
    for (int i = 0; i < N; i+=1) {
        printf("Введіть x та y для точки %d: ", i + 1);
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }
    for (int i = 0; i < N - 1; i+=1) {
        x1 = points[i][0];
        y1 = points[i][1];
        x2 = points[i + 1][0];
        y2 = points[i + 1][1];
        #include "distance_formula.txt" 
        printf("Відстань між точкою %d і точкою %d: %lf\n", i + 1, i + 2, y);
    }
    return 0;
}