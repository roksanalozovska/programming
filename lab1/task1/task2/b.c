#include <stdio.h>

int main() {
    int N, i;
    float sum = 0;
    int first = -1, last = -1;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);
    float array[N];
    printf("Введіть %d елементів масиву, де мінімум два від'ємних числа:\n", N);
    for (i = 0; i < N; i+=1) {
        scanf("%f", &array[i]);
        if (array[i] < 0) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first != -1 && last != -1 && first != last) {
        for (i = first + 1; i < last; i+=1) {
            sum += array[i];
        }
        printf("Сума елементів між першим і останнім від'ємними: %.2f\n", sum);
    } 
    return 0;
}
