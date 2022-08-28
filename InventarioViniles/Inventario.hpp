#ifndef PROYECTO_INVENTARIO_HPP
#define PROYECTO_INVENTARIO_HPP
#include <iostream>
#include <fstream> // Se utiliza para crear archivos tanto de lectura como de escritura.
#include "Ortografia.hpp" // Se utiliza para usar caracteres ASCII

using namespace std;

ofstream archivo; // Variable global para la creación del archivo .txt.

struct inventario { // Estructura principal del programa.
    int ID;
    double precio;
    char username[25], fecha[25];
    char color[25], pais[25];
    char genero[25], sello [20];
    char garantia[2], vendido[2];
    char descripcion[50],nombre[50],album[50];
    inventario *izquierda; // Para estructura de árbol.
    inventario *derecha;  // Para estructura de árbol.
    inventario *link;  // Para lista ligada y pila.
};

struct inventario *p, *q; // Apuntadores necesarios para la creación de las estructuras.

bool otraCaja(){
    char c;
    cout << "\nPresiona 's' si quieres agregar una caja: " << endl;
    cin >> c;
    return c == 's' || c == 'S';
}
//Retorná un valor booleano; true cuando el usuario digita 's' o 'S' y false cuando es diferente a 's' o 'S'

bool hayHijo(int n){
    char c;
    char *lado[2] = {"izquierda", "derecha"};
    cout << "\nHay hijo " << lado[n] << "?: " << endl;
    cin >> c;
    return c == 's' || c == 'S';
}
/* n Se le mandá como parámetro un valor entero. Retorná un valor booleano; true cuando el usuario digita 's' o 'S' y false cuando
  es diferente  's' o 'S'.*/

bool comprarD(){
    char c;
    cout << "\nPresione 's' si desea comprar este vinyl: " << endl;
    cin >> c;
    return c == 's' || c == 'S';
}
/* Retorná un valor booleano; true cuando el usaurio digita 's' o 'S' y false cuando es diferente a 's' o 'S'.*/

bool elementoVendido(){
    char c;
    cout << "\nPresione 's' para reafirmar si el vinyl ya ha sido vendido: ";
    cin >> c;
    return c == 's' || c == 'S';
}
/* Retorna un valor booleano; true cuando el usuario digita 's' o 'S' y false cuando es diferente a 's' o 'S'.*/

bool devolucion(){
    char c;
    cout << "\nPresione 's' si desea devolver el vinyl: ";
    cin >> c;
    return c == 's' || c == 'S';
}
/* Retorná un valor booleano; true cuando el usuario digita 's' o 'S' y false cuando es diferente a 's' o 'S'.*/

inventario *hacerInventario(){
    q = new inventario;
    if (q == NULL){
        return NULL;
    }
    cout << "____________________________________" << endl;
    cout << "Digita el ID: " << endl;
    cin >> q->ID;
    cout << "Digita el nombre del artista: " << endl;
    cin >> q->nombre;
    cout << "Digita el nombre del album: " << endl;
    cin >> q->album;
    cout << "Digita el color del vinyl: " << endl;
    cin >> q->color;
    cout << "Digita el nacionalidad del artista: " << endl;
    cin >> q->pais;
    cout << "Digita el genero musical del artista: " << endl;
    cin >> q->genero;
    cout << "Digita el sello discografico del artista: " << endl;
    cin >> q->sello;
    cout << "Digita el precio del vinyl: " << endl;
    cin >> q->precio;
    cout << "Vinyl vendido? si o no?: " << endl;
    cin >> q->vendido;
    return q;
    cout << "____________________________________" << endl;
}
/* Retorna el apuntador *q tipo estructura ya lleno*/

void push(inventario *q){
    if (q == NULL){
        return;
    }
    q->link = p;
    p = q;
}
/*q Se le mandá como parámetro el apuntador *q tipo estructura, este va uniendo los enlaces con las cajas que se van creando */

void llenaCaja(){
    while (otraCaja()){
        push(hacerInventario());
    }
    cout << " _____________________" << endl;
    cout << "|    Guardando datos  |" << endl;
    cout << " _____________________" << endl;
}
/* Esta función sirve simplemente para poder guardar los datos de las cajas, hasta que el proveedor así lo desee */

void eliminaNodos(inventario *p){
    if (p == NULL){
        return;
    }
    eliminaNodos(p->izquierda);
    eliminaNodos(p->derecha);
}

