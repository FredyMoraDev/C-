#include <iostream>

struct disquera{
    char genero[20];
    char nombre [20];
    char disco [20];
    int anno;
    int venta;
}mexico,colorado,usa;

using namespace std;
float promedio();/* Funcion para sacar el promedio de n numeros*/
float circulo();/* Funcion de area de circulo*/
float cuadrado();/* Funcion de area de cuadrado*/
float rectangulo();/* Funcion de area de rectangulo*/
float triangulo();/* Funcion de area de triangulo*/
float trapecio();/* Funcion de area de trapecio*/

int main() {
    int opc, opcion;
    do{
        cout << "1.- Promedio de N cantidad de numeros" << endl;
        cout << "2.- Disqueras" << endl;
        cout << "3.- Areas de figuras geometricas" << endl;
        cout << "\nIntroduza su opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1:

                cout << "\t Promedio n cantidad de numeros \n" << endl;
                promedio();
                break;

                case 2:
                    cout << "\t Disqueras y bandas" << endl;
                    struct disquera mexico;
                    cout << "Como se llama la banda mexicana? " << endl;
                    cin >> mexico.nombre;
                    cout << "Que genero toca la banda?" << endl;
                    cin >> mexico.genero;
                    cout << "Como se llama el disco?" << endl;
                    cin >> mexico.disco;
                    cout << "En que año salio el disco? "<< endl;
                    cin >> mexico.anno;
                    cout << "Cuantos discos se vendieron?" <<endl;
                    cin >> mexico.venta;

                    struct disquera usa;
                    cout << "Como se llama la banda Estado Unidense? " << endl;
                    cin >> usa.nombre;
                    cout << "Que genero toca la banda?" << endl;
                    cin >> usa.genero;
                    cout << "Como se llama el disco?" << endl;
                    cin >> usa.disco;
                    cout << "En que año salio el disco? "<< endl;
                    cin >> usa.anno;
                    cout << "Cuantos discos se vendieron?" <<endl;
                    cin >> usa.venta;

                    struct disquera colombia;
                    cout << "Como se llama la banda Colombiana?" << endl;
                    cin >> colombia.nombre;
                    cout << "Que genero toca la banda?" << endl;
                    cin >> colombia.genero;
                    cout << "Como se llama el disco?" << endl;
                    cin >> colombia.disco;
                    cout << "En que año salio el disco?"<< endl;
                    cin >> colombia.anno;
                    cout << "Cuantos discos se vendieron?" <<endl;
                    cin >> colombia.venta;
                    /*PROCESO*/
                    if(mexico.venta >usa.venta && mexico.venta>colombia.venta){
                        cout<<"El disco mas vendido fue : "<<mexico.disco << " del artista  " <<mexico.nombre<< endl;
                    }
                    if(usa.venta > colombia.venta && usa.venta > mexico.venta){
                        cout<<"El disco mas vendido fue : "<<usa.disco <<" del artista  "<<usa.nombre << endl;
                    }
                    if(colombia.venta > usa.venta && colombia.venta > mexico.venta){
                        cout<<"El disco mas vendido fue : "<<colombia.disco <<" del artista"<<colombia.nombre << endl;
                    }
                    /*Salida*/
                    cout << "\t"<< endl;
                    cout << "\t La banda se llama: " << mexico.nombre << endl;
                    cout << "\t La banda toca el genero de: " <<mexico.genero<< endl;
                    cout << "\t El nombre de su disco es: " << mexico.disco<< endl;
                    cout << "\t El disco  " <<mexico.disco <<" Salio el año de: "<<mexico.anno<< endl;
                    cout << "\t El disco  " <<mexico.disco <<" Tuvo una venta de  " <<mexico.venta << "  discos"<< endl;

                    cout << "\t"<< endl;
                    cout << "\t La banda se llama  " << usa.nombre << endl;
                    cout << "\t La banda toca el genero de: " <<usa.genero<< endl;
                    cout << "\t El nombre de su disco es: " << usa.disco<< endl;
                    cout << "\t El disco  " <<usa.disco <<" Salio el año de: "<< usa.anno<< endl;
                    cout << "\t El disco  " <<usa.disco <<" Tuvo una venta de  " <<usa.venta << "  discos"<< endl;

                    cout << "\t"<< endl;
                    cout << "\t La banda se llama  " << colombia.nombre << endl;
                    cout << "\t La banda toca el genero de: " <<colombia.genero<< endl;
                    cout << "\t El nombre de su disco es: " << colombia.disco<< endl;
                    cout << "\t El disco  " <<colombia.disco <<" Salio el año de: "<<colombia.anno<< endl;
                    cout << "\t El disco  " <<colombia.disco <<" Tuvo una venta de  " <<colombia.venta << "  discos"<< endl;
                    break;

                    case 3:
                        cout << "\t Ejercicio 3" << endl;
                        do {
                            cout << "__________________________________" << endl;
                            cout << "___Areas de figuras geometricas___" << endl;
                            cout << "1. Circulo" << endl;
                            cout << "2. Cuadrado" << endl;
                            cout << "3. Ractangulo" << endl;
                            cout << "4. Triangulo" << endl;
                            cout << "5. Trapecio" << endl;
                            cout << "6. Salir" << endl;
                            cout << "__________________________________" << endl;
                            cin >> opc;

                            switch (opc) {
                                case 1:
                                    circulo();
                                    break;

                                    case 2:
                                        cuadrado();
                                        break;

                                        case 3:
                                            rectangulo();
                                            break;

                                            case 4:
                                                triangulo();
                                                break;

                                                case 5:
                                                    trapecio();
                                                    break;

                                                    case 6:
                                                        cout << "Saliendo del programa" << endl;
                                                        break;

                                                        default:
                                                            cout << "Opcion no valida" << endl;
                                                            break;
                            }
                        }while (opc != 6);
                        break;
                        default:
                            cout << "\nEsa opcion no existe" << endl;
        }
    } while (opcion > 3);
    return 0;
}


