#include <iostream>
using namespace std;

void imprimirMatriz(int* mat, int F, int C) {
    cout << "Matriz:" << endl;
    for (int i = 0; i < F; i++) {
        cout << "  "; 
        for (int j = 0; j < C; j++) {
            cout << *(mat + i * C + j) << "  ";
        }
        cout << endl;
    }
}

bool esPico(int* mat, int F, int C, int i, int j) {
    int val = *(mat + i * C + j);
    bool mayorOIgual = true;
    bool estrictamenteMayor = false;

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && ni < F && nj >= 0 && nj < C) {
            int vecino = *(mat + ni * C + nj);
            if (val < vecino) {
                mayorOIgual = false;
            }
            if (val > vecino) {
                estrictamenteMayor = true;
            }
        }
    }
    return mayorOIgual && estrictamenteMayor;
}
void imprimirPicos(int* mat, int F, int C) {
    cout << "Elementos pico:" << endl;
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (esPico(mat, F, C, i, j)) {
                cout << "Pico en (" << i << "," << j << "): " << *(mat + i * C + j) << endl;
            }
        }
    }
}

int main() {
    int M[4][5] = {
        {3, 3, 3, 3, 3},
        {3, 4, 4, 2, 3},
        {3, 4, 5, 4, 3},
        {3, 3, 3, 3, 3}
    };
    int filas = 4;
    int columnas = 5;

    imprimirMatriz((int*)M, filas, columnas);
    imprimirPicos((int*)M, filas, columnas);

    return 0;
}