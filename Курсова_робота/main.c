#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct {
    double T;       
    double dt;      
    double epsilon; 
    double v0;      
    double F;       
    double A;       
    double k;       
    double d;       
} Vibrogranulator;

double calculateV(double v0, double k, double T, double t) {
    return v0 * (1 + k * cos(2 * M_PI * t / T));
}

double calculateF(double F, double A, double T, double t) {
    if (t >= 0 && t <= T/4) {
        return F + (4*A/T) * t;
    } else if (t > T/4 && t <= 3*T/4) {
        return F + A - (t - T/4) * (4*A/T);
    } else {
        return F - A + (t - 3*T/4) * (4*A/T);
    }
}

double calculateDk(double v, double d, double epsilon, double f) {
    return pow(3 * pow(d, 2) * epsilon * v / f, 1.0/3.0);
}

int main() {
    
    Vibrogranulator devices[3] = {
        {600, 20, 0.6, 2.5, 1000, 250, 0.8, 0.5}, 
        {600, 20, 0.6, 2.5, 2000, 300, 0.75, 1.0},  
        {600, 20, 0.6, 2.5, 500, 50, 0.85, 2.0}     
    };

    FILE *outFile = fopen("results.txt", "w");
    if (!outFile) {
        fprintf(stderr, "Не вдалося відкрити файл для запису результатів!\n");
        return 1;
    }

    fprintf(outFile, "Результати обчислень для віброгрануляторів:\n\n");

    for (int i = 0; i < 3; i+=1) {
        Vibrogranulator device = devices[i];

        if (device.k < 0 || device.k > 1) {
            fprintf(stderr, "Помилка: коефіцієнт k повинен бути в діапазоні [0,1] для пристрою %d\n", i+1);
            continue;
        }
        fprintf(outFile, "Варіант %d:\n", i+1);
        fprintf(outFile, "T = %.1f с, Δt = %.1f с, ε = %.1f\n", device.T, device.dt, device.epsilon);
        fprintf(outFile, "v0 = %.1f м/с, F = %.1f Гц, A = %.1f Гц\n", device.v0, device.F, device.A);
        fprintf(outFile, "k = %.2f, d = %.1f мм\n\n", device.k, device.d);
        fprintf(outFile, "Час (с)\t\tv(t) (м/с)\tf(t) (Гц)\tdk(t) (мм)\n");
        fprintf(outFile, "------------------------------------------------\n");
        
        for (double t = 0; t <= device.T; t += device.dt) {
            double v = calculateV(device.v0, device.k, device.T, t);
            double f = calculateF(device.F, device.A, device.T, t);
            double dk = calculateDk(v, device.d, device.epsilon, f);
            
            fprintf(outFile, "%.1f\t\t%.4f\t\t%.1f\t\t%.4f\n", t, v, f, dk);
        }
        fprintf(outFile, "\n\n");
    }
    fclose(outFile);
    printf("Обчислення завершено. Результати записано у файл results.txt\n");
    return 0;
}