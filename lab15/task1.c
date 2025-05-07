#include <stdio.h>
#include <conio.h>

int main() {
    float x, y;          // Оголошення змінних x та y (значення не ініціалізовані)
    float *x_ptr, *y_ptr; // Оголошення покажчиків на float (не ініціалізовані)

    x_ptr = &x;          // x_ptr тепер містить адресу змінної x
    *x_ptr = 5;          // Записуємо значення 5 у x через покажчик (x = 5)

    y_ptr = x_ptr;       // y_ptr тепер вказує на те саме, що й x_ptr (на x)
    y = *y_ptr / 2 + *x_ptr; // y = 5 / 2 + 5 = 2.5 + 5 = 7.5

    y_ptr = &y;          // y_ptr тепер вказує на y (адреса змінної y)

    // Виведення результатів:
    printf("x = %f, y = %f\n", x, y);           // x = 5.0, y = 7.5
    printf("Адреса x = %p, y = %p\n", &x, &y);  // Виводить адреси x та y
    printf("x_ptr = %p, y_ptr = %p\n", x_ptr, y_ptr); // Адреси, на які вказують покажчики
    printf("*x_ptr = %f, *y_ptr = %f\n", *x_ptr, *y_ptr); // Значення за адресами: 5.0 та 7.5
    printf("Адреса x_ptr = %p, y_ptr = %p\n", &x_ptr, &y_ptr); // Адреси самих покажчиків

    getch();
    return 0;
}