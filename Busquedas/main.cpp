#include <iostream>
#include <locale.h>
#include "busquedas.hpp"
using namespace std;

int tam = 0 ;

int main() {
    setlocale(LC_CTYPE, "");
    int *matriz1;
    int *matriz2;
    int *matriz3, t = 0;
    int opcion = 0, val = 0;

    do {
        cout << "\nMenu: " << endl;
        cout << "1.- Busqueda secuencial" << endl;
        cout << "2.- Busqueda binaria " << endl;
        cout << "3.- Busqueda binaria 2" << endl;
        cout << "4.- Salir" << endl;
        cout << "\nIndica tu opcion: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                matriz1 = new int[tam];
                cout << "Dame tamannio de la lista: "<< endl;
                cin >> tam;
                for(int i = 0; i < tam; i++){
                    cout << "\n[""Posicion: "<< i << "]- Dame un numero aleatorio: ";
                    cin >> matriz1[i];
                }
                cout << "\nQue valor buscas?: ";
                cin >> val;

                busquedaSecuencial(matriz1, tam, val);
                if (matriz1 != NULL){
                    delete[] matriz1;
                }
                break;

            case 2:
                matriz2 = new int[tam];
                cout << "Dame tamannio de la lista: "<< endl;
                cin >> tam;
                cout << "Nota: Ingresa los datos de forma ordenada " << endl;
                for(int i = 0; i < tam; i++){
                    cout << "\n[""Posicion: " << i << "]- Dame un numero en orden: ";
                    cin >> matriz2[i];
                }
                cout << "\nQue valor buscas?: ";
                cin >> val;
                busquedaBinaria(matriz2, tam, val);
                if (matriz2 != NULL){
                    delete[] matriz2;
                }
                break;

            case 3:
                cout << "Dame el tamanio del arreglo: ";
                cin >> t;
                matriz3 = new int[t];
                cout << "Nota: Ingresa los datos de forma ordenada " << endl;
                for(int i = 0; i < t; i++){
                    cout << "\n[""Posicion: " << i << "]- Dame un numero en orden: ";
                    cin >> matriz3[i];
                }
                cout << "\nQue valor buscas?: ";
                cin >> val;
                busquedaBinaria(matriz3, t, val);
                if (matriz3 != NULL){
                    delete[] matriz3;
                }
                break;

            case 4:
                cout << "\nPrograma finalizado con exito" << endl;
                break;

            default:
                cout << "\nOpcion no valida" << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}