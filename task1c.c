#include <stdio.h>  

int main() {
    int N;  
    printf("Введіть кількість чисел: "); 
    scanf("%d", &N); 
    int array[N]; 
    int max, number; 
    printf("Введіть %d чисел: ", N); 
    for (int i = 0; i < N; i+=1) {  
        scanf("%d", &array[i]);  
        if (i == 0 || array[i] > max) {  
            max = array[i];  
            number = i;  
        }
    } 
    printf("Максимальне значення: %d\n", max); 
    printf("Його номер у списку: %d\n", number + 1); 
    return 0;  
}
