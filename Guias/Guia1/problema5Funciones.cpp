#include <iostream>
#include <cmath>
#include <stdio.h>
#include "../../Funciones/biseccion.h"
#include "../../Funciones/regula_falsi.h"

/**
 * Planteo
 * Sabemos que con gamma = 5/3 y pidiendo eficiencia de 0.3.
 * T2/T1 = x (x < 1)
 *
 * entonces nuestra funcion de eficiencia se puede expresar como:
 * n(x) = (ln(x)-(1-1/x))/(ln(x) + (1-1/x)/(gamma-1))
 * y queremos n(0.3)
 * Por lo que definimos la funcion f(x) a buscar como n(x) - 0.3
 * Ahora, ¿Que intervalo usamos?
 * Como x = T2/T1 y T2 > T1, entonces sabemos que x > 1
 * Debemos valuar f(x) en valores mayores a 1 hasta encontrar el cambio de signo y luego
 * utilizar los metodos para encontrar la raiz dentro de ese intervalo
 *
 *
 */

using namespace std;

// Prototipo de funciones
double n(double x);
double f(double x);
bool verificarIntervalo(double a, double b);
int main()
{
    double a, b, raiz;
    double raices[2]={0.0};
    int iteraciones_totales[2]={0};    
    int iteraciones;
    a = 5.3;
    b = 5.5;
    biseccion(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[0] = raiz;
    iteraciones_totales[0] = iteraciones;
    raiz = 0.0;
    iteraciones = 0;
    regula_falsi(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[1] = raiz;
    iteraciones_totales[1] = iteraciones;
    printf("\n=============== RESULTADOS FINALES ===============\n");
    printf("Utilizando los metodos numericos: \n");
    printf("METODO REGLA FALSI -> Raiz: %.10lf, Iteraciones: %d\n", raices[1], iteraciones_totales[1]);
    printf("METODO BISECCION -> Raiz: %.10lf, Iteraciones: %d\n", raices[0], iteraciones_totales[0]);

    return 0;
}
double f(double x)
{
    return ((log(x) - (1.0 - 1.0 / x)) / (log(x) + ((1.0 - 1.0 / x) / (5.0 / 3.0 - 1.0)))) - 0.3;
}

bool verificarIntervalo(double a, double b)
{
    if (f(a) * f(b) > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
