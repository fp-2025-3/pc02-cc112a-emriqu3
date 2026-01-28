#include <iostream>
using namespace std;

void imprimirMatriz(int* mat, int F, int C) {
    cout << "Matriz:" << endl;
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            cout << *(mat + i * C + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int sumarSubmatriz(int* mat, int C, int i1, int j1, int i2, int j2) {
    int suma = 0;
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            suma += *(mat + i * C + j);
        }
    }
    return suma;
}

void submatrizSumaMaxima(int* mat, int F, int C) {
    int maxSuma = -1000000;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    for (int i1 = 0; i1 < F; i1++) {
        for (int j1 = 0; j1 < C; j1++) {
            for (int i2 = i1; i2 < F; i2++) {
                for (int j2 = j1; j2 < C; j2++) {
                    int sumaActual = sumarSubmatriz(mat, C, i1, j1, i2, j2);
                    if (sumaActual > maxSuma) {
                        maxSuma = sumaActual;
                        r1 = i1; c1 = j1;
                        r2 = i2; c2 = j2;
                    }
                }
            }
        }
    }
    cout << "Submatriz de suma maxima:" << endl;
    cout << "Esquina superior izquierda: (" << r1 << "," << c1 << ")" << endl;
    cout << "Esquina inferior derecha: (" << r2 << "," << c2 << ")" << endl;
    cout << "Suma maxima: " << maxSuma << endl;
}

int main() {
    int filas = 4;
    int columnas = 5;

    int A[4][5] = {
        {-2,  1, -3,  4, -1},
        { 2,  3, -2,  1, -5},
        {-1,  4,  2, -3,  2},
        { 1, -2,  3,  4, -1}
    };
    imprimirMatriz((int*)A, filas, columnas);
    submatrizSumaMaxima((int*)A, filas, columnas);

    return 0;
}