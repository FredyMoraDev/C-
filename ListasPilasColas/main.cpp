#include <iostream>
using namespace std;

struct computadora{
    char marca[30];
    char modelo[30];
    float precio;
    char tamanio[30];
    int ID;
    computadora *link;
};
struct computadora *p, *q, *caja_nueva,*caja_final,*caja_inicial;
void LlenarCola();
void ImprimeCola();
void Enqueue(computadora *caja_nueva);
void ImprimeCaja(computadora *p,computadora *q);
void Push(computadora *q);
computadora *HacerCaja();
computadora *pop();
void LlenarCaja();
void ImprimeLista(computadora *p, computadora *q);
bool otraCaja();
void LlenarLista();

int main() {
    p = NULL;
    q = NULL;
    caja_nueva = NULL;
    caja_final = NULL;
    caja_inicial = NULL;
    int opc, opc2;
    do {
        cout << " Ejercicios" << endl;
        cout << "1.- Lista Circular" << endl;
        cout << "2.- Pilas o Cola" << endl;
        cout << "3.- Salir" << endl;
        cout << "Indique su opcion: ";
        cin >> opc;
        switch (opc) {
            case 1:
                    LlenarLista();
                    ImprimeLista(p,q);
                break;
            case 2:
                do {
                    cout << "1.- Pila" << endl;
                    cout << "2.- Cola" << endl;
                    cout << "3.- Salir al menu principal" << endl;
                    cout << "Indique su opcion: ";
                    cin >> opc2;
                    switch (opc2) {
                        case 1:
                                LlenarCaja();
                                ImprimeCaja(p,q);
                             break;
                        case 2:
                                LlenarCola();
                                ImprimeCola();
                            break;
                        case 3:
                            cout << "Regresando al menu principal" << endl;
                            break;
                        default:
                            cout << "opcion no valida" << endl;
                            break;
                    }
                } while (opc2 != 3);
                break;
            default:
                cout << "\nEsa opcion no existe";
                break;
        }
    }while (opc != 3);
    return 0;
}
void LlenarLista() {
            while (otraCaja()) {
                q = new computadora;
                cout << "\nDigita el ID: " << endl;
                cin >> q->ID;
                cout << "\nDigita tu marca: " << endl;
                cin >> q->marca;
                cout << "Digita el modelo: " << endl;
                cin >> q->modelo;
                cout << "Digita el precio: " << endl;
                cin >> q->precio;
                cout << "Digita la cantidad de computadoras: " << endl;
                cin >> q->tamanio;
                q->link = q;
                    if (p == NULL) {
                     p = q;
                    }
                q->link = p->link;
                p->link = q;
            }
}

void ImprimeLista(computadora *p, computadora *q){
        int i = 0;
        p = q;
        while (p->ID >= 1) {
            cout << "*****Computadora*****" << endl;
            cout << "ID: " << q->ID << endl;
            cout << "Marca: " << q->marca << endl;
            cout << "Modelo: " << q->modelo << endl;
            cout << "Precio: " << q->precio << endl;
            cout << "Cantidad : " << q->tamanio << endl;
            q = q->link;
            delete p;
            p = q;
        }
}

bool otraCaja(){
    char c;
    cout << "Deseas agregar una caja? Presiona 's': " << endl;
    cin >> c;
    return (c == 'S' || c == 's');
}

void LlenarCaja(){
    while (otraCaja()){
        Push(HacerCaja());
    }
}

computadora *HacerCaja(){
    q = new computadora;
    if (q == NULL){
        return NULL;
    }
    cout << "\nDigita el ID: " << endl;
    cin >> q->ID;
    cout << "\nDigita tu marca: " << endl;
    cin >> q->marca;
    cout << "Digita el modelo: " << endl;
    cin >> q->modelo;
    cout << "Digita el precio: " << endl;
    cin >> q->precio;
    cout << "Digita la cantidad de computadoras: " << endl;
    cin >> q->tamanio;
    return q;
}
void Push(computadora *q){
    if (q == NULL){
        return;
    }
    q->link = p;
    p = q;
}

computadora *pop(){
    q = p;
    if (p != NULL){
        p = p->link;
    }
    return q;
}

void ImprimeCaja(computadora *p,computadora *q){
    p = q;
    for (;p != NULL;){
        cout << "*****Computadora*****" << endl;
        cout << "ID: " << q->ID << endl;
        cout << "Marca: " << q->marca << endl;
        cout << "Modelo: " << q->modelo << endl;
        cout << "Precio: " << q->precio << endl;
        cout << "Cantidad : " << q->tamanio << endl;
        q = q->link;
        delete p;
        p = q;
    }
}
void LlenarCola(){
    while (otraCaja()){
        Enqueue(HacerCaja());
    }
}

void Enqueue(computadora *caja_nueva){
    if (caja_nueva == NULL){
        return;
    }
    caja_nueva->link = NULL;
    if (caja_final == NULL){
        caja_inicial = caja_nueva;
    }
    else {
        caja_final->link = caja_nueva;
    }
    caja_final = caja_nueva;
}

computadora *Dequeue() {
    if (caja_inicial == NULL) {
        return NULL;
    }
    computadora *q;
    q = caja_inicial;
    caja_inicial = caja_inicial->link;
    q->link = NULL;
    if (caja_inicial == NULL) {
        caja_final = NULL;
        return q;
    }
}

void ImprimeCola(){
    caja_nueva = caja_inicial;
    while ((caja_nueva = Dequeue()) != NULL){
        cout << "*****Computadora*****" << endl;
        cout << "ID: " << caja_nueva->ID << endl;
        cout << "Marca: " << caja_nueva->marca << endl;
        cout << "Modelo: " << caja_nueva->modelo << endl;
        cout << "Precio: " << caja_nueva->precio << endl;
        cout << "Cantidad : " << caja_nueva->tamanio << endl;
        caja_nueva = caja_nueva->link;
        delete caja_nueva;
    }
}