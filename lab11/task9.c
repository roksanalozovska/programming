#include <stdio.h>

#define M 20
#define N 20

void vvod(float mat[][M], int rows, int cols, char name);
int count_zeros(float mat[][M], int rows, int cols);

int main()
{
    int n, m;
    float a[N][M], b[M][N];
    int zeros_a, zeros_b;
    
    printf("Введіть розміри матриць (n < 20, m < 20): ");
    scanf("%d %d", &n, &m);
    
    printf("Введіть матрицю a(%d,%d):\n", n, m);
    vvod(a, n, m, 'a');
    zeros_a = count_zeros(a, n, m);
    
    printf("Введіть матрицю b(%d,%d):\n", m, n);
    vvod(b, m, n, 'b');
    zeros_b = count_zeros(b, m, n);
    
    printf("Кількість нулів у матриці a: %d\n", zeros_a);
    printf("Кількість нулів у матриці b: %d\n", zeros_b);
    
    return 0;
}

void vvod(float mat[][M], int rows, int cols, char name)
{
    int i, j;
    for(i = 0; i < rows; i+=1)
    {
        for(j = 0; j < cols; j+=1)
        {
            printf("Введіть %c[%d][%d] = ", name, i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
}

int count_zeros(float mat[][M], int rows, int cols)
{
    int i, j, count = 0;
    for(i = 0; i < rows; i+=1)
    {
        for(j = 0; j < cols; j+=1)
        {
            if(mat[i][j] == 0)
                count++;
        }
    }
    return count;
}