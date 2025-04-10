#include <stdio.h>
#define N 10

int main()
{
    float A[N][N];
    float sum[N];
    int size;
    int i, j;
    printf("Введіть розмір матриці (не більше %d): ", N);
    scanf("%d", &size); 
    printf("Введіть елементи матриці %dx%d:\n", size, size);
    for(i = 0; i < size; i+=1)
        for(j = 0; j < size; j+=1)
        {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    for(i = 0; i < size; i+=1)
    {
        sum[i] = 0;
        for(j = 0; j < size; j+=1)
            if(A[i][j] > 0)
             sum[i] += A[i][j];
    }
    printf("\nСума додатніх елементів:\n");
    for(i = 0; i < size; i+=1)
        printf("Рядок %d: %.2f\n", i+1, sum[i]);
    return 0;
}