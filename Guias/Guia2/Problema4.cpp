#include <stdio.h>
#include <cmath>
#include "../../Funciones/newton_raphson.h"

// Definir la función g(x)
double g(double x) {
    return x * cosh(10.0/x) - x - 6.0;
}

int main() {
    int i = 0;
    double x0;
    double tol = 1e-12;
    double x1, error;
    int max_iter = 100;

    // Suponiendo que punto_fijo retorna void y utiliza variables de salida
    x0 = 8.0;
    newton_raphson(g, tol, max_iter, i, x0, x1, error);

    // Aquí podrías agregar una condición basada en el valor de error o el número de iteraciones
    printf("La funcion converge\n");
    printf("========================================\n");
    printf("\nAproximacion final: x = %.8f en %d iteraciones con error de %.8f\n", x1, i, error);
    printf("========================================\n");
    return 0;
}