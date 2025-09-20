#include <iostream>
#include "../../Funciones/eli_gaussiana_pivoteo.h"

int main()
{
    int n = 4;
    double c[10], determinante = 1.0;
    printf("Resolviendo el sistema sin modificar:\n");
    eli_gaussiana_pivoteo("matriz_eje_51.dat", c, determinante);
    printf("A11 = 20514\n");
    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
        printf("c[%d] = %.10f\n", i + 1, c[i]);
    printf("\nDeterminante de la matriz: %.10f\n", determinante);
    c[10] = {0}; // Reiniciar el arreglo c
    determinante = 1.0; // Reiniciar el determinante
    n = 4;
    printf("Resolviendo el sistema modificado:\n");
    printf("A11 = 20515\n");
    eli_gaussiana_pivoteo("matriz_eje_52.dat", c, determinante);
    printf("\nSolucion del sistema:\n");
    for (int i = 0; i < n; i++)
        printf("c[%d] = %.10f\n", i + 1, c[i]);
    printf("\nDeterminante de la matriz: %.10f\n", determinante);


    return 0;
}