#ifndef ORDENAMIENTOS_HPP
#define ORDENAMIENTOS_HPP
#include <iostream>
using namespace std;

void iniciaLista(int *arreglo, int tam){
    cout << "\nLlenando lista..." << endl;
    for (int i = 0; i < tam; i++){
        cout << "\n Dame valor " << "["<<i + 1<<"]: ";
        cin >> arreglo[i];
    }
}

void imprimeLista(int *arreglo, int tam){
    cout << "\nImprimiendo lista original" << endl;
    for (int i = 0; i < tam; i++){
        cout << "\n[""Posicion: " << i  << "]- Numero: " << arreglo[i] << endl;
    }
}
void ordenamientoIntercambio(int *arreglo, int tam){
    int aux = 0;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam - 1; j++) {
            if (arreglo[i] > arreglo[j]){
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
    cout << "\n_________________________" << endl;
    cout << "Imprimiendo datos ordenados..." << endl;
    for (int k = tam - 1; k >= 0 ; k--){
        cout << "\n[""Posici\xA2n: " << k << "]- El valor ordenado es: " << arreglo[k] << endl;
    }
}

void ordenamientoSeleccion(int *arreglo, int tam){
    int menor, aux, ind;
    for(int i = 0; i < tam - 1; i++){
        menor = arreglo[i];
        ind = i;
        for(int j = i + 1; j < tam; j++){
            if (menor > arreglo[j]){
                menor = arreglo[j];
                ind = j;
            }
        }
        aux = arreglo[i];
        arreglo[i] = menor;
        arreglo[ind] = aux;
    }
    cout << "\n______________________" << endl;
    cout << "Imprimiendo datos ordenados..." << endl;
    for (int k = 0; k < tam ; k++){
        cout << "\n[""Posici\xA2n: " << k << "]- El valor ordenado es: " << arreglo[k] << endl;
    }
}

void ordenamientoInsercion(int *arreglo, int tam){
    int j, aux;
    for(int i = 1; i < tam; i++){
        aux = arreglo[i];
        for( j = i - 1; j >= 0 && aux < arreglo[j]; j--){
            arreglo[j + 1] = arreglo[j];
        }
        arreglo[j + 1] = aux;
    }
    cout << "\n______________________" << endl;
    cout << "Imprimiendo datos ordenados..." << endl;
    for (int k = 0; k < tam ; k++){
        cout << "\n[""Posici\xA2n: " << k << "]- El valor ordenado es: " << arreglo[k] << endl;
    }
}

void ordenamientoBurbuja(int *arreglo, int tam){
    int aux;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if (arreglo[j] > arreglo[j + 1]){
                aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
    cout << "\n___________________________" << endl;
    cout << "Imprimiendo datos ordenados..." << endl;
    for (int k = 0; k < tam ; k++){
        cout << "\n[""Posici\xA2n: " << k << "]- El valor ordenado es: " << arreglo[k] << endl;
    }
}
#endif //ORDENAMIENTOS_HPP