#include <stdio.h>
#include <conio.h>

#define N 15

int main() {
    int X[N] = {12, 5, 8, 19, 3, 7, 14, 2, 9, 11, 6, 15, 4, 10, 1};
    int A, i, j, tmp, max_index, flag, left, right, middle;
    
    printf("Початковий масив:\n");
    for(i = 0; i < N; i+=1) {
        printf("%d ", X[i]);
    }
    printf("\n");
    
    printf("Введіть цільовий елемент A: ");
    scanf("%d", &A);
    
    flag = 0;
    for(i = 0; i < N; i+=1) {
        if(X[i] == A) {
            printf("Лінійний пошук: знайдено на позиції %d\n", i);
            flag = 1;
            break;
        }
    }
    if(!flag) {
        printf("Лінійний пошук: елемент не знайдено\n");
    }
    
    for(i = 0; i < N-1; i+=1) {
        max_index = i;
        for(j = i+1; j < N; j+=1) {
            if(X[j] > X[max_index]) {
                max_index = j;
            }
        }
        tmp = X[i];
        X[i] = X[max_index];
        X[max_index] = tmp;
    }
    
    printf("Відсортований масив (за спаданням):\n");
    for(i = 0; i < N; i+=1) {
        printf("%d ", X[i]);
    }
    printf("\n");
    
    left = 0;
    right = N-1;
    flag = 0;
    
    while(left <= right) {
        middle = (left + right) / 2;
        
        if(X[middle] == A) {
            printf("Бінарний пошук: знайдено на позиції %d\n", middle);
            flag = 1;
            break;
        }
        else if(X[middle] < A) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    if(!flag) {
        printf("Бінарний пошук: елемент не знайдено\n");
    }
    
    getch();
    return 0;
}
