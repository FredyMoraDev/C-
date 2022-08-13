#include <iostream>
#include "ordenamientos.hpp"




using namespace std;

int main() {
    int *arregloA;
    int opc = 0;
    int tam = 0;

    do {
        cout << "\nMENU DE OPCIONES: " << endl;
        cout << "1.- Ordenamiento por intercambio" << endl;
        cout << "2.- Ordenamiento por selecci\xA2n" << endl;
        cout << "3.- Ordenamiento por inserci\xA2n" << endl;
        cout << "4.- Ordenamiento burbuja" << endl;
        cout << "5.- Salir" << endl;
        cout << "\nIntroduzca su opci\xA2n: ";
        cin >> opc;

        switch (opc) {
            case 1:
                arregloA = new int[tam];
                cout << "\nDame el tama\xA4o del arreglo: ";
                cin >> tam;
                iniciaLista(arregloA, tam);
                imprimeLista(arregloA, tam);
                ordenamientoIntercambio(arregloA, tam);
                if (arregloA != NULL){
                    delete[] arregloA;
                }
                break;
            case 2:
                arregloA = new int[tam];
                cout << "\nDame el tama\xA4o del arreglo: ";
                cin >> tam;
                iniciaLista(arregloA, tam);
                imprimeLista(arregloA, tam);
                ordenamientoSeleccion(arregloA, tam);
                if (arregloA != NULL){
                    delete[] arregloA;
                }
                break;
            case 3:
                arregloA = new int[tam];
                cout << "\nDame el tama\xA4o del arreglo: ";
                cin >> tam;
                iniciaLista(arregloA, tam);
                imprimeLista(arregloA, tam);
                ordenamientoInsercion(arregloA, tam);
                if (arregloA != NULL){
                    delete[] arregloA;
                }
                break;
            case 4:
                arregloA = new int[tam];
                cout << "\nDame el tama\xA4o del arreglo: ";
                cin >> tam;
                iniciaLista(arregloA, tam);
                imprimeLista(arregloA, tam);
                ordenamientoBurbuja(arregloA, tam);
                if (arregloA != NULL){
                    delete[] arregloA;
                }
                break;
            case 5:
                cout << "\nPrograma finalizado con \x82xito" << endl;
                break;
            default:
                cout << "\nElija una opci\xA2n valida" << endl;
                break;
        }
    } while (opc != 5);

    return 0;
}