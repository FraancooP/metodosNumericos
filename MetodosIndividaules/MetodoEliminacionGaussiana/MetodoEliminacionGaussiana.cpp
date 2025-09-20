#include <stdio.h>
#include <cmath>

int main() {
    int n = 4;
    double A[4][4] = {
        {4, -1, 2, 3},
        {0, -2, 7, -4},
        {0, 0, 6, 5},
        {0, 0, 0, 3}
    };
    double b[4] = {20, -7, 4, 6};
    double x[4];

    // Eliminación hacia adelante
    for (int k = 0; k < n-1; k++) {
        for (int i = k+1; i < n; i++) {
            if (fabs(A[k][k]) < 1e-12) {
                printf("Error: pivote cero o muy pequeño en la fila %d\n", k+1);
                return 1;
            }
            double m = A[i][k] / A[k][k];
            for (int j = k; j < n; j++)
                A[i][j] -= m * A[k][j];
            b[i] -= m * b[k];
        }
    }

    double determinante = 1.0;
    for (int i = 0; i < n; i++) {
        determinante *= A[i][i];
    }


    // Sustitución hacia atrás
    for (int i = n-1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i+1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        if (fabs(A[i][i]) < 1e-12) {
            printf("Error: pivote cero o muy pequeño en la fila %d\n", i+1);
            return 1;
        }
        x[i] /= A[i][i];
    }

    // Mostrar la solución
    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i+1, x[i]);

    // Mostrar el determinante
    printf("\nDeterminante de la matriz: %.10f\n", determinante);

    return 0;
}