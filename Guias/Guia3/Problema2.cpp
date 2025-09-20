#include <iostream>
#include "../../Funciones/eli_gaussiana.h"

int main()
{
    int n = 4;
    double x[10], determinante = 1.0;
    eli_gaussiana("matriz_eje_2.dat", x, determinante);
    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10f\n", i + 1, x[i]);
    printf("\nDeterminante de la matriz: %.10f\n", determinante);

    return 0;
}