#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "jacobi.h"

int jacobi(const char* filename, double x[], double error[], int* iter, double tol, int max_iter)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        puts("No se puede abrir el archivo");
        exit(1);
    }

    int n;
    fscanf(fp, "%d", &n);

    double A[n][n], b[n], x0[n], x_old[n];

    // Leer la matriz A
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%lf", &A[i][j]);

    // Leer el vector b
    for (int i = 0; i < n; i++)
        fscanf(fp, "%lf", &b[i]);

    // Leer el vector inicial x0
    for (int i = 0; i < n; i++)
        fscanf(fp, "%lf", &x0[i]);

    fclose(fp);

    printf("La matriz cargada desde el archivo es: \n");
    printf("\nMatriz aumentada (A | b):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%10.4f ", A[i][j]);
        printf("| %10.4f\n", b[i]);
    }

    printf("\nVector inicial x0:\n");
    for (int i = 0; i < n; i++)
        printf("x0[%d] = %.10f\n", i+1, x0[i]);
    printf("\n");

    // Chequeo de diagonal dominante
    int esDominante = 1;
    for (int i = 0; i < n; i++) {
        double suma = 0.0;
        for (int j = 0; j < n; j++) {
            if (j != i)
                suma += fabs(A[i][j]);
        }
        if (fabs(A[i][i]) < suma) {
            esDominante = 0;
            break;
        }
    }
    if (!esDominante) {
        printf("ADVERTENCIA: La matriz NO es diagonalmente dominante. El método puede no converger.\n");
        system("pause");
        printf("Presione una tecla para continuar...\n");
    }

    system("pause");
    printf("Presione una tecla para continuar...\n");

    // Inicializar x con x0
    for (int i = 0; i < n; i++)
        x[i] = x0[i];

    *iter = 0;
    double err = 0.0;

    printf("\nIter\tError\n");
    do {
        for (int i = 0; i < n; i++)
            x_old[i] = x[i];

        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * x_old[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Calcular el error como la norma infinita
        err = 0.0;
        for (int i = 0; i < n; i++) {
            double e = fabs(x[i] - x_old[i]);
            if (e > err)
                err = e;
        }
        error[*iter] = err;
        printf("%d\t%.10f\n", *iter+1, err);
        (*iter)++;
    } while (err > tol && *iter < max_iter);
    return n;
}