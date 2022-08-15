#include <iostream>

using namespace std;
struct videojuego{
    int id;
    char nombre[30];
    int cantidad;
    float precio;
    videojuego *link;
};
struct videojuego *ini, *aux2;
//Prototipos
void LeerMatrizE(int arreglo[2][5][3]);
void LeerMatrizD(int ***arreglo, int n, int m, int l);
void ImprimirMatrizD(int ***arreglo, int n, int m, int l);
void ImprimirMatrizE(int arreglo[2][5][3]);
void ImprimirCaja(videojuego *ini, videojuego *aux2);
void ImprimirCajaC( videojuego *p, videojuego *q);
void LlenarCaja();
void LlenarCajaC();
bool otraCaja();
void LimpiarArregloG(double *arregloG);
void LimpiarArregloQ(double **arregloQ,int n2);

int main() {
    int opc, opc2;
    //Variables ejercicios AP.
    int *arreglo, tam, aux, i = 0, j = 0, *z1;
    float *x, *y, *z, n, m;
    //Variables ejercicios arreglos dinámicos.
    int n1, n2, m2, l2;
    int arregloA[2][5][3], ***arregloB;
    double *arregloG, **arregloQ;
    //Variables lista ligada.
    struct videojuego *ini, *aux2;
    float aum = 0.15;
    ini = NULL;
    aux2 = NULL;

    do {
        cout << "__________________________________" << endl;
        cout << "1.- Apuntadores" << endl;
        cout << "2.- Arreglos din\xA0micos" << endl;
        cout << "3.- Lista ligada sencilla" << endl;
        cout << "4.- Lista ligada circular" << endl;
        cout << "5.- Salir" << endl;
        cout << "__________________________________" << endl;
        cout << "Introduzca su opci\xA2n: ";
        cin >> opc;
        switch (opc) {
            case 1:
                do {
                    cout << "__________________________________" << endl;
                    cout << "\nApuntadores" << endl;
                    cout << "1.- Ejercicio 1 " << endl;
                    cout << "2.- Ejercicio 2 " << endl;
                    cout << "3.- Salir al men\xA3 principal  " << endl;
                    cout << "__________________________________" << endl;
                    cout << "Elige una Opci\xA2n: ";
                    cin >> opc2;
                    switch (opc2) {
                        case 1:
                            //variables tipo apuntador
                            x = &m;
                            y = &m;
                            z = &n;
                            //variables numeros reales
                            m = 45;
                            n = 10;
                            m = 3*m + 2**z;

                            cout << "El valor de n es: \n" << n << endl;
                            cout << "El valor de m es: \n" << m << endl;
                            break;

                        case 2:
                            //Se le pide al usuario numero total que tiene el arreglo
                            cout << "Ingresa el total de n\xA3meros en el arreglo: "<< endl;
                            cin >> tam;
                            //Alojamiento de memoria arreglo entero tipo estatico
                            arreglo = new int[tam];
                            //Se piden los datos usando while y se llena el arreglo
                            while (i < tam){
                                cout <<"\nDame un valor para la posici\xA2n" "[" << i + 1 << "]:"<< endl;
                                cin >> arreglo[i];
                                i++;
                            }
                            //Buscando el mayor valor y asigarnarlo a z en este caso z1 por que me marcaban algunos errores
                            for(i = 0; i < tam; i++){
                                for (j = 0; j - 1 < tam; j++){
                                    if (arreglo[j] < arreglo[j + 1]){
                                        aux = arreglo[j];
                                        arreglo[j] = arreglo[j + 1];
                                        arreglo[j + 1] = aux;
                                        z1 = &aux;
                                    }
                                }
                            }
                            //Imprimiendo el valor de z1
                            cout << "\nEl valor de z es: \n" << z1 << endl;
                            //Asignando a z la direccion de memoria de &z1
                            cout << "\nLa direcci\xA2n de memoria de z es: " << &z1 << endl;
                            //Imprimiendo el valor del apuntador z
                            cout << "\nEl valor del apuntador z es: " << *z1 << endl;
                            break;

                        case 3:
                            cout << "Regresando al men\xA3 principal\n\n\n" << endl;
                            break;
                        default:
                            cout << "Opci\xA2n no v\xA0lida, elige otra"<< endl;
                            break;
                    }
                } while (opc2 != 3);
                break;
            case 2:
                do {
                    cout << "__________________________________" << endl;
                    cout << "\nArreglos Din\xA0micos" << endl;
                    cout << "1.- Ejercicio 1 " << endl;
                    cout << "2.- Ejercicio 2 " << endl;
                    cout << "3.- Salir al men\xA3 principal  " << endl;
                    cout << "__________________________________" << endl;
                    cout << "Elige una Opci\xA2n: "<< endl;
                    cin >> opc2;
                    switch (opc2) {
                        case 1:
                            //pedir tamaño del arreglo para los arreglos G y Q
                            cout << "\nDame el tama\xA4o del arreglo G: "<< endl;
                            cin >> n1;
                            //Alojamiento de memoria del arreglo G.
                            arregloG = new double[n1];
                            cout << "\nDame el tama\xA4o de la fila del arreglo Q: "<< endl;
                            cin >> n2;
                            cout << "\nDame el tama\xA4o de la columna del arreglo Q: "<< endl;
                            cin >> m2;
                            //Alojamiento de memoria del arreglo Q.
                            arregloQ = new double *[n2];
                            for (i = 0; i < n2; i++){
                                arregloQ[i] = new double[m2];
                            }
                            //Se piden datos al arreglo G.
                            cout << "Datos para el arreglo G" << endl;
                            for(i = 0; i < n1; i++){
                                cout << "\nDame un valor para la posici\xA2n""[" << i + 1 << "]:"<< endl;
                                cin >> arregloG[i];
                                arregloG[i] =  arregloG[i] * 4;
                            }
                            //Se piden los datos del arreglo Q.
                            cout << "\nDatos para el arreglo Q" << endl;
                            for(i = 0; i < n2; i++){
                                for(j = 0; j < m2; j++){
                                    cout << "\n[" << i + 1 <<"][" << j + 1 <<"]- Dame un n\xA3mero: "<< endl;
                                    cin >> arregloQ[i][j];
                                    arregloQ[i][j] = arregloQ[i][j] + 3;
                                }
                            }
                            //Despliegue de datos del arreglo G.
                            cout << "__________________________________" << endl;
                            cout << "Datos del arreglo G" << endl;
                            for(i = 0; i < n1; i++){
                                cout << "Arreglo original: " << arregloG[i] << endl;
                                cout << "El resultado del n\xA3mero multiplicado por 4 es: " << arregloG[i] * 4 << endl;
                                cout << "\n";
                            }
                            //Despliegue de datos del arreglo Q.
                            cout << "__________________________________" << endl;
                            cout << "Datos del arreglo Q" << endl;
                            for(i = 0; i < n2; i++){
                                for(j = 0; j < m2; j++){
                                    cout << "Arreglo original: " << arregloQ[i][j] << endl;
                                    cout << "El resultado del n\xA3mero sumado mas 3 es: " << arregloQ[i][j] + 3 << endl;
                                    cout << "\n";
                                }
                            }
                            //Desaljamiento de memoria del arreglo G.
                            LimpiarArregloG( arregloG);
                            //Desalojamiento de memoria del arreglo Q.
                            LimpiarArregloQ(arregloQ,n2);
                            break;
                        case 2:
                            do {
                                cout << "__________________________________" << endl;
                                cout << "Arreglo multidimensional" << endl;
                                cout << "1.- Memoria est\xA0tica" << endl;
                                cout << "2.- Memoria din\xA0mica" << endl;
                                cout << "3.- Regresar al men\xA3 anterior" << endl;
                                cout << "__________________________________" << endl;
                                cout << "Opci\xA2n: "<< endl;
                                cin >> opc2;
                                switch (opc2) {
                                    case 1:
                                        LeerMatrizE(arregloA);
                                        ImprimirMatrizE(arregloA);
                                        break;

                                    case 2:
                                        LeerMatrizD(arregloB, n2, m2, l2);
                                        ImprimirMatrizD(arregloB, n2, m2, l2);

                                        break;
                                    case 3:
                                        cout << "Regresando al men\xA3 principal\n\n\n" << endl;
                                        break;
                                    default:
                                        cout << "Elige una opci\xA2n v\xA0lida"<< endl;
                                        break;
                                }
                            } while (opc2 != 3);
                            break;
                        default:
                            cout << "Error, elige una opci\xA2n v\xA0lida"<< endl;
                            break;
                    }
                } while (opc2 != 3);
                break;
            case 3:
                LlenarCaja();
                ImprimirCaja(ini, aux2);
                break;
            case 4:
                LlenarCajaC();
                ImprimirCajaC(ini, aux2);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Introduzca una opci\xA2n v\xA0lida"<< endl;
                break;
        }
    } while (opc != 5);
    return 0;
}

