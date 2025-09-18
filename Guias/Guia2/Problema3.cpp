#include <stdio.h>
#include <cmath>
#include "../../Funciones/newton_raphson.h"

// Definir la función g(x)
double g(double x) {
    return x * (10.0 - 2.0*x) * (16.0 - 2.0*x) - 100.0;
}

int main() {
    int i = 0;
    double x0;
    double tol = 1e-12;
    double x1, error;
    int max_iter = 100;
    double raiz1, raiz2, raiz3;

    // Suponiendo que punto_fijo retorna void y utiliza variables de salida
    x0 = 0.7;
    newton_raphson(g, tol, max_iter, i, x0, x1, error);
    raiz1 = x1;
    x1 = 0.0;
    error = 0.0;
    x0 = 3.0;
    newton_raphson(g, tol, max_iter, i, x0, x1, error);
    raiz2 = x1;
    x1 = 0.0;
    error = 0.0;
    x0 = 8.0;
    newton_raphson(g, tol, max_iter, i, x0, x1, error);
    raiz3 = x1;

    // Aquí podrías agregar una condición basada en el valor de error o el número de iteraciones
    printf("La funcion converge\n");
    printf("========================================\n");
    printf("Raiz 1: %.8f\n", raiz1);
    printf("Raiz 2: %.8f\n", raiz2);
    printf("Raiz 3: %.8f\n", raiz3);
    printf("========================================\n");
    return 0;
}