#include "../../Funciones/gauss_seidel_resuido.h"
#include "../../Funciones/jacobi_resuido.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    double x[20], error[1000];
    int iter = 0;
    double tol = 1e-11;
    int max_iter = 1000;
    int n;

    printf("Metodo de Jacobi:\n");
    n = jacobi_resuido("matriz_problema21.dat", x, error, &iter, tol, max_iter);
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    printf("Error final: %.10f\n", error[iter-1]);
    printf("Numero de iteraciones: %d\n", iter);
    printf("Metodo de Gauss-Seidel:\n");
    x[20], error[1000];
    iter = 0;
    n = gauss_seidel_resuido("matriz_problema21.dat", x, error, &iter, tol, max_iter);
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    printf("Error final: %.10f\n", error[iter-1]);
    printf("Numero de iteraciones: %d\n", iter);

    return 0;
}