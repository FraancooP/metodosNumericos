#include <stdio.h>
#include <cmath>
#include "newton_raphson.h"

// Derivada numérica de f(x)
double f_prima(std::function<double(double)> f, double x, double h = 0.001) {
    return (f(x + h) - f(x)) / h;
}

void newton_raphson(std::function<double(double)> f, double tol, int max_iter, int& i, double& x0, double& x1, double& error) {
    printf("\nIter\t x1\t\t Error\t\t f'(x1)\n");
    printf("---------------------------------------------\n");

    do {
        double fp = f_prima(f, x0);
        if (fabs(fp) < 1e-4) {
            printf("Derivada muy pequeña (|f'(x)| < 1e-4). El método puede fallar.\n");
            exit(1);
        }
        x1 = x0 - f(x0) / fp;
        error = fabs(x1 - x0);
        printf("%d\t%.8f\t%.8f\t%.8f\n", i, x1, error, fp);
        x0 = x1;
        i++;
    } while (error > tol && i < max_iter);

    printf("\nAproximacion final: x = %.12f en %d iteraciones.\n", x1, i);
    printf("Valor de f(x) en la aproximacion: %.12f\n", f(x1));
    system("pause");
    printf("Presione una tecla para continuar....\n");
}