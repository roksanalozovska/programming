#include <stdio.h> 
int main() {
    int N;   
    printf("Введіть кількість чисел: "); 
    scanf("%d", &N);  
    int array[N], sum = 0, count = 0;     
    printf("Введіть %d чисел: ", N); 
    for (int i = 0; i < N; i+=1) {  
        scanf("%d", &array[i]);  
        if (array[i] % 2 == 0) {  
            sum += array[i];  
            count++;  
        }
    } 
    printf("Сума парних чисел: %d\n", sum); 
    if (count > 0) 
        printf("Середнє арифметичне: %.2f\n", (double)sum / count); 
    else
        printf("Немає парних чисел\n"); 
    return 0;  
