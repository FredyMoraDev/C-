#include <iostream>
#include <fstream>

using namespace std;
double Far_to_Cent(double a);
float mayor(float *v);

int main() {
    ofstream archivo;
    int opcion, *a, *b, *c, i, j, k, l = 0;
    int *pointer_int, ***arregloC2, a2, x = 7;
    int *arreglo, fil, col, dim, t, *datos, arregloC[2][5][3];
    int matriz[10][10], **matriz2, dim2;
    float *pointer_float, b2, y = 4.0,  F[10];
    double *p1, *p2, **p3, a1 = 100, b1 = 200, x2;

    do {
        cout << "____________________________________" << endl,
        cout << "1.- Apuntadores - Ejercicio 1" << endl,
        cout << "2.- Apuntadores - Ejercicio 2" << endl;
        cout << "3.- Apuntadores - Ejercicio 3" << endl;
        cout << "4.- Alojamiento dinamico de memoria - Ejercicio 1" << endl;
        cout << "5.- Alojamiento dinamico de memoria - Ejercicio 2" << endl;
        cout << "6.- Arreglos dinamicos - Ejercicio 1" << endl;
        cout << "7.- Arreglos dinamicos - Ejercicio 2" << endl;
        cout << "8.- Funciones - Ejercicio 1" << endl;
        cout << "9.- Funciones - Ejercicio 2" << endl;
        cout << "10.- Salir" << endl;

        cout << "Introduza su opcion: "<<endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                a = &i;
                b = &i;
                c = &j;

                i = 4;
                j = 3;

                *a = 4 + 4 + 3;

                cout << "El valor de i es: " << i << endl;
                cout << "El valor de j es: " << j << endl;
                cout << "\n"<<endl;

                break;
            case 2:
                p1 = &a1;
                p2 = &b1;
                p3 = &p2;

                a1 = *p1 + 2 * b1;
                *p2 = 3 * a1 + 3 * **p3;
                *p3 = &b1;
                p3 = &p2;
                *p3 = &a1;

                **p3 = *p2 - *p1 * b1;

                cout << "El valor de a es: " << a1 << endl;
                cout << "El valor de b es: " << b1 << endl;

                break;
            case 3:
                //El apuntador a entero se carga con la dirección de x.
                pointer_int = &x;

                cout << "El contenido de x es: " << x << endl;
                cout << "La direccion de x es: " << &x << endl;
                cout << "El pointer_int contiene: " << pointer_int << endl;
                cout << "El pointer_int apunta a: " << *pointer_int << endl;

                //El apuntador a float se carga con la dirección de y.
                pointer_float = &y;

                cout << "El contenido de y es: " << y << endl;
                cout << "La direccion de y es: " << &y << endl;
                cout << "El pointer_float contiene: " << pointer_float << endl;
                cout << "El pointer_float apunta a: " << *pointer_float << endl;

                //a se carga con lo que apunta pointer_int.
                a2 = x;

                //b se carga con lo que apunta pointer_float.
                b2 = y;

                //Despliegue de a y b.
                cout << "El valor de a es: " << a2 << endl;
                cout << "El valor de b es: " << b2 << endl;

                break;
            case 4:
                cout << "El alojamiento de memoria dinamica sirve para que el programa "
                        "sea mas eficiente y que este le pida al usuario n de espacio,"
                        " esto sirve para que no se desperdicie la memoria RAM"
                        "y que al mismo tiempo consuma la necesaria anteriormente solicitada al usuario" << endl;


                cout << "Dame el tamanio del arreglo: " << endl;
                cin >> t;

                //Alojamiento de memoria.
                arreglo = new int[t];

                //Se piden los datos.
                for (i = 0; i < t; i++) {
                    cout << "\nDame un numero entero para la posicion  " <<i+1<<":"<<endl ;
                    cin >> arreglo[i];
                }

                //Se imprimen los datos.
                for (j = 0; j < t; j++) {
                    cout <<"El numero en la posicion " << j+1<< " es: " << arreglo[j]<<endl;
                }

                //Desalojamiento de memoria.
                if (arreglo != NULL) {
                    delete[] arreglo;
                }

                break;
            case 5:

                cout << "Dame el tamanio del arreglo: "<<endl;
                cin >> t;

                //Alojamiento de memoria.
                datos = new int[t];

                for (int i = 0; i < t; i++) {
                    cout << "\nDame un numero entero para la posicion  " <<i+1<<":"<<endl ;
                    cin >> datos[i];
                }

                archivo.open("C:\\Users\\crack\\Documents\\repositorio\\C++\\apuntadoresAlojamientoArreglos\\datos.txt",
                        ios::out);

                archivo << "\t Numero de datos del arreglo: " << t << endl;

                for (j = 0; j < t; j++) {
                    archivo <<"\n\tEl numero en la posicion " << j+1<< " es: " << datos[j] << endl;
                    archivo << "\n\tEl resultado del numero multiplicado por 2 es: " << datos[j] * 2<<endl;

                }
                for (l = t - 1; l >= 0; l--) {
                    archivo << "\n\tOrden inverso: " << datos[l]<<endl;
                }

                if (archivo.fail()) {
                    cout << "No se pudo crear el archivo";
                    exit(1);
                }
                archivo.close();
                {
                    //Funcion para imprimir el archivo txt
                FILE *arch = fopen("C:\\Users\\crack\\Documents\\repositorio\\C++\\apuntadoresAlojamientoArreglos\\datos.txt","r");
                int c;
                while((c=fgetc(arch))!=EOF){
                    putchar(c);
                }
                cout << "\n" <<endl;
                if (datos != NULL) {
                    delete[] datos;
                }}

                break;
            case 6:
                cout << "1.- Estatica" << endl;
                cout << "2.- Dinamica" << endl;
                cout << "Introduzca su opcion: "<< endl ;
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        //Usando memoria estatica.
                        for (i = 0; i < 2; i++) {
                            for (j = 0; j < 5; j++) {
                                for (k = 0; k < 3; k++) {
                                    cout << "\n[" << i + 1 << "] [" << j + 1 << "] [" << k + 1
                                         << "]- Dame un valor entero: "<<endl;
                                    cin >> arregloC[i][j][k];
                                }
                            }
                        }

                        //Despliegue de datos.
                        for (i = 0; i < 2; i++) {
                            for (j = 0; j < 5; j++) {
                                for (k = 0; k < 3; k++) {
                                    cout << "\n[" << i + 1 << "] [" << j + 1 << "] [" << k + 1 << "]- El valor es: "
                                         << arregloC[i][j][k]<<endl;
                                }
                            }
                        }
                        break;
                    case 2:
                        //Usando memoria dinámica.
                        cout << "\nDame el tamanio de la fila: " << endl;
                        cin >> fil;

                        cout << "\nDame el tamanio de la columna: " << endl;
                        cin >> col;

                        cout << "\nDame el tamanio de la tercera dimension: " << endl;
                        cin >> dim;

                        //Alojamiento de memoria.
                        arregloC2 = new int **[fil];

                        for (i = 0; i < fil; i++) {
                            arregloC2[i] = new int *[col];
                        }

                        for (i = 0; i < fil; i++) {
                            for (j = 0; j < col; j++) {
                                arregloC2[i][j] = new int[dim];
                            }
                        }
                        //Pidiendo datos.
                        for (i = 0; i < fil; i++) {
                            for (j = 0; j < col; j++) {
                                for (k = 0; k < dim; k++) {
                                    cout << "\n[" << i + 1 << "] [" << j + 1 << "] [" << k + 1
                                         << "]- Dame valores enteros: " << endl;
                                    cin >> arregloC2[i][j][k];
                                }
                            }
                        }

                        //Despliegue de datos.
                        for (i = 0; i < fil; i++) {
                            for (j = 0; j < col; j++) {
                                for (k = 0; k < dim; k++) {
                                    cout << "\n[" << i + 1 << "] [" << j + 1 << "] [" << k + 1 << "]- El valor es: "
                                         << arregloC2[i][j][k]<<endl;
                                }
                            }
                        }

                        //Desalojamiento de memoria.
                        if (arregloC2 != NULL) {
                            for (i = 0; i < fil; i++) {
                                if (arregloC2[i] != NULL) {
                                    for (j = 0; j < col; j++) {
                                        if (arregloC2[i][j] != NULL) {
                                            delete[] arregloC2[i][j];
                                        }
                                        delete[] arregloC2[i];
                                    }
                                }
                                delete[] arregloC2;
                            }
                        }
                        break;
                    default:
                        cout << "\nEsa opcion no existe, elige otra.";
                }
            case 7:
                cout << "1.-Estatica" << endl;
                cout << "2.-Dinamica" << endl;

                cout << "Indique su opcion: " << endl;
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        //Usando memoria estática.
                        for (i = 0; i < 10; i++) {
                            for (j = 0; j < 10; j++) {
                                cout << "\n[" << i + 1 << "] [" << j + 1 << "]- Dame un numero: " << endl;
                                cin >> matriz[i][j];
                            }
                        }

                        for (i = 0; i < 10; i++) {
                            for (j = 0; j < 10; j++) {
                                cout << "\n[" << i + 1 << "] [" << j + 1 << "]- El numero es: " << matriz[i][j]<<endl;
                            }
                        }

                        break;
                    case 2:
                        //Usando memoria dinámica.
                        cout << "Dame el tamanio de la fila: "<< endl;
                        cin >> fil;

                        cout << "Dame el tamanio de la columna: " << endl;
                        cin >> col;

                        //Alojamiento de memoria.
                        matriz2 = new int *[fil];

                        for (i = 0; i < fil; i++) {
                            matriz2[i] = new int[col];
                        }

                        //Se piden los datos.
                        for (i = 0; i < fil; i++) {
                            for (j = 0; j < col; j++) {
                                cout << "\n[" << i + 1 << "] [" << j + 1 << "]- Dame un numero: "<<endl;
                                cin >> matriz2[i][j];
                            }
                        }

                        //Despliegue de datos.
                        for (i = 0; i < fil; i++) {
                            for (j = 0; j < col; j++) {
                                cout << "\n[" << i + 1 << "] [" << j + 1 << "]- El numero es: " << matriz2[i][j]<<endl;
                            }
                        }
                        cout << "\n" <<endl;
                        //Desalojamiento de memoria.
                        if (matriz2 != NULL) {
                            for (i = 0; i < fil; i++) {
                                delete[] matriz2[i];
                            }
                            delete[] matriz2;
                        }

                        break;
                    default:
                        cout << "\nEsa opcion no existe";
                }
            case 8:
                //Farenheit a Celsius.
                cout << "Dame el valor que quieras convertir a Celsius: " << endl;
                cin >> x2;

                cout << "\nEl resultado en Celsius es: " << Far_to_Cent(x2);
                cout << "\n" <<endl;
                break;

            case 9:
                 for(int i=0;i<10;i++)  //se leen los valores por teclado
                    {
                        cout << "Introduce elemento " << i+1 << " del vector: "<<endl;
                        cin >> F[i];
                    }
                    cout << "El numero Mayor del vector es : " << mayor(F) << endl; //en la llamada a la función se le envía el vector
                break;
            case 10:
                cout << "Saliendo del programa..." << endl;
        }
    } while (opcion != 10);

    return 0;
}
double Far_to_Cent(double a){
    return (a - 32) * 5 / 9;
}


float mayor(float *v){ // v contiene la direccion de inicio del vector
    float mayor;
    int i;
    mayor = *v; //tomamos el primer elemento como mayor
    v++;        //avanzamos hasta el segundo elemento del vector
    for(i=1;i<10;i++)
    {
        if(*v > mayor) //si el elemento actual es mayor que el mayor actual
        {
            mayor=*v; //se toma como mayor
        }
        v++; //siguiente elemento del vector
    }

    return mayor; //se devuelve el mayor
}