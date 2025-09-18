#include <stdio.h>
#include <cmath>

// Definir la función f(x)
double f(double x) {
    return pow(x, 3) - x - 2;
}

int main() {
    double x0, x1, x2, error;
    int i = 0;
    int max_iter = 10000;
    double tol = 1e-8;

    printf("Ingrese x0: ");
    scanf("%lf", &x0);
    printf("Ingrese x1: ");
    scanf("%lf", &x1);

    printf("\nIter\t x2\t\t Error\t\t f(x2)\n");
    printf("---------------------------------------------\n");

    do {
        double fx0 = f(x0);
        double fx1 = f(x1);
        if (fabs(fx1 - fx0) < 1e-12) {
            printf("División por cero en la fórmula de la secante. El método puede fallar.\n");
            break;
        }
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        error = fabs(x2 - x1);
        printf("%d\t%.8f\t%.8f\t%.8f\n", i, x2, error, f(x2));
        x0 = x1;
        x1 = x2;
        i++;
    } while (error > tol && i < max_iter);

    printf("\nAproximacion final: x = %.12f en %d iteraciones.\n", x2, i);
    printf("Valor de f(x) en la aproximacion: %.12f\n", f(x2));
    return 0;
}