#include <stdio.h>
#include <math.h> 

struct Polynomial {
    double a; 
    double b; 
    double c; 
    double d; 
};

double calculate_polynomial(struct Polynomial poly, double x) {
    return poly.a * pow(x, 3) + poly.b * pow(x, 2) + poly.c * x + poly.d;
}
void input_polynomial(struct Polynomial *poly) {
    printf("Введіть коефіцієнти полінома 3-го ступеня (ax^3 + bx^2 + cx + d):\n");
    printf("a: ");
    scanf("%lf", &poly->a);
    printf("b: ");
    scanf("%lf", &poly->b);
    printf("c: ");
    scanf("%lf", &poly->c);
    printf("d: ");
    scanf("%lf", &poly->d);
}
int main() {
    struct Polynomial poly;
    double x, result;
    input_polynomial(&poly);
    printf("Введіть значення x для обчислення полінома: ");
    scanf("%lf", &x);
    result = calculate_polynomial(poly, x);
    printf("Значення полінома %.2fx^3 + %.2fx^2 + %.2fx + %.2f при x = %.2f: %.2f\n",
           poly.a, poly.b, poly.c, poly.d, x, result);
    
    return 0;
}