/* p Se le mandá como parámetro el apuntador *p tipo struct, esta dunción sirve para eliminar los nodos de forma recursiva.*/

inventario *contruyeArbol(){
    inventario *raiz;
    raiz = new inventario;
    cout << "\n__________________" << endl;
    cout << "Digita el ID: " << endl;
    cin >> raiz->ID;
    cout << "Digita el nombre del artista: " << endl;
    cin >> raiz->nombre;
    cout << "Digita el nombre del album: " << endl;
    cin >> raiz->album;
    cout << "Digita el color del vinyl: " << endl;
    cin >> raiz->color;
    cout << "Digita nacionalidad del artista: " << endl;
    cin >> raiz->pais;
    cout << "Digita el genero musical del artista: " << endl;
    cin >> raiz->genero;
    cout << "Digita el sello discografico del artista: " << endl;
    cin >> raiz->sello;
    cout << "Digita el precio del vinyl: " << endl;
    cin >> raiz->precio;
    cout << "Vinyl vendido: si o no? " << endl;
    cin >> raiz->vendido;
    raiz->izquierda = NULL;
    raiz->derecha = NULL;
    if (hayHijo(0)){
        raiz->izquierda = contruyeArbol();
    }
    if (hayHijo(1)){
        raiz->derecha = contruyeArbol();
    }
    return raiz;
}
/*Retorna el apuntador *raiz va formando las hojas para que después se puedan usar, dependiendo del lado en que se este construyendo.*/

void imprimeArbolEntreOrden(inventario *p){
    if (p == NULL){
        return;
    }
    imprimeArbolEntreOrden(p->izquierda);
    cout << "\n________________________" << endl;
    cout << "ID: " << p->ID << endl;
    cout << "Artista: " << p->nombre << endl;
    cout << "Album: " << p->album << endl;
    cout << "Color: " << p->color << endl;
    cout << "Nacionalidad: " << p->pais << endl;
    cout << "Genero musical: " << p->genero << endl;
    cout << "Sello discografico: " << p->sello << endl;
    cout << "Precio del vinyl: " << p->precio << endl;
    imprimeArbolEntreOrden(p->derecha);
}
/* p Se le mandá como parámetro el apuntador *p tipo struct. Imprime los elementos en ordenamiento entre - orden.*/

void imprimeLista(inventario *p, inventario *q){
    p = q;
    for (;p != NULL;){
        cout << "\n___________________" << endl;
        cout << "ID: " << q->ID << endl;
        cout << "Artista: " << q->nombre << endl;
        cout << "Album: " << q->album << endl;
        cout << "Color: " << q->color << endl;
        cout << "Nacionalidad: " << q->pais << endl;
        cout << "Genero musical: " << q->genero << endl;
        cout << "Sello discografico: " << q->sello << endl;
        cout << "Precio del vinyl: " << q->precio << endl;
        q = q->link;
        p = q;
    }
}
/* p Se le mandá como parámetro el apuntador *p tipo struct q Se le mandá como parámetro el apuntador *q tipo struct. Imprime la lista ligada simple */

void imprimeInventario(inventario *p, inventario *q){
    for(;p != NULL;) {
        cout << "\n********************" << endl;
        cout << "ID: " << q->ID << endl;
        cout << "Artista: " << q->nombre << endl;
        cout << "Album: " << q->album << endl;
        cout << "Color: " << q->color << endl;
        cout << "Nacionalidad: " << q->pais << endl;
        cout << "Genero musical: " << q->genero << endl;
        cout << "Sello discografico: " << q->sello << endl;
        cout << "Precio del vinyl: " << q->precio << endl;
        q = q->link;
        p = q;
    }
}
/* p Se le mandá como parámetro el apuntador *p tipo struct, q Se le mandá como parámetro el apuntador *q tipo struct.Imprime la pila.*/