void LeerMatrizE(int arreglo[2][5][3]){
    int i, j, k;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 3; k++){
                cout << "\n[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]- Dame un n\xA3mero: "<< endl;
                cin >> arreglo[i][j][k];
                cout << "\n";
            }
        }
    }
}

void LeerMatrizD(int ***arreglo, int n, int m, int l){
    int i, j, k;
    cout << "Dame el tama\xA4o de la fila: "<< endl;
    cin >> n;
    cout << "Dame el tama\xA4o de la columna: "<< endl;
    cin >> m;
    cout << "Dame el tama\xA4o de la dimensi\xA2n: "<< endl;
    cin >> l;
    //Alojamiento de memoria.
    arreglo = new int **[n];
    for(i = 0; i < n; i++){
        arreglo[i] = new int*[m];
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            arreglo[i][j] = new int[l];
        }
    }
    //Se piden los datos.
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            for(k = 0; k < l; k++){
                cout << "\n[" << i + 1 << "][" << j + 1 << "][" << k + 1 <<"]- Dame un n\xA3mero: "<< endl;
                cin >> arreglo[i][j][k];
            }
        }
    }
    ImprimirMatrizD(arreglo, n, m, l);
}

void ImprimirMatrizD(int ***arreglo, int n, int m, int l){
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            for(k = 0; k < l; k++){
                cout << "\n[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]- El n\xA3mero es: " << arreglo[i][j][k] << endl;
            }
        }
    }
}

