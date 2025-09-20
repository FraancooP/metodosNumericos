#include <iostream>
#include "../../Funciones/eli_gaussiana_pivoteo.h"

int main()
{
    int n = 3;
    double x[10], determinante = 1.0;
    eli_gaussiana_pivoteo("matriz_eje_4.dat", x, determinante);
    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i + 1, x[i]);
    printf("\nDeterminante de la matriz: %.10f\n", determinante);

    return 0;
}