inventario *busquedaBinaria(inventario *p, int valor){
    if (p == NULL){
        return NULL;
    }
    if (valor == p->ID){
        cout << "\n_________________________" << endl;
        cout << "ID: " << p->ID << endl;
        cout << "Artista: " << p->nombre << endl;
        cout << "Album: " << p->album << endl;
        cout << "Color: " << p->color << endl;
        cout << "Nacionalidad: " << p->pais << endl;
        cout << "Genero musical: " << p->genero << endl;
        cout << "Sello discografico: " << p->sello << endl;
        cout << "Precio del vinyl: " << p->precio << endl;
        return p;
    }
    if (valor < p->ID){
        return busquedaBinaria(p->izquierda, valor);
    }
    if (valor > p->ID){
        return busquedaBinaria(p->derecha, valor);
    }
    cout << "\n_____________________" << endl;
    cout << "ID no encontrado..." << endl;
    cout << "______________________" << endl;
    return NULL;
}
/*  p Se le mandá como parámetro el apuntador *p tipo struct valor Se le mandá como parámetro el valor que digita el usuario.
 Retornará el equipo si esté ha sido encontrado en la lista, sino solamente retornará un valor nulo con un aviso al usuario.*/

char *buscarElemento(inventario *p, inventario *q, int busq){
    int j = 1;
    p = q;
    while(p != NULL){
        if(q->ID == busq){
            cout << "\n____________________" << endl;
            cout << "ID: " << q->ID << endl;
            cout << "Artista: " << q->nombre << endl;
            cout << "Album: " << q->album << endl;
            cout << "Color: " << q->color << endl;
            cout << "Nacionalidad: " << q->pais << endl;
            cout << "Genero musical: " << q->genero << endl;
            cout << "Sello discografico: " << q->sello << endl;
            cout << "Precio del vinyl: " << q->precio << endl;
            return 0;
        }
        q = q->link;
        j++;
        if (q->ID != busq){
            cout << "\n____________________" << endl;
            cout << "   ID no encontrado" << endl;
            cout << "______________________" << endl;
            return NULL;
        }
    }
    return NULL;
}
/* p Se le mandá como parámetro el apuntador *p tipo struct, q Se le mandá como parámetro el apuntador *q tipo struct.
 valor Se le mandá como parámetro el valor que digite el usuario Retornará el equipo con sus elementos si ha sido encontrado el ID, de
 lo contrario retornará un valor nulo y un aviso al usuario */

char *comprarElementoA(inventario *p, int valor){
    if (comprarD() == 1){
        if (elementoVendido() == 0){
            for(;p!= NULL;) {
                cout << "Digite de nuevo el ID de su compra: " << endl;
                cin >> p->ID;
                cout << "Digite su nombre de usuario: " << endl;
                cin >> p->username;
                cout << "Fecha de compra: " << endl;
                cin >> p->fecha;
                cout << "Agregar a" << n << "o de garant" << i << "a?: " << endl;
                cin >> p->garantia;
                if (p->ID == valor) {
                    cout << "_____________________" << endl;
                    cout << "ID: " << p->ID << endl;
                    cout << "Username: " << p->username << endl;
                    cout << "Fecha de compra: " << p->fecha << endl;
                    cout << "\nElementos comprados: " << endl;
                    cout << "Artista: " << p->nombre << endl;
                    cout << "Album: " << p->album << endl;
                    cout << "Color: " << p->color << endl;
                    cout << "Nacionalidad: " << p->pais << endl;
                    cout << "Genero musical: " << p->genero << endl;
                    cout << "Sello discografico: " << p->sello << endl;
                    archivo.open("DatosVenta.txt", ios::out);//Se abre el archivo txt para generar el ticket de venta
                    archivo << "ID: " << p->ID << endl;
                    archivo << "Username: " << p->username << endl;
                    archivo << "Fecha de compra: " << p->fecha << endl;
                    archivo << "Garant" << i << "a: " << p->garantia << endl;
                    archivo << "Artista: " << p->nombre << endl;
                    archivo << "Album: " << p->album << endl;
                    archivo << "Color: " << p->color << endl;
                    archivo << "Nacionalidad: " << p->pais << endl;
                    archivo << "Genero musical: " << p->genero << endl;
                    archivo << "Sello discografico: " << p->sello << endl;
                    archivo.close();// se cierra el archivo txt
                    cout << "\n___________________________" << endl;
                    cout << "Generando ticket de compra..." << endl;
                    cout << "_____________________________" << endl;
                    return 0;
                } else {
                    cout << "\n______________________" << endl;
                    cout << "Elemento no disponible  " << endl;
                    cout << "________________________" << endl;
                }
            }
        } else {
            cout << "\n__________________________________________________" << endl;
            cout << "Este vinyl ya ha sido vendido, elija uno disponible" << endl;
            cout << "___________________________________________________" << endl;
        }
    }
    else {
        cout << "\n__________________________________________________" << endl;
        cout << "Gracias por mostrar su inter" << e << "s, haremos lo posible por satisfacerlo" << endl;
        cout << "____________________________________________________" << endl;
        printf("\n");
        printf("\t          *******              \n");
        printf("\t      ***************          \n");
        printf("\t    *******************        \n");
        printf("\t  ***********************      \n");
        printf("\t *************************     \n");
        printf("\t************  *************    \n");
        printf("\t***********    ************    \n");
        printf("\t************  *************    \n");
        printf("\t***************************    \n");
        printf("\t *************************      \n");
        printf("\t  ***********************       \n");
        printf("\t    *******************         \n");
        printf("\t      ***************           \n");
        printf("\t          *******               \n");
        printf("\n");
        printf("\t      VINYL NEVER DIE             ");
        printf("\n");
        cout << "___________________________________________________________" << endl;
    }
    return NULL;
}
/*p Se le mandá como parámetro el apuntador *p tipo struct. valor Se le mandá como parámetro el valor que digite el usuario.
 Retornará el nombre de usuario, fecha de compra y los elementos comprados por el usuario, al final generará un ticket de compra, de lo contrario mandará un valor nulo
 con un aviso al usuario.*/
