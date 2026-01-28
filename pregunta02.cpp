#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for (int* ptr = inicio; ptr < fin; ptr++) {
        if (equivale(*ptr, clave)){
        return ptr;    
        } 
    }
    return nullptr;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida
bool igual(int a, int b) { 
    return a == b; 
}

bool mismaParidad(int a, int b) { 
    int valA = (a < 0) ? -a : a;
    int valB = (b < 0) ? -b : b;
    return (valA % 2) == (valB % 2); 
}

bool divideA(int a, int b) { 
    if (a == 0) return false;
    return (b % a == 0); 
}

int contarDigitos(int n) {
    if (n == 0) return 1;
    if (n < 0) n = -n;
    int contador = 0;
    while (n > 0) {
        n /= 10;
        contador++;
    }
    return contador;
}

bool mismaCantidadDigitos(int a, int b) {
    return contarDigitos(a) == contarDigitos(b);
}

bool mismoResiduoMod5(int a, int b) { 
    int resA = a % 5;
    int resB = b % 5;
    if (resA < 0) resA += 5;
    if (resB < 0) resB += 5;
    return resA == resB; 
}



int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int n = 7;
    int* inicio = A;
    int* fin = A + n;

    int clave = 13;

    // Imprima el arreglo
    cout << "Arreglo: ";
    for (int i = 0; i < n; i++) {
        cout << *(inicio + i) << " ";
    }
    cout << endl;

    cout << "Clave: " << clave << endl << endl;
    const char* nombres[] = {
        "Igualdad exacta",
        "Misma paridad",
        "Divide a",
        "Misma cantidad de digitos",
        "Mismo residuo modulo 5"
    };
    bool (*criterios[])(int, int) = {
        igual,
        mismaParidad,
        divideA,
        mismaCantidadDigitos,
        mismoResiduoMod5
    };
    for (int i = 0; i < 5; i++) {
        int* resultado = buscar(inicio, fin, criterios[i], clave);
        cout << nombres[i] << ": ";
        if (resultado) {
            cout << "encontrado valor: " << *resultado 
                 << " Pos: " << (void*)resultado << endl;
        } else {
            cout << "no encontrado." << endl;
        }
    }

    return 0;
}

