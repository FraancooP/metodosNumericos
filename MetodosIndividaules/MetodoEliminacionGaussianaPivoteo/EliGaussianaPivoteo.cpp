#include <stdio.h>
#include <cmath>

int main() {

    int n = 3;
    double A[3][3] = {
        {2, 1, -1},
        {4, 2, 3},
        {-2, 1, 2}
    };
    double b[3] = {1, 11, -1};
    double x[3];

    // Eliminación hacia adelante con pivoteo parcial
    for (int k = 0; k < n-1; k++) {
        // Pivoteo parcial: buscar el mayor valor absoluto en la columna k
        int max_row = k;
        double max_val = fabs(A[k][k]);
        for (int i = k+1; i < n; i++) {
            if (fabs(A[i][k]) > max_val) {
                max_val = fabs(A[i][k]);
                max_row = i;
            }
        }
        // Intercambiar filas si es necesario
        if (max_row != k) {
            for (int j = 0; j < n; j++) {
                double temp = A[k][j];
                A[k][j] = A[max_row][j];
                A[max_row][j] = temp;
            }
            double temp = b[k];
            b[k] = b[max_row];
            b[max_row] = temp;
        }

        // Eliminación
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