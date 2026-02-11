#include <iostream>
#include <cstring>
using namespace std;

void leerDatos(char nombres[][21], int* tiempos, int& n) {
    cout << "Ingrese numero de corredores: ";
    cin >> n;
    if (n > 30) n = 30;

    for (int i = 0; i < n; i++) {
        cout << "Nombre del corredor " << i + 1 << ": ";
        cin >> *(nombres + i); 
        cout << "Tiempo (en segundos): ";
        cin >> *(tiempos + i);
    }
}
void ordenarRanking(char nombres[][21], int* tiempos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(tiempos + j) > *(tiempos + j + 1)) {
                int tempT = *(tiempos + j);
                *(tiempos + j) = *(tiempos + j + 1);
                *(tiempos + j + 1) = tempT;
                char tempN[21];
                strcpy(tempN, *(nombres + j));
                strcpy(*(nombres + j), *(nombres + j + 1));
                strcpy(*(nombres + j + 1), tempN);
            }
        }
    }
}
void mostrarRanking(char nombres[][21], int* tiempos, int n) {
    cout << "\nRANKING FINAL" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << *(nombres + i) << endl;
        cout << "   " << *(tiempos + i) << " segundos" << endl;
    }
}
void buscarCorredor(char nombres[][21], int* tiempos, int n) {
    char buscado[21];
    cout << "\nIngrese nombre a buscar: ";
    cin >> buscado;

    bool hallado = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(*(nombres + i), buscado) == 0) {
            cout << "Corredor encontrado" << endl;
            cout << "Posicion: " << i + 1 << endl;
            cout << "Tiempo: " << *(tiempos + i) << " segundos" << endl;
            hallado = true;
            break;
        }
    }
    if (!hallado) cout << "El corredor no existe." << endl;
}
void filtrarRango(char nombres[][21], int* tiempos, int n) {
    int t_min, t_max;
    cout << "\nIngrese tiempo minimo y maximo: ";
    cin >> t_min >> t_max;

    cout << "Corredores en el rango [" << t_min << ", " << t_max << "]:" << endl;
    for (int i = 0; i < n; i++) {
        if (*(tiempos + i) >= t_min && *(tiempos + i) <= t_max) {
            cout << *(nombres + i) << " - " << *(tiempos + i) << " segundos" << endl;
        }
    }
}
int main() {
    char nombres[30][21];
    int tiempos[30];
    int n;

    leerDatos(nombres, tiempos, n);
    ordenarRanking(nombres, tiempos, n);
    mostrarRanking(nombres, tiempos, n);
    buscarCorredor(nombres, tiempos, n);
    filtrarRango(nombres, tiempos, n);

    return 0;
}