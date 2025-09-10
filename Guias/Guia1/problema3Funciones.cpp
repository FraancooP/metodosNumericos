#include <iostream>
#include <cmath>
#include <stdio.h>
#include "../../Funciones/biseccion.h"
#include "../../Funciones/regula_falsi.h"
/*
CONCLUCIONES:
Para el final de este algoritmo, los resultados terminan en 2 iteraciones para regula falsi y
14 para el metodo de biseccion(depende la compu), se puede observar que para regula false, se aprovecha
la forma de la curva de la funcion, lo que permite una convergencia mas rapida hacia la raiz.
En cambio como el metodo de biseccion utiliza un enfoque mas conservador, requiere mas iteraciones para alcanzar 
la misma precision.
En resumen, conviene mucho mas utilizar regula falsi cuando se tienen funciones que su grafica termine
en una curva como la de este ejercicio.
*/
using namespace std;
//Prototipo de funciones
double f(double x);
bool verificarIntervalo(double a, double b);

int main() {
	double a, b, raiz = 0.0;
    int iteraciones = 0;
    double raices[2] = {0.0};
    int iteraciones_totales[2] = {0};
	a = 63.0;
	b = 64.0;
    biseccion(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[0] = raiz;
    iteraciones_totales[0] = iteraciones;
    raiz = 0.0;
    iteraciones = 0;
    regula_falsi(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[1] = raiz;
    iteraciones_totales[1] = iteraciones;
    raiz = 0.0;
    iteraciones = 0;

	printf("\n=============== RESULTADOS FINALES ===============\n");
    printf("Utilizando los metodos numericos, la masa (m) debe tener valer los siguientes resultados para cada metodo: \n");
	printf("METODO REGLA FALSI -> Raiz: %.10lf, Iteraciones: %d\n", raices[1], iteraciones_totales[1]);
	printf("METODO BISECCION -> Raiz: %.10lf, Iteraciones: %d\n", raices[0], iteraciones_totales[0]);

	return 0;
}
double f(double x){
	return (9.81*x / 14.0)*(1.0 - exp(-(14.0 / x) * 7.0)) - 35.0;
}
bool verificarIntervalo(double a, double b){
	if(f(a) * f(b) > 0){
		return false;
	}else{
		return true;
	}
}
