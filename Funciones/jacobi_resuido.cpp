#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jacobi_resuido.h"

int jacobi_resuido(const char* filename, double x[], double error[], int* iter, double tol, int max_iter) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
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
    
    // Inicializar x con x0
    for (int i = 0; i < n; i++)
        x[i] = x0[i];
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
    }
    system("pause");
    printf("Presione una tecla para continuar...\n");

    // Inicializar x con x0
    for (int i = 0; i < n; i++)
        x[i] = x0[i];

    printf("\nIter\t||Ax - b||\n");

    int iter_local = 0;
    double error_local;

    do {
        for (int i = 0; i < n; i++)
            x_old[i] = x[i];

        // Iteración Jacobi
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * x_old[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Calcular residuo r = Ax - b
        double residuo[n];
        for (int i = 0; i < n; i++) {
            residuo[i] = 0.0;
            for (int j = 0; j < n; j++)
                residuo[i] += A[i][j] * x[j];
            residuo[i] -= b[i];
        }

        // Norma 2 del residuo
        error_local = 0.0;
        for (int i = 0; i < n; i++)
            error_local += residuo[i] * residuo[i];
        error_local = sqrt(error_local);

        printf("%d\t%.10f\n", iter_local+1, error_local);

        iter_local++;
    } while (error_local > tol && iter_local < max_iter);

    *iter = iter_local;
    system("pause");
    printf("Presione una tecla para continuar...\n");
    return n;
}
