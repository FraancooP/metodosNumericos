#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// Prototipos de funciones
//Funciones de cada problema de la guia:
void problema1();
void problema2();
void problema3();
void problema4();
//Funciones f(x):
/*
Las nomenclaturas de las funciones son:
- fp1e1: Funcion problema 1 ejercicio 1
- fp1e2: Funcion problema 1 ejercicio 2....
*/
double fp1e1(double x);




//Metodos de calculo:
void metodoReglaFalsa(double (*func)(double));
void metodoBiseccion(double (*func)(double));
int main(){
    bool salir = false;
    int opcion = 0;

    do{
        printf("Este programa esta creado para mostrar resultados de la guia.\n");
        printf("Todos los extremos de la funcion estan en la carpeta de graficasGuia1\n");
        printf("Seleccione un problema que desea ver:\n");
        printf("1. Problema 1\n");
        printf("2. Problema 2\n");
        printf("3. Problema 3\n");
        printf("4. Problema 4\n");
        printf("5. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                problema1();
                break;
            case 2:
                problema2();
                break;
            case 3:
                problema3();
                break;
            case 4:
                problema4();
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
void problema1() {
    printf("Ejercicio 1:.\n");
    printf("Para la funcion f(x) = -2 + 7x - 5x^2 + 6x^3\n");
    printf("La funcion posee 1 raiz en X.\n");
    printf("Intervalos: [0.1, 0.2]\n");
    // Aqui puedes agregar el codigo para resolver el problema 1
}
void problema2() {
    printf("Ejercicio 2:.\n");
    printf("Para la funcion f(x) = -2 + 7x - 5x^2 + 6x^3\n");
    printf("La funcion posee 1 raiz en X.\n");
    printf("Intervalos: [0.1, 0.2]\n");
    // Aqui puedes agregar el codigo para resolver el problema 2
}
void problema3() {
    printf("Este es el resultado del problema 3.\n");
    // Aqui puedes agregar el codigo para resolver el problema 3
}
void problema4() {
    printf("Este es el resultado del problema 4.\n");
    // Aqui puedes agregar el codigo para resolver el problema 4
}   


void metodoReglaFalsa(double (*func)(double)) {
    // Implementacion del metodo de la regla falsa
    // Aqui puedes agregar el codigo para el metodo de la regla falsa
}
void metodoBiseccion(double (*func)(double)) {
    
}