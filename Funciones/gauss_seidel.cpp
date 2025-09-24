#include <stdio.h>
#include <math.h>
#include <cmath>


int gauss_seidel(const char* filename, double x[], double error[], int* iter, double tol, int max_iter) {
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
        system("pause");
        printf("Presione una tecla para continuar...\n");
    }
    int iter_local = 0;
    double error_local;
    double errorViejo = 1e9;
    printf("\nIter\tError\n");
    do {
        for (int i = 0; i < n; i++)
            x_old[i] = x[i];
    
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
    
         // Calculo del error
        error_local = 0.0;
        for (int i = 0; i < n; i++) {
            error_local += pow(x[i] - x_old[i], 2);
        }
        error_local = sqrt(error_local);
    
        if (error_local > errorViejo) {
            printf("El error ha aumentado. El metodo no converge.\n");
            return 0;
        }
        errorViejo = error_local;
        printf("%d\t%.10f\n", iter_local+1, error_local);
        iter_local++;
    } while (error_local > tol && iter_local < max_iter);
    
    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);
    
    *iter = iter_local;

    
    system("pause");
    printf("Presione una tecla para continuar...\n");
    return 0;
}