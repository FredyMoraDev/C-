#include <iostream>
#define N 4

//Se declara la estructura tipo global, para que funcione en todas las funciones.
struct s_caja{
    int elemento;
    s_caja *siguiente;
    s_caja *anterior;
};
using namespace std;
int main() {
    int cont = 1;
    s_caja *p, *q;
    p = NULL;
    q = NULL;
    int opc;

      do {
            cout << "Listas Ligadas " << endl;
            cout << "1.- Ejercicio 1" << endl;
            cout << "2.- Ejercicio 2" << endl;
            cout << "3.- Ejercicio 3" << endl;
            cout << "4.- Ejercicio 4" << endl;
            cout << "5.- Salir" << endl;
            cout << "Indique su opcion: ";
            cin >> opc;

            switch (opc) {

                case 1:
                        for (int i = 0; i < N; i++) {
                        q = new s_caja;
                        q->elemento = i;
                        q->siguiente = q;
                        if (p == NULL) p = q;
                        q->siguiente = p->siguiente;
                        p->siguiente = q;
                        }
                    //Proceso

                    while (q != NULL) {
                        cout << "la caja " << cont << " vale: " << q->elemento << endl;
                        q = q->siguiente;
                        cont++;
                    }
                    //eliminar memoria
                    //eliminar memoria
                    q = p;
                    while (q != NULL) {
                        p = q->anterior;
                        delete q;
                        q = p;
                    }
                    break;

                case 2:
                    for (int i = 0; i < N; i++) {
                        q = new s_caja;
                        q->elemento = i;
                        q->siguiente = p;
                        q->anterior = NULL;
                        if (p != NULL)
                            p->anterior = q;
                            p = q;
                    }
                    //Proceso

                    while (q != NULL) {
                        cout << "la caja " << cont << " vale: " << q->elemento << endl;
                        q = q->anterior;
                        cont++;
                    }
                    //eliminar memoria
                    q = p;
                    while (q != NULL) {
                        p = q->anterior;
                        delete q;
                        q = p;
                    }
                    break;
                case 3:

                    for(int i = 0; i < N; i++) {
                        q = new s_caja;
                        q->elemento = i;
                        q->siguiente = p;
                        p = q;

                        int j = 0;
                        q = p;
                        while (q != NULL) {
                            cout << " La caja p "<< j << endl;
                            cout << " El elemento es: " << q->elemento << endl;
                            cout << "_____________"<<endl;
                            q = q->siguiente;
                            j++;
                        }
                        while (p!= NULL){
                            q = p->siguiente;
                            delete p;
                            p = q;
                        }
                    }
                    break;
                case 4:
                    for(int i = 0; i < N; i++){
                        q = new s_caja;
                        q->elemento = i;
                        q ->siguiente = p;
                        q->anterior = NULL;
                        if (p!=NULL){
                            p->anterior = q;
                        }
                        p=q;
                    }
                        while (q !=NULL) {
                            cout << "____________________" << endl;
                            cout << "caja p " << p << endl;
                            cout << "caja q " << q << endl;
                            cout << "caja q enlaza " << q->siguiente << endl;
                            cout << "Elemento: " << q->elemento << endl;
                            q = q->siguiente;
                        }
                         q = p;
                        while (q != NULL){
                            q = q->siguiente;
                            delete p;
                        }


                    break;

                default:
                    cout << "\nEsa opcion no existe";
            }
        } while (opc > 5 || opc < 0);


        return 0;
    }