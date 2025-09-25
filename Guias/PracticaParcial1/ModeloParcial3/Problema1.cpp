#include <iostream>
#include <cmath>
#include <stdio.h>
#include "../../../Funciones/regula_false.h"


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
    a = 1.0;
    b = 2.0;
    raiz = 0.0;
    iteraciones = 0;
    regula_falsi(f, a, b, 1e-5, 1000, raiz, iteraciones);
    iteraciones_totales[1] = iteraciones;
    printf("\n=============== RESULTADOS FINALES ===============\n");
    printf("Utilizando los metodos numericos: \n");
    printf("METODO REGULA FALSI -> Raiz: %.10lf, Iteraciones: %d\n", raiz, iteraciones_totales[1]);

    return 0;
}
double f(double x)
{
    return log(pow(x,2) + 1.0) - sin(x);
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
