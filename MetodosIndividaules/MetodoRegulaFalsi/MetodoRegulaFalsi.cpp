#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

bool verificarIntervalo(double a, double b); // Prototipo de la funcion verificarIntervalo
double f(double x); // Prototipo de la funcion f(x)
int main(){
    double a = 0.0f;
    double b = 0.0f;
    int i = 0;
    int max_iter = 1000;
    double tol = 1e-3;
    double error = 0.0f;
    double c = 0.0f;
    double cviejo = 0.0f;

    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);
    
    if(verificarIntervalo(a, b)) { // Verificacion del intervalo
        printf("El intervalo es valido.\n");
    } else {
        printf("El intervalo no es valido.\n");
        exit(0);
    }

    do{

        c = (a * f(b) - b * f(a)) /(f(b) - f(a)); // Regla de falsa posicion
        //IMPORTANTE: El inicio del intervalo no debe 0!, ya que debido a esto
        //la funcion f(x) no se puede evaluar en ese punto(por el logaritmo).
    	if(f(a) * f(c) > 0){
    		a = c;
    	}else if(f(a) * f(c) < 0){
    		b = c;
    	}else{
    		printf("La raiz esta en: %lf\n", c);
    		break;
    		
    	}
    	error = fabs(f(c));
    	i++;
    	cviejo = c;

    }while(error > tol && i < max_iter);
     printf("La raiz es: %.10lf\n", c);
    printf("Numero de iteraciones: %d\n", i);
    printf("Error absoluto: %.10lf\n", error);
    printf("Valor de c en la ultima iteracion: %.10lf\n", cviejo);



    return 0;
}



double f(double x) {
    return log(x) + exp(sin(x)) - x; // Funcion a probar
}
bool verificarIntervalo(double a, double b) {
    if (f(a) * f(b) > 0) {
        return false; // El producto es positivo, no hay raiz en el intervalo
    }else {
        return true; // El producto es negativo o cero, hay raiz en el intervalo
    }
}