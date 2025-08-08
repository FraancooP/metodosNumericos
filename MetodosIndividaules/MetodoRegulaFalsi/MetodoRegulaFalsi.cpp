#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

bool verificarIntervalo(double a, double b); // Prototipo de la funcion verificarIntervalo
double f(double x); // Prototipo de la funcion f(x)
int main(){
    double a = 0.0;
    double b = 0.0;
    double c, cviejo = 0.0;
    double error_funcion, error_absoluto, error_relativo, error_porcentual, error_intervalo;
    int i = 0;
    int max_iter = 1000;
    double tol = 1e-6;

    printf("Ingrese el inicio del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el final del intervalo: ");
    scanf("%lf", &b);
    
    printf("Para la funcion f(x) = ln(x) + e^(sin(x)) - x\n");
    printf("Aplicando metodo de Regla Falsi con tolerancia de %.10lf\n", tol);
    
    if(verificarIntervalo(a, b)) { // Verificacion del intervalo
        printf("El intervalo [%.6f, %.6f] es valido.\n", a, b);
        printf("f(%.6f) = %.6f\n", a, f(a));
        printf("f(%.6f) = %.6f\n", b, f(b));
    } else {
        printf("El intervalo no es valido.\n");
        printf("f(a) * f(b) = %.6f * %.6f = %.6f > 0\n", f(a), f(b), f(a)*f(b));
        printf("No hay cambio de signo en el intervalo.\n");
        exit(0);
    }
    
    printf("\nIter\t   a\t\t   b\t\t   c\t\t f(c)\t\t Err.Abs\t Err.Rel(%)\t Err.Int\n");
    printf("----\t-------\t\t-------\t\t-------\t\t-------\t\t-------\t-------\t\t-------\n");

    do{
        c = (a * f(b) - b * f(a)) / (f(b) - f(a)); // Regla de falsa posicion
        
        // Cálculo de errores
        error_funcion = fabs(f(c));
        error_intervalo = fabs(b - a);
        
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
        
        //IMPORTANTE: El inicio del intervalo no debe ser 0!, ya que debido a esto
        //la funcion f(x) no se puede evaluar en ese punto(por el logaritmo).
    	if(f(a) * f(c) > 0){
    		a = c;
    	}else if(f(a) * f(c) < 0){
    		b = c;
    	}else{
    		printf("\nLa raiz exacta esta en: %.10lf\n", c);
    		break;
    	}
    	
    	i++;
    	cviejo = c;

    }while(error_funcion > tol && i < max_iter);
     
    printf("\n=== RESULTADOS FINALES (METODO REGLA FALSI) ===\n");
    printf("La raiz aproximada es: %.10lf\n", c);
    printf("Valor de la funcion en la raiz: f(%.10lf) = %.10lf\n", c, f(c));
    printf("Iteraciones totales: %d\n", i);
    printf("Error absoluto final: %.10lf\n", error_absoluto);
    printf("Error relativo final: %.10lf\n", error_relativo);
    printf("Error porcentual final: %.6f%%\n", error_porcentual);
    printf("Error del intervalo final: %.10lf\n", error_intervalo);
    printf("Tolerancia utilizada: %.10lf\n", tol);
    
    if(i >= max_iter) {
        printf("ADVERTENCIA: Se alcanzo el maximo de iteraciones (%d)\n", max_iter);
    }



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