#include <stdio.h>
#include <cmath>
#include "punto_fijo.h"


using namespace std;
// Definir la función g(x)

// Derivada numérica de g(x) usando diferencia finita
double g_prima(std::function<double(double)> g, double x, double h = 1e-6) {
    return (g(x + h) - g(x)) / h;
}


// Prototipo de la funcion verificarIntervalo
void punto_fijo(std::function<double(double)> g, double tol, int max_iter, int& i, double& x0, double& x1, double& error){
    printf("\nIter\t x1\t\t Error\t\t g'(x1)\n");
    printf("---------------------------------------------\n");
    do {
        double gp = fabs(g_prima(g, x0));
        if (gp > 1.0) {
            printf("No converge: |g'(x0)| = %.6f > 1\n", gp);
            exit(1);
        }
        x1 = g(x0);
        error = fabs(x1 - x0);
        printf("%d\t%.8f\t%.8f\t%.8f\n", i, x1, error, g_prima(g, x1));
        x0 = x1;
        i++;
    } while (error > tol && i < max_iter);

    printf("\nAproximacion final: x = %.8f en %d iteraciones.\n", x1, i);
    system("pause");
    printf("Presione una tecla para continuar....\n");
}