char *comprarElemento(inventario *p, inventario *q, int valor){
    p = q;
    if (comprarD() == 1){
        if (elementoVendido() == 0){
            for(;p!= NULL;) {
                cout << "Digite de nuevo el ID de su compra: " << endl;
                cin >> q->ID;
                cout << "Digite su nombre de usuario: " << endl;
                cin >> q->username;
                cout << "Fecha de compra: " << endl;
                cin >> q->fecha;
                cout << "Agregar a" << n << "o de garant" << i << "a?: " << endl;
                cin >> q->garantia;
                if (q->ID == valor) {
                    cout << "________________________________" << endl;
                    cout << "ID: " << q->ID << endl;
                    cout << "Username: " << q->username << endl;
                    cout << "Fecha de compra: " << q->fecha << endl;
                    cout << "\nElementos comprados: " << endl;
                    cout << "Artista: " << q->nombre << endl;
                    cout << "Album: " << q->album << endl;
                    cout << "Color: " << q->color << endl;
                    cout << "Nacionalidad: " << q->pais << endl;
                    cout << "Genero musical: " << q->genero << endl;
                    cout << "Sello discografico: " << q->sello << endl;
                    cout << "Precio del vinyl: " << q->precio << endl;

                    archivo.open("DatosVenta.txt", ios::out);//Se abre el archivo txt para almacenar los datos de venta
                    archivo << "ID: " << q->ID << endl;
                    archivo << "Username: " << q->username << endl;
                    archivo << "Fecha de compra: " << q->fecha << endl;
                    archivo << "Garant" << i << "a: " << q->garantia << endl;
                    archivo << "Artista: " << q->nombre << endl;
                    archivo << "Album: " << q->album << endl;
                    archivo << "Color: " << q->color << endl;
                    archivo << "Nacionalidad: " << q->pais << endl;
                    archivo << "Genero musical: " << q->genero << endl;
                    archivo << "Sello discografico: " << q->sello << endl;
                    archivo << "Precio del vinyl: " << q->precio << endl;
                    archivo.close();//Se cierra y guarda el archivo txt
                    cout << "\n_____________________________________" << endl;
                    cout << "      Generando ticket de compra...    " << endl;
                    cout << "_______________________________________" << endl;
                    q = p;
                    return 0;
                } else {
                    cout << "\n____________________" << endl;
                    cout << "Elemento no disponible" << endl;
                    cout << "______________________" << endl;
                }
            }
        } else {
            cout << "\n_________________________________________________" << endl;
            cout << "Este Vinyl ya no se encuentra disponible           " << endl;
            cout << "____________________________________________________" << endl;
        }
    }
    else {
        cout << "\n******************************************************" << endl;
        cout << "Gracias por mostrar su inter" << e << "s, haremos lo posible por satisfacerlo" << endl;
        cout << "******************************************************" << endl;
        printf("\n");
        printf("\t          *******              \n");
        printf("\t      ***************          \n");
        printf("\t    *******************        \n");
        printf("\t  ***********************      \n");
        printf("\t *************************     \n");
        printf("\t************  *************    \n");
        printf("\t***********    ************    \n");
        printf("\t************  *************    \n");
        printf("\t***************************    \n");
        printf("\t *************************      \n");
        printf("\t  ***********************       \n");
        printf("\t    *******************         \n");
        printf("\t      ***************           \n");
        printf("\t          *******               \n");
        printf("\n");
        printf("\t      VINYL NEVER DIE             ");
        printf("\n");
        cout << "___________________________________________________________" << endl;
    }
    return NULL;
}
/* p Se le mandá como parámetro el apuntador *p tipo struct, q Se le mandá como parámetro el apuntador *q tipo struct.
  valor Se le mandá como parámetro el valor que digite el usuario. Retornará el nombre de usuario, fecha de compra y los elementos comprados
  por el usuario, al final generará un ticket de compra, de lo contrario mandará un valor nulo con un aviso al usuario.*/

