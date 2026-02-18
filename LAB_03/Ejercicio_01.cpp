#include <iostream>

using namespace std;

int longitud_palabra(const char* p) {
    int len = 0;
    while (*(p + len) != ' ' && *(p + len) != '\0') {
        len++;
    }
    return len;
}

int separar_palabras(char* texto, char* palabras[]) {
    int n = 0;
    bool enPalabra = false;
    char* p = texto;

    while (*p != '\0') {
        if (*p != ' ') {
            if (!enPalabra) {
                *(palabras + n) = p;
                n++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
        p++;
    }
    return n;
}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl) {
    nc = 0;
    nl = 0;
    for (int i = 0; i < n; i++) {
        char* p = *(palabras + i);
        if (longitud_palabra(p) <= 3) {
            *(cortas + nc) = p;
            nc++;
        } else {
            *(largas + nl) = p;
            nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b) {
    int i = 0;
    while (*(a + i) != ' ' && *(a + i) != '\0' && *(b + i) != ' ' && *(b + i) != '\0') {
        if (*(a + i) != *(b + i)) {
            return *(a + i) - *(b + i);
        }
        i++;
    }
    char finA = (*(a + i) == ' ') ? '\0' : *(a + i);
    char finB = (*(b + i) == ' ') ? '\0' : *(b + i);
    return finA - finB;
}

void ordenar(char* v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar_palabras(*(v + j), *(v + j + 1)) > 0) {
                char* temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n) {
    cout << titulo << ":" << endl;
    for (int i = 0; i < n; i++) {
        char* p = *(v + i);
        int len = longitud_palabra(p);
        for (int j = 0; j < len; j++) {
            cout << *(p + j);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int nc, nl;

    int n = separar_palabras(texto, palabras);
    clasificar(palabras, n, cortas, nc, largas, nl);

    ordenar(cortas, nc);
    ordenar(largas, nl);

    cout << "Entrada: " << texto << endl << endl;
    imprimir_grupo("Palabras cortas", cortas, nc);
    imprimir_grupo("Palabras largas", largas, nl);

    return 0;
}