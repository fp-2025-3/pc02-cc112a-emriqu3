#include <iostream>
using namespace std;

//estructura para el polinomio
struct Polinomio {
    int grado;
    int* cf; //puntero para el arreglo dinamico 
};
//funcion para crear un polinomio y reservar memoria
Polinomio crear(int g, int* datos) {
    Polinomio p;
    p.grado = g;
    //reservo memoria
    p.cf = new int[g + 1]; 
    
    //paso los datos del arreglo auxiliar a mi estructura
    for (int i = 0; i <= g; i++) {
        p.cf[i] = datos[i];
    }
    return p;
}
//funcion para mostrar
void mostrar(Polinomio p) {
    for (int i = 0; i <= p.grado; i++) {
         //calculo el exponente
        int exp = p.grado - i;
         //imprimo el numero
        cout << p.cf[i];
        if (exp > 0) {
            cout << "x^" << exp;
        }       
        //pongo el + solo si no es el ultimo termino
        if (i < p.grado) {
            cout << " + ";
        }
    }
    cout << endl;
}
//suma de 3 polinomios
Polinomio sumar3(Polinomio a, Polinomio b, Polinomio c) {
    int maxgr = a.grado;
    if (b.grado > maxgr) maxgr = b.grado;
    if (c.grado > maxgr) maxgr = c.grado;
    //creo el polinomio resultado
    Polinomio res;
    res.grado = maxgr;
    res.cf = new int[maxgr + 1];
    //lleno de ceros para poder sumar encima
    for(int i = 0; i <= maxgr; i++) res.cf[i] = 0;
    //sumo el primero
    for(int i = 0; i <= a.grado; i++) {
        int exp = a.grado - i;
        int pos = maxgr - exp;
        //posicion en el arreglo resultado
        res.cf[pos] = res.cf[pos] + a.cf[i];
    }
    //sumo el segundo
    for(int i = 0; i <= b.grado; i++) {
        int exp = b.grado - i;
        int pos = maxgr - exp;
        res.cf[pos] = res.cf[pos] + b.cf[i];
    }
    //sumo el tercero
    for(int i = 0; i <= c.grado; i++) {
        int exp = c.grado - i;
        int pos = maxgr - exp;
        res.cf[pos] = res.cf[pos] + c.cf[i];
    }
    return res;
}
//multiplicacion de 2 polinomios (para usarla despues)
Polinomio multiplicar2(Polinomio a, Polinomio b) {
    Polinomio res;
    //en la multiplicacion los grados se suman
    res.grado = a.grado + b.grado;
    res.cf = new int[res.grado + 1];
    //inicializo en 0
    for(int i=0; i<=res.grado; i++) res.cf[i] = 0;
    //multiplico todos con todos (convolucion)
    for (int i = 0; i <= a.grado; i++) {
        for (int j = 0; j <= b.grado; j++) {
            //sumo en la posicion i + j
            res.cf[i + j] = res.cf[i + j] + (a.cf[i] * b.cf[j]);
        }
    }
    return res;
}
//multiplicacion de los 3
Polinomio multiplicar3(Polinomio a, Polinomio b, Polinomio c) {
    Polinomio temp = multiplicar2(a, b); //multiplicando los dos primeros
    Polinomio res = multiplicar2(temp, c); //el resultado por el tercero
    
    //borro el temporal para no dejar basura en memoria
    delete[] temp.cf; 
    return res;
}
//funcion para limpiar memoria al final
void liberar(Polinomio p) {
    delete[] p.cf;
}
int main() {
    cout << "CASO 1" << endl;
    
    //datos fijos
    int d1[] = {1, 0, 3};
    int d2[] = {-4, 5};
    int d3[] = {3, 0, 1};
    Polinomio P1 = crear(2, d1);
    Polinomio P2 = crear(1, d2);
    Polinomio P3 = crear(2, d3);
    cout << "Polinomio 1: "; mostrar(P1);
    cout << "Polinomio 2: "; mostrar(P2);
    cout << "Polinomio 3: "; mostrar(P3);
    Polinomio suma = sumar3(P1, P2, P3);
    cout << "Suma: "; mostrar(suma);
    Polinomio prod = multiplicar3(P1, P2, P3);
    cout << "Producto: "; mostrar(prod);

    //libero memoria
    liberar(P1); liberar(P2); liberar(P3); liberar(suma); liberar(prod);
    cout << endl;

    cout << "CASO 2" << endl;
    //probando con otro polinomio
    int d4[] = {2, 0}; 
    int d5[] = {1, 2};
    int d6[] = {3};
    Polinomio P4 = crear(1, d4);
    Polinomio P5 = crear(1, d5);
    Polinomio P6 = crear(0, d6);
    cout << "P4: "; mostrar(P4);
    cout << "P5: "; mostrar(P5);
    cout << "P6: "; mostrar(P6);
    Polinomio suma2 = sumar3(P4, P5, P6);
    cout << "Suma: "; mostrar(suma2);
    Polinomio prod2 = multiplicar3(P4, P5, P6);
    cout << "Producto: "; mostrar(prod2); 
    liberar(P4); liberar(P5); liberar(P6); liberar(suma2); liberar(prod2);

    return 0;
}