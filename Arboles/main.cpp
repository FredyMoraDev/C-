#include <iostream>
using namespace std;

struct equipos{
    int ID, puntos;
    char nombre[25];
    char ciudad[25];
    equipos *izquierda;
    equipos *derecha;
};
bool hayHijo(int n);
equipos *contruyeArbol();
void imprimeArbolPreOrden(equipos *p);
void imprimeArbolPostOrden(equipos *p);
void imprimeArbolEntreOrden(equipos *p);
void eliminaNodos(equipos *p);
int dameNivel(equipos *p);
struct equipos *p;

int main() {
    p = NULL;
    int opcion = 0;

    do {
        cout << "MENU: " << endl;
        cout << "1.- Llenar arbol" << endl;
        cout << "2.- Imprimir arbol pre-orden" << endl;
        cout << "3.- Imprimir arbol post-orden" << endl;
        cout << "4.- Imprimir arbol entre-orden" << endl;
        cout << "5.- Numero de niveles" << endl;
        cout << "6.- Salir" << endl;
        cout << "\nIndique su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                p = contruyeArbol();
                break;
            case 2:
                imprimeArbolPreOrden(p);
                break;
            case 3:
                imprimeArbolPostOrden(p);
                break;
            case 4:
                imprimeArbolEntreOrden(p);
                break;
            case 5:
                cout << "El numero de niveles es: " << dameNivel(p) << endl;
                break;
            case 6:
                cout << "Finalizacion completa";
                break;
            default:
                cout << "Elige una opcion valida.";
                break;
        }
    } while (opcion != 6);

    return 0;
}
bool hayHijo(int n){
    char c;
    char *lado[2] = {"izquierda", "derecha"};
    cout << "Hay hijo " << lado[n] << "?: " << endl;
    cin >> c;
    return c == 'S' || c == 's';
}

void eliminaNodos(equipos *p){
    if (p == NULL){
        return;
    }
    eliminaNodos(p->izquierda);
    eliminaNodos(p->izquierda);
    delete p;
}

int dameNivel(equipos *p){
    if (p == NULL){
        return 0;
    }
    return 1 + max(dameNivel(p->izquierda), dameNivel(p->derecha));
}

equipos *contruyeArbol(){
    equipos *raiz;
    raiz = new equipos;
    cout << "                      " << endl;
    cout << "Digita la posicion del equipo: ";
    cin >> raiz->ID;
    cout << "Digita el nombre del equipo:  ";
    cin >> raiz->nombre;
    cout << "Digita la ciudad del equipo: ";
    cin >> raiz->ciudad;
    cout << "Digita los puntos del equipo: "; //Entero.
    cin >> raiz->puntos;
    raiz->izquierda = NULL;
    raiz->derecha = NULL;
    if (hayHijo(0)){
        raiz->izquierda = contruyeArbol();
    }
    if (hayHijo(1)){
        raiz->derecha = contruyeArbol();
    }
    return raiz;
}

void imprimeArbolPreOrden(equipos *p){
    if (p == NULL){
        return;
    }
    cout << "_____________________" << endl;
    cout << "Posicion: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Ciudad: " << p->ciudad << endl;
    cout << "Puntos: " << p->puntos << endl;
    cout << "________________________" << endl;
    imprimeArbolPreOrden(p->izquierda);
    imprimeArbolPreOrden(p->derecha);
    eliminaNodos(p);
}

void imprimeArbolPostOrden(equipos *p){
    if (p == NULL){
        return;
    }
    imprimeArbolPostOrden(p->izquierda);
    imprimeArbolPostOrden(p->derecha);
    cout << "_____________________" << endl;
    cout << "Posicion: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Ciudad: " << p->ciudad << endl;
    cout << "Puntos: " << p->puntos << endl;
    cout << "________________________" << endl;
    eliminaNodos(p);
}

void imprimeArbolEntreOrden(equipos *p){
    if (p == NULL){
        return;
    }
    imprimeArbolEntreOrden(p->izquierda);
    cout << "_____________________" << endl;
    cout << "Posicion: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Ciudad: " << p->ciudad << endl;
    cout << "Puntos: " << p->puntos << endl;
    cout << "________________________" << endl;
    imprimeArbolEntreOrden(p->derecha);
    eliminaNodos(p);
}