#include <stdio.h>
#include <math.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);

int main() {
    double (*func_ptr[5])(double, double) = {
        add, subtract, multiply, divide, power
    };
    double x = 10.0, y = 3.0;
    const char* func_names[] = {
        "Додавання", "Віднімання", "Множення", "Ділення", "Степінь"
    };
    printf("Результати операцій для x=%.2f, y=%.2f:\n", x, y);
    printf("\n");

    for (int i = 0; i < 5; i+=1) {
        double result = func_ptr[i](x, y);
        printf("%s: %.2f\n", func_names[i], result);
    }
    
    return 0;
}
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    if (b == 0) {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
    return a / b;
}
double power(double a, double b) {
    return pow(a, b);
}