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
    double tol = 1e-8;
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

    }while(error > tol && i < max_iter);

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