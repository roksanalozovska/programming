#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main() {
    struct dog {
        char breed[30];  
        char name[30];   
        double weight;
    };
    int i, n; 
    FILE *pFile;
    pFile = fopen("dogs_data.dat", "w+");
    puts("Введіть кількість собак:");
    scanf("%i", &n);
    struct dog *dogs;
    dogs = (struct dog*)malloc(n * sizeof(struct dog));
    for(i = 0; i < n; i++) {
        printf("\nВведіть дані для собаки #%d\n", i+1);
        printf("Порода: ");
        fflush(stdin);
        scanf("%s", dogs[i].breed);
        printf("Кличка: ");
        fflush(stdin);
        scanf("%s", dogs[i].name);
        printf("Вага: ");
        scanf("%lf", &dogs[i].weight);
        fwrite(&dogs[i], sizeof(struct dog), 1, pFile);
    }
    rewind(pFile); 
    for(i = 0; i < n; i+=1) {
        fread(&dogs[i], sizeof(struct dog), 1, pFile);
        printf("\nСобака #%d: %s, порода %s, вага %.2f\n", 
               i+1, dogs[i].name, dogs[i].breed, dogs[i].weight);
        printf("Введіть нову вагу для %s: ", dogs[i].name);
        scanf("%lf", &dogs[i].weight);
        fseek(pFile, -(long)sizeof(struct dog), SEEK_CUR);
        fwrite(&dogs[i], sizeof(struct dog), 1, pFile);
        fseek(pFile, -(long)sizeof(struct dog), SEEK_CUR);
        fread(&dogs[i], sizeof(struct dog), 1, pFile);
        printf("Оновлені дані: %s, порода %s, нова вага %.2f\n", 
               dogs[i].name, dogs[i].breed, dogs[i].weight);
    }
    puts("\nРобота завершена!");
    fclose(pFile);
    free(dogs);
    getch();
    return 0;
}