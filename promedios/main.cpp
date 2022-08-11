#include <iostream>

using namespace std;
float promedio();
int main() {
    promedio();
    return 0;
}

float promedio(){
    float promedio = 0, n = 0, cantidad = 0, suma = 0;
    cout <<"Cuantas cantidades vas a ingresar?" << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Ingresa la cantidad " << (i+1) << endl;
        cin >> cantidad;
        suma = suma + cantidad;
    }
    promedio = suma / n;
    cout << "El promedio de las " << n << "  cantidades es: "<< promedio << endl ;
    return promedio;
}