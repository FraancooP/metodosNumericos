#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


//Definicion de prototipos de funciones
double f(double x); // Prototipo de la funcion f(x)
bool verificarIntervalo(double a, double b);//prototipo de la funcion verificarIntervalo


int main(){
    double a = 0.0f;
    double b = 0.0f;
    int i = 0;
    double tol = exp(1e-8);
    double error = 0.0f;
    double c = 0.0f;
    double cviejo = 0.0f;

    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);

    if(verificarIntervalo(a, b)) {
        printf("El intervalo es valido.\n");
    }else {
        printf("El intervalo no es valido.\n");
        exit(0);
    }
    do{
        c = (a + b)/2.0f; //Punto medio del intervalo
        if (f(a)*f(c) > 0){
            a = c; //La raiz esta en el intervalo [c, b]
        }else if(f(a)*f(c) < 0){
            b = c; //La raiz esta en el intervalo [a, c]
        }else {
            printf("La raiz es: %lf\n", c);
            break; //La raiz es c
        }    
        error = fabs(f(c)); //Error absoluto
        i++;
        cviejo = c; //Guardamos el valor de c para la siguiente iteracion
    }while (error > tol);
    printf("La raiz es: %lf\n", c);
    printf("Numero de iteraciones: %d\n", i);
    printf("Error absoluto: %lf\n", error);
    printf("Valor de c en la ultima iteracion: %lf\n", cviejo);
    


    return 0;
}

//Desarrolo de funciones.
double f(double x) {
    return log(x) + exp(sin(x)) - x;
}

bool verificarIntervalo(double a, double b) {
    if (f(a) * f(b) > 0) {
        return false; // El producto es positivo, no hay raiz en el intervalo
    }else {
        return true; // El producto es negativo o cero, hay raiz en el intervalo
    }
}