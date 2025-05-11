#include <stdio.h>
#include <conio.h>

#define N 10 

int main() {
    long arr[N];        
    long *pel, *pend, *pmax; 
    int k = 0;          
    printf("Введіть елементи\n");
    while (k < N) {
        scanf("%ld", arr + k);  
        if (*(arr + k) == 0)  
            break;
        k+=1;
    }
    pmax = arr;        
    pend = arr + k;    
    for (pel = arr + 1; pel < pend; pel+=1) {
        if (*pel > *pmax) { 
            pmax = pel;    
        }
    }
    printf("Найбільший елемент - %d, його значення - %ld\n", (int)(pmax - arr + 1), *pmax);
    getch();
    return 0;
}