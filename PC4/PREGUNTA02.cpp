#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//guardo los datos de cada pais
struct Seleccion {
    char nombre[20];
    int g, e, p; //partidos
    int gf, gc; //goles
    int dg; //diferencia
    int pts; //puntos
    double rend; //rendimiento
};
//funcion para simular un solo partido y sumar goles
void simularPartido(int resul, int& gfv, int& gctr) {
    int migol, sugol;
    
    //generando goles
    if (resul == 1) { //gane
        migol = 1 + rand() % 5; //entre 1 y 5 goles
        sugol = rand() % migol;
    } else if (resul == 2) { //empate
        migol = rand() % 6;
        sugol = migol; //iguales
    } else { //perdi
        sugol = 1 + rand() % 5;
        migol = rand() % sugol; //hacer menos
    }
    
    //sumo al acumulado
    gfv = gfv + migol;
    gctr = gctr + sugol;
}

//funcion para llenar los datos de los 5 equipos
void generarDatos(Seleccion arr[], int n) {
    const char* nombres[] = {"peru", "brasil", "argentina", "chile", "bolivia"};
    for(int i=0; i<n; i++) {
        strcpy(arr[i].nombre, nombres[i]);
        //generando partidos
        arr[i].g = rand() % 101; 
        arr[i].e = rand() % (101 - arr[i].g);
        arr[i].p = 100 - arr[i].g - arr[i].e;
        //inicializo goles en 0
        arr[i].gf = 0;
        arr[i].gc = 0;
        //simulandio los partidos
        for(int k=0; k<arr[i].g; k++) simularPartido(1, arr[i].gf, arr[i].gc);
        for(int k=0; k<arr[i].e; k++) simularPartido(2, arr[i].gf, arr[i].gc);
        for(int k=0; k<arr[i].p; k++) simularPartido(3, arr[i].gf, arr[i].gc);
        //calculo lo final
        arr[i].pts = (arr[i].g * 3) + (arr[i].e * 1);
        arr[i].dg = arr[i].gf - arr[i].gc;
        //rendimiento
        arr[i].rend = (double)arr[i].pts / 300.0 * 100.0;
    }
}
//ordena por puntos - ddiferencia goles - goles Favor
void ordenarBurbuja(Seleccion arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            bool cambio = false;
            //comparo puntos
            if (arr[j].pts < arr[j+1].pts) {
                cambio = true;
            } else if (arr[j].pts == arr[j+1].pts) {
                //si empatan en puntos, miro la diferencia de goles
                if (arr[j].dg < arr[j+1].dg) {
                    cambio = true;
                } else if (arr[j].dg == arr[j+1].dg) {
                    //si empatan en diferencia de goels, miro goles a favor
                    if (arr[j].gf < arr[j+1].gf) {
                        cambio = true;
                    }
                }
            }
            //si hay que cambiar, hago el swap manual
            if (cambio) {
                Seleccion temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void mostrarTabla(Seleccion arr[], int n) {
    cout << "equipo\t\tPG\tPE\tPP\tGF\tGC\tPts\tRend" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i].nombre << "\t\t"
             << arr[i].g << "\t" 
             << arr[i].e << "\t" 
             << arr[i].p << "\t"
             << arr[i].gf << "\t" 
             << arr[i].gc << "\t"
             << arr[i].pts << "\t" 
             << (int)arr[i].rend << "%" << endl; //casteo a int para que se vea limpio
    }
    cout << endl;
    cout << "CAMPEON DEL TORNEO: " << arr[0].nombre << endl;
}
int main() {
    //semilla fija para que salgan los mismos datos siempre (Sesion 9)
    srand(1234); 
    
    //CASO 1
    cout << "CASO 1" << endl;
    Seleccion tabla1[5];
    generarDatos(tabla1, 5);
    ordenarBurbuja(tabla1, 5);
    mostrarTabla(tabla1, 5);
    cout << endl;

    //CASO 2
    cout << "CASO 2" << endl;
    srand(5678); //cambio la semilla para tener otro resultado
    Seleccion tabla2[5];
    generarDatos(tabla2, 5);
    ordenarBurbuja(tabla2, 5);
    mostrarTabla(tabla2, 5);

    return 0;
}