#include <stdio.h>
#define N 3  

int main() {
    float p[N][N], det;   
    int i, j;      
    printf("Введіть елементи матриці %dx%d:\n", N, N);
    for(i = 0; i < N; i+=1) {
        for(j = 0; j < N; j+=1) {
            printf("p[%d][%d] = ", i+1, j+1);
            scanf("%f", &p[i][j]);
        }
    }
    det = p[0][0] * (p[1][1]*p[2][2] - p[1][2]*p[2][1]) 
        - p[0][1] * (p[1][0]*p[2][2] - p[1][2]*p[2][0]) 
        + p[0][2] * (p[1][0]*p[2][1] - p[1][1]*p[2][0]);
    printf("\nВизначник матриці дорівнює: %.2f\n", det);
    return 0;
}