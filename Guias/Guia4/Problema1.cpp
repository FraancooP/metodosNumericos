#include "../../Funciones/gauss_seidel.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    double x[20], error[1000];
    int iter = 0;
    double tol = 1e-8;
    int max_iter = 1000;

    //printf("Metodo de Jacobi:\n");
    //int n = jacobi("matriz_problema1.dat", x, error, &iter, tol, max_iter);
    //printf("\nSolucion aproximada:\n");
    //for (int i = 0; i < n; i++)
    //    printf("x[%d] = %.10f\n", i+1, x[i]);
    //printf("Error final: %.10f\n", error[iter-1]);


    printf("Metodo de Gauss-Seidel:\n");
    int nn = gauss_seidel("matriz_problema12.dat", x, error, &iter, tol, max_iter);
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < nn; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    printf("Error final: %.10f\n", error[iter-1]);

    return 0;
}