char *devolucionDevinylA(inventario *p, int elemento){
    if (devolucion() == 1){
        cout << "\nNota: M" << a << "ximo 50 caracteres y sin espacios" << endl;
        cout << "Describa la causa por la cual quiere regresar el vinyl: " << endl;
        cin >> p->descripcion;

        archivo.open("DatosDevolucion.txt", ios::out);
        for (;p != NULL;) {
            if (p->ID == elemento){
                archivo << "ID: " << p->ID << endl;
                archivo << "Username: " << p->username << endl;
                archivo << "Fecha de compra: " << p->fecha << endl;
                archivo << "Garant" << i << "a: " << p->garantia << endl;
                archivo << "Artista: " << p->nombre << endl;
                archivo << "Alb"<<u<<"m: " << p->album << endl;
                archivo << "Color: " << p->color << endl;
                archivo << "Nacionalidad: " << p->pais << endl;
                archivo << "G"<<e<<"nero musical: " << p->genero << endl;
                archivo << "Sello discografico: " << p->sello << endl;
                archivo << "Fecha de venta: " << p->fecha << endl;
                archivo << "Fecha de devoluci"<<o<<"n: " << p->fecha << endl;
                archivo << "Descripci" << o <<"n: " << p->descripcion << endl;
                archivo.close();

                cout << "\n_________________" << endl;
                cout << "Generando ticket..." << endl;
                cout << "___________________" << endl;
                return 0;
            }
            else {
                cout << "\n______________" << endl;
                cout << "ID no encontrado" << endl;
                cout << "________________" << endl;
            }
        }
    }
    else {
        cout << "\n______________________________" << endl;
        cout << "Regresando al men" << u <<" principal" << endl;
        cout << "________________________________" << endl;
    }
    return NULL;
}
/* p Se le mandá como parámetro el apuntador *p tipo struct. elemento Se le mandá como parámetro el elemento que digite el usuario.
 Retornará el vinyl con todos sus elementos junto con el nombre de usuario, fecha de compra / devolucion, se generará un ticket de devolucion con la descripción, de lo contrario
 regresará al menu principal o mandará un aviso al usuario.*/

char *devolucionDeVinyl(inventario *p, inventario *q, int elemento){
    p = q;
    if (devolucion() == 1){
        cout << "\nNota: M" << a << "ximo 50 caracteres y sin espacios" << endl;
        cout << "Describa la causa por la cual quiere regresar el vinyl: "<< endl;
        cin >> q->descripcion;

        archivo.open("DatosDevolucion.txt", ios::out);
        for (;p != NULL;) {
            if (q->ID == elemento){
                archivo << "ID: " << q->ID << endl;
                archivo << "Username: " << q->username << endl;
                archivo << "Artista: " << q->nombre << endl;
                archivo << "Album: " << q->album << endl;
                archivo << "Color: " << q->color << endl;
                archivo << "Nacionalidad: " << q->pais << endl;
                archivo << "Genero musical: " << q->genero << endl;
                archivo << "Sello discografico: " << q->sello << endl;
                archivo << "Precio del vinyl: " << q->precio << endl;
                archivo << "Garant" << i << "a: " << q->garantia << endl;
                archivo << "Fecha de venta: " << q->fecha << endl;
                archivo << "Fecha de devoluci"<<o<<"n: " << q->fecha << endl;
                archivo << "Descripci" << o <<"n: " << q->descripcion << endl;
                archivo.close();

                cout << "\n_____________________" << endl;
                cout << "Generando ticket..." << endl;
                cout << "______________________" << endl;
                q = p;
                return 0;
            }
            else {
                cout << "\n_______________" << endl;
                cout << "ID no encontrado" << endl;
                cout << "_________________" << endl;
            }
        }
    }
    else {
        cout << "\n_______________________________" << endl;
        cout << "Regresando al men" << u <<" principal" << endl;
        cout << "_________________________________" << endl;
    }
    return NULL;
}
/* p Se le mandá como parámetro el apuntador *p tipo struct. q Se le mandá como parámetro el apuntador *q tipo struct.
 elemento Se le mandá como parámetro el elemento que digite el usuario. Retornará el vinyl con todos sus elementos junto con el nombre de usuario,
 fecha de compra / devolucion, se generará un ticket de devolucion con la descripción, de lo contrario regresará al menu principal o mandará un aviso al usuario.*/

