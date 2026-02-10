#include <iostream>
using namespace std;
long long costoMaximo(int* inicio, int* fin) {
    if (inicio == fin) {
        return 0;
    }
    long long maxCosto = -1;
    long long productoActual = 1;
    for (int* p = inicio; p < fin; p++) {
        productoActual *= *p;
        long long costoResto = costoMaximo(p + 1, fin);
        long long costoTotal = productoActual + costoResto;
        if (costoTotal > maxCosto) {
            maxCosto = costoTotal;
        }
    }
    return maxCosto;
}
long long costoMaximoConTraza(int* inicio, int* fin, int nivel) {
    for (int i = 0; i < nivel; i++) cout << "    ";
    cout << "Llamada con sub-arreglo: { ";
    for (int* k = inicio; k < fin; k++) cout << *k << " ";
    cout << "}" << endl;
    if (inicio == fin) {
        for (int i = 0; i < nivel; i++) cout << "    ";
        cout << "Retorna: 0 (Arreglo vacio)" << endl;
        return 0;
    }
    long long maxCosto = -1;
    long long productoActual = 1;

    for (int* p = inicio; p < fin; p++) {
        productoActual *= *p;
        long long costoResto = costoMaximoConTraza(p + 1, fin, nivel + 1);
        long long costoTotal = productoActual + costoResto;

        if (costoTotal > maxCosto) {
            maxCosto = costoTotal;
        }
    }
    for (int i = 0; i < nivel; i++) cout << "    ";
    cout << "Retorna MAXIMO encontrado: " << maxCosto << endl;
    
    return maxCosto;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    cout << "PARTE A" << endl;
    cout << "Arreglo: {1, 2, 3, 4, 5}" << endl;
    long long resultado = costoMaximo(A, A + n);
    cout << "Costo Maximo: " << resultado << endl << endl;
    int B[] = {2, 1, 3};
    int m = 3;

    cout << "PARTE B" << endl;
    cout << "Arreglo: {2, 1, 3}" << endl;
    cout << "Traza:" << endl;
    costoMaximoConTraza(B, B + m, 0);

    return 0;
}