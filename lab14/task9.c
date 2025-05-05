#include <stdio.h>

int main() {
    char str[] = "Лабораторна робота №14. Виконую 9 варіант";
    char result[100]; 
    int i = 0;
    while (str[i] != '.' && str[i] != '\0') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0'; 
    printf("Підрядок до першої крапки: %s\n", result);
    return 0;
}
