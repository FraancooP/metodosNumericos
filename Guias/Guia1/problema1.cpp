#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//Prototipo de funciones
double f(double x);
bool verificarIntervalo(double a, double b);
int main() {
	double a, b, c, cviejo = 0.0;
	double error_funcion, error_absoluto, error_relativo, error_porcentual, error_intervalo;
	int i = 0;
	int max_iter = 1000;
	double tol = 1e-4;
	printf("Para la funcion f(x) = -2 + 7x - 5x^2 + 6x^3\n");
	printf("La funcion posee una raiz en X.\n");
	printf("Intervalos: \n");
	printf("[0 ; 1]\n");
	a = 0.0;
	b = 1.0;
	if(verificarIntervalo(a , b)){
		printf("El intervalo es valido. \n");
	}else{
		printf("El invervalo es Invalido");
		exit(0);
	}
	printf("Aplicando metodo de biseccion para un tolerancia de %.10lf\n", tol);
	printf("\nIter\t   a\t\t   b\t\t   c\t\t f(c)\t\t Err.Abs\t Err.Rel(%)\t Err.Int\n");
	printf("----\t-------\t\t-------\t\t-------\t\t-------\t\t-------\t-------\t\t-------\n");
	
	do{
		c = (a + b)/2.0;
		
		// Cálculo de errores
		error_funcion = fabs(f(c));
		error_intervalo = (b - a) / 2.0;
		
		if(i > 0) {
			error_absoluto = fabs(c - cviejo);
			error_relativo = (c != 0) ? fabs((c - cviejo) / c) : 0;
			error_porcentual = error_relativo * 100.0;
		} else {
			error_absoluto = 0;
			error_relativo = 0;
			error_porcentual = 0;
		}
		
		// Mostrar resultados de la iteración
		printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.4f\t\t%.6f\n", 
			   i, a, b, c, f(c), error_absoluto, error_porcentual, error_intervalo);
		
		if(f(a)*f(c) > 0){
			a = c;
		}else if(f(a)*f(c) < 0){
			b = c;
		}else{
			break;
		}
		
		i++;
		cviejo = c;
		
	}while(error_funcion > tol && i < max_iter);
	printf("\n=== RESULTADOS FINALES ===\n");
	printf("La raiz aproximada es: %.10lf\n", c);
	printf("Valor de la funcion en la raiz: f(%.10lf) = %.10lf\n", c, f(c));
	printf("Iteraciones totales: %d\n", i);
	printf("Error absoluto final: %.10lf\n", error_absoluto);
	printf("Error relativo final: %.10lf\n", error_relativo);
	printf("Error porcentual final: %.6f%%\n", error_porcentual);
	printf("Error del intervalo final: %.10lf\n", error_intervalo);
	printf("Tolerancia utilizada: %.10lf\n", tol);

	return 0;
}
double f(double x){
	return -2 + 7 * x - 5 * pow(x , 2) + 6 * pow(x , 3);
}
bool verificarIntervalo(double a, double b){
	if(f(a) * f(b) > 0){
		return false;
	}else{
		return true;
	}
}
