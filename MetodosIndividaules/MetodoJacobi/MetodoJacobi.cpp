#include <stdio.h>
#include <math.h>

int main() {
    int n, max_iter = 1000;
    double tol = 1e-8;

    printf("Ingrese el tamaño del sistema (n): ");
    scanf("%d", &n);

    double A[n][n], b[n], x[n], x_old[n];

    // Ingreso de la matriz de coeficientes
    printf("Ingrese la matriz de coeficientes A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }

    // Ingreso del vector de términos independientes
    printf("Ingrese el vector b:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i+1);
        scanf("%lf", &b[i]);
    }

    // Ingreso del vector inicial
    printf("Ingrese el vector inicial x0:\n");
    for (int i = 0; i < n; i++) {
        printf("x0[%d]: ", i+1);
        scanf("%lf", &x[i]);
    }

    int iter = 0;
    double error;
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
        error = 0.0;
        for (int i = 0; i < n; i++) {
            double e = fabs(x[i] - x_old[i]);
            if (e > error)
                error = e;
        }
        printf("%d\t%.10f\n", iter+1, error);
        iter++;
    } while (error > tol && iter < max_iter);

    printf("\nSolucion aproximada:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);

    return 0;
}