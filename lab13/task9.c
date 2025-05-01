#include <stdio.h>
#include <conio.h>

double calculate_sum(int n, double x, int current);
int main() {
    int n;
    double x, s;
    printf("Введіть n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%lf", &x);

    s = calculate_sum(n, x, 1);
    printf("Сума s = %.2f", s);
    getch();
    return 0;
}
double calculate_sum(int n, double x, int current) {
    if (current > n) {
        return 0; 
    } else {
        double term = (n * x) / (current + x); 
        return term + calculate_sum(n, x, current + 1);
    }
}