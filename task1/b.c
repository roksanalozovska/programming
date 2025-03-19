#include <stdio.h>  
#include <math.h> 

int main() {
    int N;   
    printf("Введіть кількість чисел: "); 
    scanf("%d", &N);  
    
    int array[N], product = 1, count = 0;  
    printf("Введіть %d чисел: ", N); 
    for (int i = 0; i < N; i+=1) {  
        scanf("%d", &array[i]);   
        if (array[i] % 2 != 0) { 
            product *= array[i];  
            count++;  
        }
    } 
    printf("Добуток непарних чисел: %d\n", (count > 0 ? product : 0)); 
    if (count > 0) 
        printf("Середнє геометричне: %.2f\n", pow(product, 1.0 / count)); 
    else
        printf("Немає непарних чисел\n"); 
    return 0;  
}