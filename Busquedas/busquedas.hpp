#ifndef TAREA09_BUSQUEDAS_HPP
#define TAREA09_BUSQUEDAS_HPP
#include <iostream>
using namespace std;

void busquedaSecuencial(int *a, int tam, int valor){
    int i = 0;
    while(i < tam && a[i] != valor){
        i++;
    }
    if (i > tam - 1){
        cout << "\nEl numero --> " << valor << " no esta en la lista" << endl;
    } else {
        cout << "\nEl numero buscado -> " << a[i] << " esta en la posicion: " << i;
    }
}

void busquedaBinaria(int *b, int tam, int valor){
    int inf = 0, sup = tam - 1;
    int medio;
    do {
        medio = (inf + sup) / 2;
        if (valor > b[medio]){
            inf = medio + 1;
        }
        if (valor < b[medio]){
            sup = medio - 1;
        }
    } while (valor != b[medio] && inf <= sup);
    if (valor == b[medio]){
        cout << "\nEl valor -> " << b[medio] << " esta en la posicion: " << medio << endl;
    } else {
        cout << "\nEl valor -> " << valor << " no esta en la lista" << endl;
    }

}
#endif