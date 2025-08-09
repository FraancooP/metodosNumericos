/*
Concluciones:
Para los casos de los metodos de biseccion en ambas raices, las iteraciones totales son 0.
Esto se debe a porque esta cayendo justo en la raiz al momento de calcular c.
En cambio, para el metodo de reghula falsi, no cae exactamente en la raiz debido a la formula
lineal que se usa al calcular c.
*/


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stack>

using namespace std;

//Prototipo de funciones
double f(double x);
bool verificarIntervalo(double a, double b);

void metodoBiseccion(double a, double b, stack<int>& iteraciones, stack<double>& raiz);
void metodoRegulaFalsi(double a, double b, stack<int>& iteraciones, stack<double>& raiz);
int main() {
	double a, b = 0.0;
    //Declaro pilas para guardar iteraciones y valor de la raiz.
	stack<int> iteraciones;
	stack<double> valor_raiz;
	printf("Para la funcion g(a) = a^10 - 1\n");
	printf("La funcion posee 2 raizes en X.\n");
	printf("Intervalos: \n");
	printf("[-1.5 ; -0.5]\n");
	printf("[0.5 ; 1.5]\n");
	printf("Aplicando metodo de biseccion y regula falsi para la primera raiz.\n");
	a = -1.5;
	b = -0.5;
	metodoBiseccion(a ,b ,iteraciones, valor_raiz);
	metodoRegulaFalsi(a, b, iteraciones, valor_raiz);
	printf("Aplicando metodo de biseccion y regula falsi para la segunda raiz.\n");
	a = 0.5;
	b = 1.5;
	metodoBiseccion(a, b, iteraciones, valor_raiz);
	metodoRegulaFalsi(a, b, iteraciones, valor_raiz);
	printf("===============Resultados finales===============\n");
    printf("Metodo: \t NroRaiz: \t RaizAproximada \t IteracionesTotales\n");
	printf("RegulaFalsi\t  2da\t\t %.10lf\t\t %d\n",valor_raiz.top(),iteraciones.top());
	valor_raiz.pop();
	iteraciones.pop();
    printf("Biseccion\t  2da\t\t %.10lf\t\t %d\n",valor_raiz.top(),iteraciones.top());
    valor_raiz.pop();
	iteraciones.pop();
    printf("RegulaFalsi\t  1era\t\t %.10lf\t\t %d\n",valor_raiz.top(),iteraciones.top());
    valor_raiz.pop();
	iteraciones.pop();
    printf("Biseccion\t  1era\t\t %.10lf\t\t %d\n",valor_raiz.top(),iteraciones.top());
	valor_raiz.pop();
	iteraciones.pop();




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

void metodoBiseccion(double a, double b, stack<int>& iteraciones, stack<double>& raiz){
		double c, cviejo = 0.0;
		double error_funcion, error_absoluto, error_relativo, error_porcentual, error_intervalo;
	    int i = 0;
	    int max_iter = 1000;
	    double tol = 1e-5;

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
	    	iteraciones.push(i);
	    	raiz.push(c);
	    	system("pause");
	    	printf("Precione una tecla para continuar...\n");
}
void metodoRegulaFalsi(double a, double b, stack<int>& iteraciones, stack<double>& raiz){
	double c, cviejo = 0.0;
	    double error_funcion, error_absoluto, error_relativo, error_porcentual, error_intervalo;
	    int i = 0;
	    int max_iter = 1000;
	    double tol = 1e-5;
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
	    iteraciones.push(i);
	    raiz.push(c);
	    system("pause");
	    printf("Presione una tecla para continuar...\n");

}
