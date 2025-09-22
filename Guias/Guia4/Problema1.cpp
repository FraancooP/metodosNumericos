#include "../../Funciones/gauss_seidel.h"
#include "../../Funciones/jacobi.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    double x[20], error[1000];
    int iter = 0;
    double tol = 1e-8;
    int max_iter = 1000;
    double lambda = 1.0; // Valor de lambda para relajación (1.0 = sin relajación)

    printf("Resolviendo el primer sistema usando el metodo de jacobi: ");
    system("pause");
    printf("Presione una tecla para continuar...\n");
    int n = jacobi("matriz_problema1.dat", x, error, &iter, tol, max_iter);
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    printf("Error final: %.10f\n", error[iter-1]);
    system("pause");
    printf("Presione una tecla para continuar...\n");
    printf("Resolviendo el sistema usando el método de Gauss-Seidel con relajación...\n");
    system("pause");
    printf("Presione una tecla para continuar...\n");
    int n = gauss_seidel("matriz_problema1.dat", x, error, &iter, tol, max_iter, &lambda);
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    printf("Error final: %.10f\n", error[iter-1]);
    system("pause");
    printf("Presione una tecla para continuar...\n");

    return 0;
}