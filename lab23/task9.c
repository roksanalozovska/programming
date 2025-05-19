#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 5  

struct dog {
    char breed[30]; 
    char name[20];  
    float weight;   
};
int main() {
    struct dog dogs[N]; 
    char target_breed[30]; 
    int i;
    FILE *output_file;

    printf("Введіть дані про %d собак:\n", N);
    for (i = 0; i < N; i+=1) {
        printf("\nСобака #%d:\n", i+1);
        printf("Порода: ");
        scanf("%s", dogs[i].breed);
        printf("Кличка: ");
        scanf("%s", dogs[i].name);
        printf("Вага (кг): ");
        scanf("%f", &dogs[i].weight);
    }
    printf("\nВведіть породу для пошуку: ");
    scanf("%s", target_breed);
    output_file = fopen("dogs_output.txt", "w");
    if (output_file == NULL) {
        printf("Помилка відкриття файлу для запису!\n");
        return 1;
    }
    fprintf(output_file, "Собаки породи '%s':\n", target_breed);
    fprintf(output_file, "\n");
    printf("\nСобаки породи '%s':\n", target_breed);
    printf("\n");
    
    int found = 0; 
    
    for (i = 0; i < N; i+=1) {
        if (strcmp(dogs[i].breed, target_breed) == 0) {
            found = 1;
            printf("Порода: %s\n", dogs[i].breed);
            printf("Кличка: %s\n", dogs[i].name);
            printf("Вага: %.1f кг\n\n", dogs[i].weight);
            fprintf(output_file, "Порода: %s\n", dogs[i].breed);
            fprintf(output_file, "Кличка: %s\n", dogs[i].name);
            fprintf(output_file, "Вага: %.1f кг\n\n", dogs[i].weight);
        }
    }
    if (!found) {
        printf("Собак породи '%s' не знайдено.\n", target_breed);
        fprintf(output_file, "Собак породи '%s' не знайдено.\n", target_breed);
    }
    fclose(output_file);
    printf("\nРезультати пошуку збережено у файлі 'dogs_output.txt'\n");
    getch();
    return 0;
}