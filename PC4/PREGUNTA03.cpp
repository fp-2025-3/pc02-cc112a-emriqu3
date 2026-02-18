#include <iostream>
#include <cstring>
using namespace std;
//estructura Producto
struct Producto {
    int cod;
    char* nombre;
    double precio;
    int stock;
};
//funcion para crear un solo producto
Producto crear_prd(int cod, const char* nombre, double precio, int stock) {
    Producto p;
    p.cod = cod;
    p.precio = precio;
    p.stock = stock;
    p.nombre = new char[strlen(nombre) + 1];
    strcpy(p.nombre, nombre);   
    return p;
}
//funcion para crear el arreglo de productos
Producto* crear_invt(int n) {
    Producto* inv = new Producto[n];
    return inv;
}
//busqueda usando indices
Producto* buscar_prd(Producto* inv, int n, int cod) {
    for (int i = 0; i < n; i++) {
        if (inv[i].cod == cod) {
            return &inv[i];
        }
    }
    return NULL;
}
//funcion para borrar todo
void liberar_invt(Producto* inv, int n) {
    for (int i = 0; i < n; i++) {
        //mucho mas legible y menos "robotico"
        delete[] inv[i].nombre;
    }
    delete[] inv;
}
void mostrar(Producto* inv, int n) {
    cout << "INVENTARIO" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Codigo: " << inv[i].cod 
             << " | Nombre: " << inv[i].nombre 
             << " | Precio: " << inv[i].precio 
             << " | Stock: " << inv[i].stock << endl;
    }
}
int main() {
    //CASO 1
    cout << "CASO 1" << endl;
    int n = 5;
    Producto* almacen = crear_invt(n);

    //llenado con corchetes (Lo que haria cualquier estudiante)
    almacen[0] = crear_prd(100, "teclado", 10.5, 5);
    almacen[1] = crear_prd(101, "mouse", 21, 10);
    almacen[2] = crear_prd(102, "monitor", 31.5, 15);
    almacen[3] = crear_prd(103, "laptop", 42, 20);
    almacen[4] = crear_prd(104, "impresora", 52.5, 25);
    mostrar(almacen, n);
    cout << "Buscando 102..." << endl;
    Producto* encontrado = buscar_prd(almacen, n, 102);   
    if (encontrado != NULL) {
        cout << "Encontrado: " << encontrado->nombre << endl;
    } else {
        cout << "No se encontro." << endl;
    }

    liberar_invt(almacen, n);
    cout << endl;

    //CASO 2
    cout << "CASO 2" << endl;
    int m = 2;
    Producto* tienda = crear_invt(m);
    
    tienda[0] = crear_prd(50, "cargador", 15.0, 100);
    tienda[1] = crear_prd(51, "audifonos", 25.5, 50);
    mostrar(tienda, m);
    liberar_invt(tienda, m);

    return 0;
}