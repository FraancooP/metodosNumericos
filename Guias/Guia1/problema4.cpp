#include <stdio.h>
#include <iostream>
#include <cmath>

/**
 * Queremos que nuestro erro sea menor igual a delta tal que: (b-a)/2^n <= delta
 * Si despejamos n de esta desigualdad tenemos
 * n >= log2((b-a)/delta)
 * Ademas, recordemos que en el metodo de biseccion, el error despues de n iteraciones esta acotado por:
 * |r-c| <= (b-a)/2^n
 * donde r = raiz real, c = aproximacion a la n-esima iteracion, [a,b] intervalo incial.
 * El objetivo es calcular primero n antes de ejecutar los metodos, con esto vamos a saber
 * cuantas iteraciones son necesarias para alcanzar la precision deseada.
 */
int main(int argc, char const *argv[])
{
    double a, b, delta;
    printf("Ingrese el intervalo [a,b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Ingrese el valor de delta: ");
    scanf("%lf", &delta);

    double n = log2((b - a) / delta);
    printf("Numero de bisecciones necesarias (real): %lf\n", n);
    printf("Numero de bisecciones necesarias (entero): %d\n", (int)ceil(n));
    return 0;
}
