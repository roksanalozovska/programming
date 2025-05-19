#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <conio.h>
#define N 5 

struct student {
    char surname[30];  
    char group[10];    
    int birth_year;   
    float avg_score;    
};

int main() {
    struct student students[N]; 
    int i, current_year;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_year = tm.tm_year + 1900; 

    printf("Введіть дані про %d студентів:\n", N);
    for (i = 0; i < N; i++) {
        printf("\nСтудент #%d\n", i+1);
        printf("Прізвище: ");
        scanf("%s", students[i].surname);
        printf("Група: ");
        scanf("%s", students[i].group);
        printf("Рік народження: ");
        scanf("%d", &students[i].birth_year);
        printf("Середній бал: ");
        scanf("%f", &students[i].avg_score);
    }
    printf("\nСтуденти старші 18 років:\n");
    printf("\n");
    printf("| Прізвище | Група | Рік народж. | Середній бал |\n");
    printf("\n");
    
    for (i = 0; i < N; i++) {
        if ((current_year - students[i].birth_year) > 18) {
            printf("| %-9s | %-6s | %-11d | %-12.2f |\n", 
                   students[i].surname, 
                   students[i].group, 
                   students[i].birth_year, 
                   students[i].avg_score);
        }
    }
    printf("\n");
    getch();
    return 0;
}