#include <stdio.h>
#include <cmath>

// Definir la función g(x)
double g(double x) {
    return sqrt(sin(sqrt(x))); // Ejemplo: g(x) = x + x^2 - sin(x)
}

// Derivada numérica de g(x) usando diferencia finita
double g_prima(double x, double h = 1e-6) {
    return (g(x + h) - g(x)) / h;
}

int main() {
    double x0;
    double tol = 1e-8;
    int max_iter = 100;
    printf("Ingrese x0: ");
    scanf("%lf", &x0);

    printf("\nIter\t x1\t\t Error\t\t g'(x1)\n");
    printf("---------------------------------------------\n");

    double x1, error;
    int i = 0;
    do {
        double gp = fabs(g_prima(x0));
        if (gp > 1.0) {
            printf("No converge: |g'(x0)| = %.6f > 1\n", gp);
            return 1;
        }
        x1 = g(x0);
        error = fabs(x1 - x0);
        printf("%d\t%.8f\t%.8f\t%.8f\n", i, x1, error, g_prima(x1));
        x0 = x1;
        i++;
    } while (error > tol && i < max_iter);

    printf("\nAproximacion final: x = %.8f en %d iteraciones.\n", x1, i);
    return 0;
}