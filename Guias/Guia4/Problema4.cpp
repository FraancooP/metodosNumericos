#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    const int n = 50; 
    vector<vector<int>> A(n, vector<int>(n, 0)); 
    vector<int> b(n, 5); 

    double x0 [] = {0};
    // Generar matriz con el patrón
    for (int i = 0; i < n; i++) {
        A[i][i] = 12;
        if (i - 1 >= 0) A[i][i - 1] = -2;
        if (i + 1 < n) A[i][i + 1] = -2;
        if (i - 2 >= 0) A[i][i - 2] = 1;
        if (i + 2 < n) A[i][i + 2] = 1;
    }

    // Abrir archivo
    FILE *fp = fopen("matriz.txt", "w");
    if (fp == NULL) {
        cout << "Error al crear el archivo!" << endl;
        return 1;
    }

    // Escribir tamaño en la primera fila
    fprintf(fp, "%d\n", n);

    // Escribir matriz A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%d ", A[i][j]);
        }
        fprintf(fp, "\n");
    }

    // Escribir vector b
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", b[i]);
    }
    fprintf(fp, "\n");

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", x0[i]);
    }
    fprintf(fp, "\n");

    fclose(fp);
    cout << "Archivo matriz.txt generado correctamente!" << endl;
    return 0;
}
