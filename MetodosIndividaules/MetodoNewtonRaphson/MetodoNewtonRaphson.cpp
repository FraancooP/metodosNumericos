#include <stdio.h>
#include <cmath>

// Definir la función f(x)
double f(double x) {
    return pow(x, 3) - x - 2;
}

// Derivada numérica de f(x)
double f_prima(double x, double h = 0.001) {
    return (f(x + h) - f(x)) / h;
}

int main() {
    double x0, x1, error;
    int i = 0;
    int max_iter = 10000;
    double tol = 1e-8;

    printf("Ingrese x0: ");
    scanf("%lf", &x0);

    printf("\nIter\t x1\t\t Error\t\t f'(x1)\n");
    printf("---------------------------------------------\n");

    do {
        double fp = f_prima(x0);
        if (fabs(fp) < 1e-4) {
            printf("Derivada muy pequeña (|f'(x)| < 1e-4). El método puede fallar.\n");
            break;
        }
        x1 = x0 - f(x0) / fp;
        error = fabs(x1 - x0);
        printf("%d\t%.8f\t%.8f\t%.8f\n", i, x1, error, fp);
        x0 = x1;
        i++;
    } while (error > tol && i < max_iter);

    printf("\nAproximacion final: x = %.12f en %d iteraciones.\n", x1, i);
    printf("Valor de f(x) en la aproximacion: %.12f\n", f(x1));
    return 0;
}