#include <stdio.h>
#include <math.h>

float calculateX(float a, float b) {
    if (a >= b) {
        return log(a * a + b * b + 2);
    } else {
        return (a * a - a * b) / (cos(a) + 1);
    }
}
int main() {
    float a_min, a_max, delta_a, b;
    printf("Введіть мінімальне значення a_min: ");
    scanf("%f", &a_min);
    printf("Введіть максимальне значення a_max, має бути >= a_min): ");
    scanf("%f", &a_max);
    printf("Введіть крок Δa, має бути > 0: ");
    scanf("%f", &delta_a);
    printf("Введіть значення b: ");
    scanf("%f", &b);

    printf("\nРезультати обчислень:\n");
    printf("a\tX\n");
    for (float a = a_min; a <= a_max; a += delta_a) {
        float x = calculateX(a, b);
        printf("%.2f\t%.2f\n", a, x);
    }
    return 0;
}