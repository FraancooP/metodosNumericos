#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


//Definicion de prototipos de funciones
double f(double x); // Prototipo de la funcion f(x)
bool verificarIntervalo(double a, double b);//prototipo de la funcion verificarIntervalo


int main(){
    //Definimos las variables
	double a, b, c, cviejo = 0.0;
	double error_funcion, error_absoluto, error_relativo, error_porcentual, error_intervalo;
    int i = 0;
    int max_iter = 1000;
    double tol = 1e-8;

    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);

    if(verificarIntervalo(a, b)) {//para la verificacion del intervalo llamo a funcion....
        printf("El intervalo es valido.\n");
    }else {
        printf("El intervalo no es valido.\n");
        exit(0);
    }
    printf("Aplicando metodo de biseccion para una tolerancia de %.10lf\n", tol);
    printf("\nIter\t   a\t\t   b\t\t   c\t\t   f(c)\t\t   Err.Abs\t Err.Rel(%)\t Err.Int\n");
    printf("----\t-------\t-------\t-------\t-------\t-------\t--------\t-------\n");
    do{
        c = (a + b)/2.0f; //Punto medio del intervalo

        error_funcion = fabs(f(c));
        error_intervalo = (b - a) / 2.0;
        //Ponemos el error de intervalo para corroborar la convergencia
        if(i > 0){
            //Calculo de errores absoluto, relativo y porcentual:
        	error_absoluto = fabs(c - cviejo);
        	error_relativo = (c != 0) ? fabs((c - cviejo) / c) : 0;
        	error_porcentual = error_relativo * 100.0;
        }else{
        	error_absoluto = 0;
        	error_relativo = 0;
        	error_porcentual = 0;
        }


        printf("%d\t%.10f\t%.10f\t%.10f\t%.10f\t%.10f\t%.10f\t\t%.10f\n", i, a, b, c, f(c), error_absoluto, error_porcentual, error_intervalo);
        if (f(a)*f(c) > 0){
            a = c; //La raiz esta en el intervalo [c, b]
        }else if(f(a)*f(c) < 0){
            b = c; //La raiz esta en el intervalo [a, c]
        }else {
            printf("La raiz es: %lf\n", c);
            break; //La raiz es c
        }
        i++;//aumento contador de iteraciones
        cviejo = c; //Guardamos el valor de c para la siguiente iteracion
    }while (error_funcion > tol && i < max_iter);
    printf("\n================ RESULTADOS FINALES ========================\n");
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

//Desarrolo de funciones.
double f(double x) {
    return log(x) + exp(sin(x)) - x;//Funcion a probar
}

bool verificarIntervalo(double a, double b) {
    if (f(a) * f(b) > 0) {
        return false; // El producto es positivo, no hay raiz en el intervalo
    }else {
        return true; // El producto es negativo o cero, hay raiz en el intervalo
    }
}