void ImprimirMatrizE(int arreglo[2][5][3]){
    int i, j, k;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 3; k++){
                cout << "[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]- El n\xA3mero es: " << arreglo[i][j][k] << endl;
            }
        }
    }
}
bool otraCaja(){
    int c;
    cout << "Presiona 1 para agregar otra caja 2 para ya no: "<< endl;
    cin >> c;
    return c == 1;
}

void LlenarCaja(){
    while(otraCaja()){
        aux2 = new videojuego;
        cout << "____________Video Juego_________" << endl;
        cout << "Dame el ID: "<< endl;
        cin >> aux2->id;
        cout << "Dame el nombre: "<< endl;
        cin >> aux2->nombre;
        cout << "Dame la cantidad: "<< endl;
        cin >> aux2->cantidad;
        cout << "Dame el precio: "<< endl;
        cin >> aux2->precio;
        aux2->link = ini;
        ini = aux2;
    }
    ImprimirCaja(ini,aux2);
}
void ImprimirCaja(videojuego *ini, videojuego *aux){
    float aum = 1.15;
    ini = aux2;
    for(;ini != NULL;){
        cout << "_______Video Juego________" << endl;
        cout << "ID: " << aux2->id << endl;
        cout << "Nombre: " << aux2->nombre << endl;
        cout << "Cantidad: " << aux2->cantidad << endl;
        cout << "Precio: " << aux2->precio << endl;
        aux2->precio = aux2->precio * aum;
        cout << "Precio con aumento del 15%: " << aux2->precio << endl;
        aux2 = aux2->link;
        delete ini;
        ini = aux2;
    }
}

void LlenarCajaC(){
    while(otraCaja()){
        aux2 = new videojuego;
        cout << "_________Video juego________" << endl;
        cout << "Dame el ID: "<< endl;
        cin >> aux2->id;
        cout << "Dame el nombre: "<< endl;
        cin >> aux2->nombre;
        cout << "Dame la cantidad: "<< endl;
        cin >> aux2->cantidad;
        cout << "Dame el precio: "<< endl;
        cin >> aux2->precio;
        aux2->link = aux2;
        if(ini == NULL){
            ini = aux2;
        }
        aux2->link = ini->link;
        ini->link = aux2;
    }
    ImprimirCajaC(ini, aux2);
}

void ImprimirCajaC(videojuego *p, videojuego *q) {
    q = p;
    for (; p->id >= 1;) {
        p = q;
        cout << "_______________________" << endl;
        cout << "ID: " << aux2->id << endl;
        cout << "Nombre: " << aux2->nombre << endl;
        cout << "Cantidad: " << aux2->cantidad << endl;
        cout << "Precio: " << aux2->precio << endl;
        cout << "_______________________" << endl;
        q = q->link;
        delete p;
        p = q;
    }
}
void LimpiarArregloG(double *arregloG) {
    if (arregloG != NULL) {
        delete[] arregloG;
    }
}
void LimpiarArregloQ(double **arregloQ,int n2){
    if(arregloQ != NULL){
        for(int i = 0; i < n2; i++){
            delete[] arregloQ[i];
        }
        delete[] arregloQ;
    }
}