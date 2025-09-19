#include <stdio.h>
#include <cmath>
#include "../../Funciones/newton_raphson.h"

// Definir la función g(x)

double g1(double x) {
    return pow(x, 2)*(10.0 - x/3) - 850.6; // Ejemplo: g(x) = x + x^2 - sin(x)
}

int main() {
    int i = 0;
    double x0;
    double tol = 1e-12;
    double x1, error;
    int max_iter = 100;
    double raiz1, raiz2, raiz3, raiz4;

    // Suponiendo que punto_fijo retorna void y utiliza variables de salida
    x0 = -8.0;
    newton_raphson(g1, tol, max_iter, i, x0, x1, error);
    raiz1 = x1;
    x1 = 0.0;
    error = 0.0;
    x0 = 10.0;
    newton_raphson(g1, tol, max_iter, i, x0, x1, error);
    raiz2 = x1;
    x1 = 0.0;
    error = 0.0;
    x0 = 26.0;
    newton_raphson(g1, tol, max_iter, i, x0, x1, error);
    raiz3 = x1;


    // Aquí podrías agregar una condición basada en el valor de error o el número de iteraciones
    printf("La funcion converge\n");
    printf("========================================\n");
    printf("Raiz 1(+10): %.8f\n", raiz1);
    printf("Raiz 2(-10): %.8f\n", raiz2);
    printf("Raiz 3(+12): %.8f\n", raiz3);
    printf("========================================\n");
    return 0;
}