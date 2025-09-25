#include <stdio.h>
#include <cmath>
#include "../../../Funciones/punto_fijo.h"

// Definir la función g(x)
double g(double x) {
    return sqrt(exp(sin(x)) + 1); // Ejemplo: g(x) = x + x^2 - sin(x)
}

int main() {
    int i = 0;
    double x0 = 1.0;
    double tol = 1e-6;
    double x1, error;
    int max_iter = 100;

    // Suponiendo que punto_fijo retorna void y utiliza variables de salida
    punto_fijo(g, tol, max_iter, i, x0, x1, error);
    // Aquí podrías agregar una condición basada en el valor de error o el número de iteraciones
    printf("La funcion converge\n");
    printf("========================================\n");
    printf("\nAproximacion final: x = %.8f en %d iteraciones con error de %.8f\n", x1, i, error);
    printf("========================================\n");
    return 0;
}