#include <stdlib.h>
#include <stdio.h>

void input_array(int **array, int n);

int main() {
    int **array, i, j, n;
    int sum = 0, count = 0;
    printf("Введіть розмір масиву n: ");
    scanf("%d", &n);
    array = (int**)malloc(n * sizeof(int*));
    if (array == NULL) {
        printf("Не вдалося виділити пам'ять\n");
        return 1;
    }
    for (i = 0; i < n; i+=1) {
        array[i] = (int*)malloc(n * sizeof(int));
        if (array[i] == NULL) {
            printf("Не вдалося виділити пам'ять\n");
            return 2;
        }
    }
    printf("Введіть елементи масиву:\n");
    input_array(array, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (array[i][j] >= 0) {
                sum += array[i][j];
                count++;
            }
        }
    }
    printf("\nСума невід'ємних елементів: %d\n", sum);
    printf("Кількість невід'ємних елементів: %d\n", count);
    for (i = 0; i < n; i+=1) {
        free(array[i]);
    }
    free(array);
    return 0;
}
void input_array(int **array, int n) {
    int i, j;
    for (i = 0; i < n; i+=1) {
        for (j = 0; j < n; j+=1) {
            scanf("%d", &array[i][j]);
        }
    }
}