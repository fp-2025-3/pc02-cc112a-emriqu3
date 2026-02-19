#include <iostream>
#include <cstring>

using namespace std;

//estructura para cada cosa del pedido
struct Item {
    char* desc; 
    int cant;
    double pre;
};

//estructura del pedido
struct Pedido {
    int num;
    char* cli;
    Item* itms;
    int n;
};

//crear un item
Item nuevo_itm(const char* d, int c, double p) {
    Item it;
    it.cant = c;
    it.pre = p;
    it.desc = new char[strlen(d) + 1];
    strcpy(it.desc, d);
    return it;
}

//armar el pedido
Pedido* crear_pdr(int numero, const char* cliente, int cant) {
    Pedido* p = new Pedido;
    p->num = numero;
    p->n = cant;
    p->cli = new char[strlen(cliente) + 1];
    strcpy(p->cli, cliente);
    p->itms = new Item[cant];
    return p;
}

double calcular_total(Pedido* p) {
    double t = 0;
    for(int i = 0; i < p->n; i++) {
        t += (p->itms[i].cant * p->itms[i].pre);
    }
    return t;
}

//buscar el mas caro
Item* el_mas_caro(Pedido* p) {
    if (p->n == 0) return NULL;
    
    int pos_max = 0;
    for(int i = 1; i < p->n; i++) {
        if (p->itms[i].pre > p->itms[pos_max].pre) {
            pos_max = i;
        }
    }
    return &p->itms[pos_max];
}

void borrar_todo(Pedido* p) {
    for(int i = 0; i < p->n; i++) {
        delete[] p->itms[i].desc;
    }
    delete[] p->itms;
    delete[] p->cli;
    delete p;
}

void mostrar(Pedido* p) {
    cout << "pedido: " << p->num << endl;
    cout << "cliente: " << p->cli << endl;
    for(int i = 0; i < p->n; i++) {
        cout << "- " << p->itms[i].desc << " | " << p->itms[i].pre << endl;
    }
    cout << "total: " << calcular_total(p) << endl;
}

int main() {
    cout << "CASO 1" << endl;
    Pedido* p1 = crear_pdr(101, "carlos perez", 3);
    p1->itms[0] = nuevo_itm("laptop", 1, 1000.0);
    p1->itms[1] = nuevo_itm("mouse", 2, 50.0);
    p1->itms[2] = nuevo_itm("teclado", 1, 300.0);

    mostrar(p1);

    Item* caro = el_mas_caro(p1);
    if (caro != NULL) {
        cout << "lo mas caro es: " << caro->desc << endl;
    }

    borrar_todo(p1);
    cout << endl;

    cout << "CASO 2" << endl;
    Pedido* p2 = crear_pdr(200, "maria lopez", 2);
    p2->itms[0] = nuevo_itm("pizza", 1, 45.0);
    p2->itms[1] = nuevo_itm("gaseosa", 2, 7.5);

    mostrar(p2);
    borrar_todo(p2);

    return 0;
}