float promedio(){
    float promedio , n = 0, cantidad = 0, suma = 0;
    cout <<"Cuantas cantidades vas a ingresar?" << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Ingresa la cantidad  " << (i+1) << endl;
        cin >> cantidad;
        suma = suma + cantidad;
    }
    promedio = suma / n;
    cout << "El promedio de las " << n << " cantidades es: "<< promedio << endl ;
    return promedio;
}

float circulo(){
    double const pi = 3.1416;
    float area,radio;
    cout << "Dame el radio:"<<endl;
    cin >>radio;
    area = (radio*radio)*pi;
    cout << "El area del circuo es: "<< area << endl;
    return area;
}


float cuadrado(){

    float area,lado;
    cout << "Dame el lado: "<<endl;
    cin >> lado;
    area = (lado*lado);
    cout << "El area del cuadrado es: "<< area << endl;
    return area;
}

float rectangulo(){

    float area,base,altura;
    cout << "Dame la base:"<<endl;
    cin >> base;
    cout << "Dame la altura:"<<endl;
    cin >> altura;
    area = base*altura;
    cout << "El area del rectangulo es: "<< area <<endl;
    return area;
}

float triangulo(){

    float area,base,altura;
    cout << "Dame la base: "<<endl;
    cin >>base;
    cout << "Dame la altura: "<<endl;
    cin >> altura;
    area = (base*altura)/2;
    cout << "El area del triangulo es: "<< area<<endl;
    return area;
}

float trapecio(){

    float area,base,base2,altura;
    cout <<"Dame la base 1:"<<endl;
    cin >> base;
    cout << "Dame la base 2"<<endl;
    cin >> base2;
    cout << "Dame la altura:"<<endl;
    cin >> altura;
    area = ((base+base2)*altura)/2;
    cout << "El area del trapecio es: "<< area <<endl;
    return area;
}
