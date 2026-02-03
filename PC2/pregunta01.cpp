#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
    if (k > grado) {
        gradoRes = 0;
        *res = 0;
        return;
    }
    // Escriba su codigo aqui
    gradoRes = grado - k;

    for (int i = 0; i <= gradoRes; i++) {
        double valor = *(coef + i + k);
        for (int j = 0; j < k; j++) {
            valor *= (i + k - j);
        }
        *(res + i) = valor;
    }
}


// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
    for (int i = grado; i >= 0; i--) {
        double valor = *(p + i);

        if (i > 0) {
            cout << valor << "x^" << i;
        }
        else {
            cout << valor;
        }
        if (i > 0) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK
    derivadaK(coef, grado, k, resultado, gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout << "Polinomio original: " << endl;
    imprimirPolinomio(coef, grado);

    cout << "\nDerivada de orden " << k << ": " << endl;
    imprimirPolinomio(resultado, gradoResultado);
    return 0;
}
