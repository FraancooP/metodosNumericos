#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// Prototipos de funciones
//Funciones de cada problema de la guia:
void problema1(double a, double b);
void problema2(double a, double b);
void problema3(double a, double b);
void problema4(double a, double b);
//Funciones f(x):
/*
Las nomenclaturas de las funciones son:
- fp1e1: Funcion problema 1 ejercicio 1
- fp1e2: Funcion problema 1 ejercicio 2....
*/
double fp1(double x);
double fp2(double a);
//Metodos de calculo:
void metodoReglaFalsa(double (*func)(double), double a, double b);
void metodoBiseccion(double (*func)(double), double a, double b);
bool verificarIntervalo(double (*func)(double), double a, double b);
int main(){
    bool salir = false;
    int opcion = 0;
    double a = 0.0, b = 0.0;
    printf("Este programa esta creado para mostrar resultados de la guia.\n");
    do{
        printf("================================================================================================\n");
        printf("Todos los extremos de las funciones estan en la carpeta de graficasGuia1\n");
        printf("Seleccione un problema que desea ver:\n");
        printf("1. Problema 1\n");
        printf("2. Problema 2\n");
        printf("3. Problema 3\n");
        printf("4. Problema 4\n");
        printf("5. Salir\n");
        printf("Ingrese su opcion: \n");
        printf("================================================================================================\n");

        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                problema1(a, b);
                break;
            case 2:
                problema2(a, b);
                break;
            case 3:
                problema3(a, b);
                break;
            case 4:
                problema4(a, b);
                break;
            case 5:
                salir = true;
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente de nuevo.\n");
        }
        

    }while(!salir);
    return 0;
}

bool verificarIntervalo(double (*func)(double), double a, double b) {
    if (func(a) * func(b) > 0) {
        return false; // El producto es positivo, no hay raiz en el intervalo
    }else {
        return true; // El producto es negativo o cero, hay raiz en el intervalo
    }
}

void problema1(double a, double b) {
    printf("Ejercicio 2:\n");
    printf("Para la funcion f(x) = -2 + 7x - 5x^2 + 6x^3\n");
    printf("La funcion posee 1 raiz en X.\n");
    printf("Intervalos: [0, 1]\n");
    a = 0.0;
    b = 1.0;
    printf("Usando el metodo de biseccion:\n");
    metodoBiseccion(fp1, a, b);
}
void problema2(double a, double b) {
    printf("Ejercicio 2:\n");
    printf("Para la funcion g(a) = a^10 - 1\n");
    printf("La funcion posee 2 raizes en X.\n");
    printf("Intervalos: [0.3, 0.4]\n");
    a = 0.3;
    b = 0.4;
    printf("Usando el metodo de biseccion:\n");
    metodoBiseccion(fp1e1, a, b);
}
void problema3(double a, double b) {
    printf("Este es el resultado del problema 3.\n");
    // Aqui puedes agregar el codigo para resolver el problema 3
}
void problema4(double a, double b) {
    printf("Este es el resultado del problema 4.\n");
    // Aqui puedes agregar el codigo para resolver el problema 4
}   


void metodoReglaFalsa(double (*func)(double), double a, double b) {
    int i = 0;
    int max_iter = 1000;
    double tol = 1e-8;
    double error = 0.0f;
    double c = 0.0f;
    double cviejo = 0.0f;

    if(verificarIntervalo(func, a, b)) { // Verificacion del intervalo
        printf("El intervalo es valido.\n");
    } else {
        printf("El intervalo no es valido.\n");
        exit(0);
    }

    do{
        c = (a * func(b) - b * func(a)) /(func(b) - func(a)); // Regla de falsa posicion
        //IMPORTANTE: El inicio del intervalo no debe 0!, ya que debido a esto
        //la funcion f(x) no se puede evaluar en ese punto(por el logaritmo).
    	if(func(a) * func(c) > 0){
    		a = c;
    	}else if(func(a) * func(c) < 0){
    		b = c;
    	}else{
    		printf("La raiz esta en: %lf\n", c);
    		break;
    		
    	}
    	error = fabs(func(c));
    	i++;
    	cviejo = c;

    }while(error > tol && i < max_iter);
    printf("La raiz es: %.10lf\n", c);
    printf("Numero de iteraciones: %d\n", i);
    printf("Error absoluto: %.10lf\n", error);
    printf("Valor de c en la ultima iteracion: %.10lf\n", cviejo);
    system("pause");
    printf("Presione cualquier tecla para continuar...\n");
    getchar(); // Espera a que el usuario presione una tecla
}
void metodoBiseccion(double (*func)(double), double a, double b) {
    int i = 0;
    int max_iter = 1000;
    double tol = 1e-8;
    double error = 0.0f;
    double c = 0.0f;
    double cviejo = 0.0f;
    if(verificarIntervalo(func, a, b)) {//para la verificacion del intervalo llamo a funcion....
        printf("El intervalo es valido.\n");
    }else {
        printf("El intervalo no es valido.\n");
        exit(0);
    }
    do{
        c = (a + b)/2.0f; //Punto medio del intervalo
        if (func(a)*func(c) > 0){
            a = c; //La raiz esta en el intervalo [c, b]
        }else if(func(a)*func(c) < 0){
            b = c; //La raiz esta en el intervalo [a, c]
        }else {
            printf("La raiz es: %lf\n", c);
            break; //La raiz es c
        }
        error = fabs(func(c)); //Error absoluto
        i++;//aumento contador de iteraciones
        cviejo = c; //Guardamos el valor de c para la siguiente iteracion
    }while (error > tol && i < max_iter);
    printf("RESULTADOS DE METODO BISECCION:\n");
    printf("La raiz es: %.10lf\n", c);
    printf("Numero de iteraciones: %d\n", i);
    printf("Error absoluto: %.10lf\n", error);
    printf("Valor de c en la ultima iteracion: %.10lf\n", cviejo);
    system("pause");
    printf("Presione cualquier tecla para continuar...\n");
    getchar();
}



double fp1(double x) {
    return -2 + 7 * x - 5 * pow(x, 2) + 6 * pow(x, 3);
}
double fp2(double a) {
    return pow(a, 10) - 1;
}