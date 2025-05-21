#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main() {
    struct dog {
        char breed[30];  // порода
        char name[30];   // кличка
        double weight;   // вага
    };
    
    int i, n; // n - кількість собак
    FILE *pFile;
    
    // Відкриваємо файл для читання та запису
    pFile = fopen("dogs_data.dat", "w+");
    
    // Запитуємо кількість собак
    puts("Введіть кількість собак:");
    scanf("%i", &n);
    
    // Виділяємо пам'ять для масиву структур
    struct dog *dogs;
    dogs = (struct dog*)malloc(n * sizeof(struct dog));
    
    // Вводимо дані про собак та записуємо їх у файл
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
        
        // Записуємо структуру у файл
        fwrite(&dogs[i], sizeof(struct dog), 1, pFile);
    }
    
    rewind(pFile); // Повертаємося на початок файлу
    
    // Читаємо дані з файлу, оновлюємо вагу та зберігаємо зміни
    for(i = 0; i < n; i++) {
        // Читаємо запис про собаку
        fread(&dogs[i], sizeof(struct dog), 1, pFile);
        
        // Виводимо поточні дані
        printf("\nСобака #%d: %s, порода %s, вага %.2f\n", 
               i+1, dogs[i].name, dogs[i].breed, dogs[i].weight);
        
        // Запитуємо нову вагу
        printf("Введіть нову вагу для %s: ", dogs[i].name);
        scanf("%lf", &dogs[i].weight);
        
        // Переміщаємося назад на один запис
        fseek(pFile, -(long)sizeof(struct dog), SEEK_CUR);
        
        // Записуємо оновлені дані
        fwrite(&dogs[i], sizeof(struct dog), 1, pFile);
        
        // Переміщаємося назад для перевірки
        fseek(pFile, -(long)sizeof(struct dog), SEEK_CUR);
        
        // Читаємо оновлені дані для перевірки
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