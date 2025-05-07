#include <stdio.h>

int main() {
    int arr[10];       
    int *p, *pmax;      
    int i, n;           
    printf("n = ");    
    scanf("%d", &n);  
    printf("Input values for arr:\n");
    for (i = 0; i < n; i+=1) {
        scanf("%d", &arr[i]); 
    pmax = arr;        
    for (p = arr + 1; p < arr + n; p+=1) {
        if (*p > *pmax) {
            pmax = p;   
        }
    }
    printf("Max element = %d\n", *pmax); 
    printf("Its number = %d\n", pmax - arr + 1); 
    return 0;
}