void imprimeTicketC(inventario *p, inventario *q){
    p = q;
    for(;p!= NULL;){
        cout << "___________________________" << endl;
        cout << "ID: " << q->ID << endl;
        cout << "Username: " << q->username << endl;
        cout << "Fecha de compra: " << q->fecha << endl;
        cout << "Garant" << i << "a: " << q->garantia << endl;
        cout << "\nElementos comprados: " << endl;
        cout << "Artista: " << q->nombre << endl;
        cout << "Alb"<<u<<"m: " << q->album << endl;
        cout << "Color: " << q->color << endl;
        cout << "Nacionalidad: " << q->pais << endl;
        cout << "G"<<e<<"nero musical: " << q->genero << endl;
        cout << "Sello discografico: " << q->sello << endl;
        cout << "Precio del vinyl: " << q->precio << endl;
        q = q->link;
        return;
    }
}
/*p Se le mandá como parámetro el apuntador *p tipo struct. q Se le mandá como parámetro el apuntador *q tipo struct.
 Imprimirá el ticket en consola, con el nombre de usuario, fecha de compra / devolucion y sus elementos.*/

void imprimeTicketCArbol(inventario *p){
    for(;p!= NULL;){
        cout << "_______________________" << endl;
        cout << "ID: " << p->ID << endl;
        cout << "Username: " << p->username << endl;
        cout << "Fecha de compra: " << p->fecha << endl;
        cout << "Garant" << i << "a: " << q->garantia << endl;
        cout << "\nElementos comprados: " << endl;
        cout << "Artista: " << p->nombre << endl;
        cout << "Album: " << p->album << endl;
        cout << "Color: " << p->color << endl;
        cout << "Nacionalidad: " << p->pais << endl;
        cout << "Genero musical: " << p->genero << endl;
        cout << "Sello discografico: " << p->sello << endl;
        return;
    }
}
/* p Se le mandá como parámetro el apuntador *p tipo struct. Imprime el ticket generado previamente, y muestra en un archivo .txt
  los datos del usuario y los elementos que compró.*/

void imprimeTicketA(){
    int op;

    do {
        cout << "\n[1].- Ticket venta" << endl;
        cout << "[2].- Ticket de devoluci"<<o<<"n" << endl;
        cout << "[3].- Men" << u << " principal" << endl;
        cout << "\nElije un ticket: " << endl;
        cin >> op;
        switch (op) {
            case 1:
                cout << "\n___________________" << endl;
                cout << "Procesando ticket..." << endl;
                cout << "___________________" << endl;
                cout << "\n";
                system("start DatosVenta.txt");
                break;
            case 2:
                cout << "\n___________________" << endl;
                cout << "Procesando ticket..." << endl;
                cout << "____________________" << endl;
                cout << "\n";
                system("start DatosDevolucion.txt");
                break;
            case 3:
                cout << "\n_____________________________" << endl;
                cout << "Regresando al men" << u <<" principal..." << endl;
                cout << "________________________________" << endl;
                break;
            default:
                cout << "\nOpci" << o << "n no v" << a << "lida" << endl;
                break;
        }
    } while (op != 3);
    cout << "\n";
}
/* Se le muestra al usuario un mini - menú de opciones, en el cual deberá elegir que tipo de ticket necesita, ya sea la primera opción; se le mostrará
  al usuario el ticket de su venta, la segunda opción; se le mostrará el ticket de devolucionn y la tercera opción; regresará al menu principal.*/

#endif //Inventario