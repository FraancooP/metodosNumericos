#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void eli_gaussiana_pivoteo(const char *filename, double x[], double &determinante)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        puts("No se puede abrir el archivo");
        exit(1);
    }

    int n;
    fscanf(fp, "%d", &n);

    double A[n][n], b[n];
    determinante = 1.0;
    // Leer la matriz A
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%lf", &A[i][j]);

    // Leer el vector b
    for (int i = 0; i < n; i++)
        fscanf(fp, "%lf", &b[i]);

    fclose(fp);
    printf("La matriz cargada desde el archivo es: \n");

    printf("\nMatriz aumentada (A | b):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%10.4f ", A[i][j]);
        printf("| %10.4f\n", b[i]);
    }
    printf("\n");
    // ... después de leer la matriz A ...
    double normaA = 0.0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            normaA += A[i][j] * A[i][j];
    normaA = sqrt(normaA);

    printf("Norma de la matriz A (||A||): %.10f\n", normaA);
    system("pause");
    printf("Presione una tecla para continuar...\n");

    // Eliminación hacia adelante con pivoteo parcial
    for (int k = 0; k < n - 1; k++)
    {
        // Pivoteo parcial: buscar el mayor valor absoluto en la columna k
        int max_row = k;
        double max_val = fabs(A[k][k]);
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(A[i][k]) > max_val)
            {
                max_val = fabs(A[i][k]);
                max_row = i;
            }
        }
        // Intercambiar filas si es necesario
        if (max_row != k)
        {
            for (int j = 0; j < n; j++)
            {
                double temp = A[k][j];
                A[k][j] = A[max_row][j];
                A[max_row][j] = temp;
            }
            double temp = b[k];
            b[k] = b[max_row];
            b[max_row] = temp;
        }

        // Eliminación
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(A[k][k]) < 1e-12)
            {
                printf("Error: pivote cero o muy pequeño en la fila %d\n", k + 1);
                exit(1);
            }
            double m = A[i][k] / A[k][k];
            for (int j = k; j < n; j++)
                A[i][j] -= m * A[k][j];
            b[i] -= m * b[k];
        }
    }

    for (int i = 0; i < n; i++)
    {
        determinante *= A[i][i];
    }

    // Sustitución hacia atrás
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        if (fabs(A[i][i]) < 1e-12)
        {
            printf("Error: pivote cero o muy pequeño en la fila %d\n", i + 1);
            exit(1);
        }
        x[i] /= A[i][i];
    }
}