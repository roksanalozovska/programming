#include <stdio.h>

int main() {
    int N, i;
    float sum = 0;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);
    float array[N];
    printf("Введіть %d елементів масиву:\n", N);
    for (i = 0; i < N; i+=1) {
        scanf("%f", &array[i]);
        if (i % 2 == 1) {
            sum += array[i];
        }
    }
    printf("Сума елементів з непарними індексами: %.2f\n", sum); 
    return 0;
}