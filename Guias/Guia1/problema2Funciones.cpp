#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stack>
#include <fstream>
#include <vector>
#include <string>
#include "../../Funciones/biseccion.h"
#include "../../Funciones/regula_falsi.h"




using namespace std;

//Prototipo de funciones
double f(double x);
bool verificarIntervalo(double a, double b);

int main() {
	double a, b = 0.0;
    double raiz = 0.0;
    int iteraciones = 0;
    double raices[4] = {0.0};
    int iteraciones_totales[4] = {0};
    //Declaro pilas para guardar iteraciones y valor de la raiz.
	printf("Para la funcion g(a) = a^10 - 1\n");
	printf("La funcion posee 2 raizes en X.\n");
	printf("Intervalos: \n");
	printf("[-1.5 ; -0.5]\n");
	printf("[0.5 ; 1.5]\n");
	printf("Aplicando metodo de biseccion y regula falsi para la primera raiz.\n");
	a = -1.5;
	b = -0.5;
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
	printf("Aplicando metodo de biseccion y regula falsi para la segunda raiz.\n");
	a = 0.5;
	b = 1.5;
    biseccion(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[2] = raiz;
    iteraciones_totales[2] = iteraciones;
    raiz = 0.0;
    iteraciones = 0;
    regula_falsi(f, a, b, 1e-5, 1000, raiz, iteraciones);
    raices[3] = raiz;
    iteraciones_totales[3] = iteraciones;

	printf("===============Resultados finales===============\n");
    printf("Metodo: \t NroRaiz: \t RaizAproximada \t IteracionesTotales\n");
	printf("RegulaFalsi\t  2da\t\t %.10lf\t\t %d\n",raices[3],iteraciones_totales[3]);
	printf("Biseccion\t  2da\t\t %.10lf\t\t %d\n",raices[2],iteraciones_totales[2]);
	printf("RegulaFalsi\t  1era\t\t %.10lf\t\t %d\n",raices[1],iteraciones_totales[1]);
	printf("Biseccion\t  1era\t\t %.10lf\t\t %d\n",raices[0],iteraciones_totales[0]);

	return 0;
}
double f(double x){
	return pow(x , 10) - 1;
}
bool verificarIntervalo(double a, double b){
	if(f(a) * f(b) > 0){
		return false;
	}else{
		return true;
	}
}