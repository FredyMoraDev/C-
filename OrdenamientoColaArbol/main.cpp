#include <iostream>
#include <conio.h>

using namespace std;

struct alumno {
    int ID;
    char nombre[25];
    char matricula[10];
    float calificacion_final;
    alumno *siguiente;
};

struct s_jugador {
    int ID;
    float puntaje;
    char nombre[25];
    s_jugador *derecha;
    s_jugador *izquierda;
};

struct s_jugador *p;
struct alumno *caja_nueva, *caja_final, *caja_inicial;
bool otraCaja();
alumno *hacerCajaC();
void Enqueue(alumno *q1);
alumno *Dequeue();
void llenarCola();
void imprimeCola();
char *buscarElementoC(alumno *caja_nueva, int valor);
void menuCola();
void promedio(alumno *p1);
bool hayHijo(int n);
s_jugador *construyeArbol();
void imprimeArbolPreOrden(s_jugador *p);
void imprimeArbolPostOrden(s_jugador *p);
void imprimeArbolEntreOrden(s_jugador *p);
void eliminaNodos(s_jugador *p);
int dameNivel(s_jugador *p);
s_jugador *busquedaBinaria(s_jugador *p,int valor);
void menuArbol();

using namespace std;

int main() {
    int opcion = 0;
    p = NULL;
    caja_nueva = NULL;
    caja_final = NULL;
    caja_inicial = NULL;

    do {
        cout << "___________________________" << endl;
        cout << "Men\xA3 Principal: " << endl;
        cout << "1.- Ordenamiento" << endl;
        cout << "2.- Cola" << endl;
        cout << "3.- \xA0rbol" << endl;
        cout << "4.- Salir" << endl;
        cout << "___________________________" << endl;
        cout << "Indique su opci\xA2n: "<< endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout<<" El estado del vector 6, 22, 11, 16, 27,3,5 después de aplicarle tres pasadas de algotimo de ordenación es 6,11, 3, 5, 16,22,27 ¿Qué algoritmo se esta usando?"  << endl;
                cout << "a) Algoritmo de inserción" << endl;
                cout << "b) Algoritmo de selección" << endl;
                cout << "c) Algoritmo de burbuja" << endl;
                cout << " d) Ninguno " << endl;
                cout << "Algoritmo de seleccón, porque a la primera pasada va ordenando los valores en un sub-arreglo de menor a mayor valor," << endl;
                cout << "en la segunda pasada igual los va acomodando de menor a mayor, y en la tercera esta sublista va quedando de esta manera por" << endl;
                cout << "que en el arreglo 1 quedan los menores valores y en el sub-arreglo quedan los mayores."<<endl;
                cout << "Ejercicio Comentado\n ";
                break;
            case 2:
                menuCola();
                break;
            case 3:
                menuArbol();
                break;
            case 4:
                cout << "\nPrograma finalizado con exito" << endl;
                break;
            default:
                cout << "\nPor favor elije una opci\xA2n valida" << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
bool otraCaja(){
    char c;
    cout << "\nPresiona 's' si deseas agregar otra caja 2 si ya no: "<< endl;
    cin >> c;
    return c == 's' || c == 'S';
}

bool hayHijo(int n){
    char c;
    const char *lado[2] = {"izquierda", "derecha"};
    cout << "\nHay hijo " << lado[n] << "?: " << endl;
    cin >> c;
    return (c == 's' || c == 'S');
}

alumno *hacerCajaC(){
    alumno *q1;
    q1 = new alumno;
    if (q1 == NULL){
        return NULL;
    }
    cout << "\n___________________________" << endl;
    cout << "Dame tu ID: "<< endl;
    cin >> q1->ID;
    cout << "Dame tu nombre: "<< endl;
    cin >> q1->nombre;
    cout << "Dame tu matricula: "<< endl;
    cin >> q1->matricula;
    cout << "Dame tu calificaci\xA2n final: "<< endl;
    cin >> q1->calificacion_final;
    return q1;
}

void Enqueue(alumno *q1){
    if (q1 == NULL){
        return;
    }
    q1->siguiente = NULL;
    if (caja_final == NULL){
        caja_inicial = q1;
    }
    else {
        caja_final->siguiente = q1;
    }
    caja_final = q1;
}

alumno *Dequeue(){
    if (caja_inicial == NULL){
        return NULL;
    }
    alumno *q1;
    q1 = caja_inicial;
    caja_inicial = caja_inicial->siguiente;
    q1->siguiente = NULL;
    if (caja_inicial == NULL){
        caja_final = NULL;
    }
    return q1;
}

void llenarCola(){
    while (otraCaja()){
        Enqueue(hacerCajaC());
    }
}

void imprimeCola(){
    caja_nueva = caja_inicial;
    while ((caja_nueva = Dequeue()) != NULL){
        cout << "\n___________________________" << endl;
        cout << "ID: " << caja_nueva->ID << endl;
        cout << "Nombre: " << caja_nueva->nombre << endl;
        cout << "Matricula: " << caja_nueva->matricula << endl;
        cout << "Calificaci\xA2n final: " << caja_nueva->calificacion_final << endl;
        caja_nueva = caja_nueva->siguiente;
    }
}

char *buscarElementoC(alumno *caja_nueva, int valor){
    caja_nueva = caja_final;
    while((caja_nueva = Dequeue()) != NULL){
        if (caja_nueva->ID == valor){
            cout << "\n_____________________" << endl;
            cout << "ID encontrado " << endl;
            cout << "ID: " << caja_nueva->ID << endl;
            cout << "Nombre: " << caja_nueva->nombre << endl;
            cout << "Matricula: " << caja_nueva->matricula << endl;
            cout << "Calificacion final: " << caja_nueva->calificacion_final << endl;
            cout << "_____________________" << endl;
            return 0;
        }
        else {
            cout << "\n____________________" << endl;
            cout << "ID no encontrado" << endl;
            cout << "______________________";
            return NULL;
        }

    }

}


void promedio(alumno *p1){
    int num_estudiantes = 0, total =0;
    double prom;
    caja_nueva = caja_inicial;
    while (caja_nueva != NULL){
        total += caja_nueva->calificacion_final;
        num_estudiantes++;
        caja_nueva = caja_nueva->siguiente;
    }
    prom =  total / num_estudiantes;
    cout <<"El promedio es : " << prom<< endl;
}

void menuCola(){
    int op = 0, valor = 0;
    float num = 0.0;

    do {
        cout << "\n___________________________" << endl;
        cout << "\n1.- Llena cola" << endl;
        cout << "2.- Desencolar" << endl;
        cout << "3.- Imprime cola" << endl;
        cout << "4.- Buscar ID" << endl;
        cout << "5.- Promedio final" << endl;
        cout << "6.- Salir al men\xA3 principal" << endl;
        cout << "\n___________________________" << endl;
        cout << "\nIndica tu opci\xA2n: "<< endl;
        cin >> op;

        switch (op) {
            case 1:
                llenarCola();
                break;
            case 2:
                while(NULL != (caja_nueva = Dequeue())) {
                    cout << "_____________________________________________" << endl;
                    cout << "ID: " << caja_nueva->ID << endl;
                    cout << "Nombre: " << caja_nueva->nombre << endl;
                    cout << "Matricula: " << caja_nueva->matricula << endl;
                    cout << "Calificaci\xA2n final: " << caja_nueva->calificacion_final << endl;
                    delete caja_nueva;
                }
                break;
            case 3:
                imprimeCola();
                break;
            case 4:
                alumno *q1;
                cout << "Que ID buscas?: ";
                cin >> valor;
                buscarElementoC(q1, valor);
                break;
            case 5:
                 promedio(caja_nueva);
                break;
            case 6:
                cout << "\n" << endl;
                cout << "Regresando al men\xA3 principal..." << endl;
                cout << " " << endl;
                break;
            default:
                cout << "Opci\xA2n no valida, elige otra" << endl;
                break;
        }
    } while (op != 6);
}
void menuArbol(){
    int opcion = 0;

    do {
        cout << "\n___________________________" << endl;
        cout << "Men\xA3: " << endl;
        cout << "1.- Llenar arbol" << endl;
        cout << "2.- Imprimir arbol pre-orden" << endl;
        cout << "3.- Imprimir arbol post-orden" << endl;
        cout << "4.- Imprimir arbol entre-orden" << endl;
        cout << "5.- Numero de niveles" << endl;
        cout << "6.- B\xA3squeda Binaria" << endl;
        cout << "7.- Salir" << endl;
        cout << "\n___________________________" << endl;
        cout << "\nIndique su opci\xA2n: "<< endl;
        cin >> opcion;
        switch (opcion) {

            case 1:
                p = construyeArbol();
                break;
            case 2:
                imprimeArbolPreOrden(p);
                break;
            case 3:
                imprimeArbolPostOrden(p);
                break;
            case 4:
                imprimeArbolEntreOrden(p);
                break;
            case 5:
                cout << "El numero de niveles es: " << dameNivel(p) << endl;
                break;
            case 6:
                int busq;
                cout <<"Digita el numero del jugador que buscas: "<<endl;
                cin >> busq;
                busquedaBinaria(p, busq);
                break;
            case 7:
                cout << "Finalizaci\xA2n completa"<< endl;
                break;
            default:
                cout << "Elige una opci\xA2n valida."<< endl;
                break;
        }
    } while (opcion != 7);


}


void eliminaNodos(s_jugador *p){
    if (p == NULL){
        return;
    }
    eliminaNodos(p->izquierda);
    eliminaNodos(p->izquierda);
    delete p;
}

int dameNivel(s_jugador *p){
    if (p == NULL){
        return 0;
    }
    return 1 + max(dameNivel(p->izquierda), dameNivel(p->derecha));
}

void imprimeArbolPreOrden(s_jugador *p){
    if (p == NULL){
        return;
    }
    cout << "_____________________" << endl;
    cout << "Numero: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Puntaje: " << p->puntaje << endl;
    cout << "_____________________" << endl;
    imprimeArbolPreOrden(p->izquierda);
    imprimeArbolPreOrden(p->derecha);
    //eliminaNodos(arbol);
}

void imprimeArbolPostOrden(s_jugador *p){
    if (p == NULL){
        return;
    }
    imprimeArbolPostOrden(p->izquierda);
    imprimeArbolPostOrden(p->derecha);
    cout << "_____________________" << endl;
    cout << "Numero: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Puntaje: " << p->puntaje << endl;
    cout << "_____________________" << endl;
    //eliminaNodos(otro);
}

void imprimeArbolEntreOrden(s_jugador *p){
    if (p == NULL){
        return;
    }
    imprimeArbolEntreOrden(p->izquierda);
    cout << "_____________________" << endl;
    cout << "Numero: " << p->ID << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Puntaje: " << p->puntaje << endl;
    cout << "_____________________" << endl;
    imprimeArbolEntreOrden(p->derecha);
    //eliminaNodos(otro);
}
s_jugador *construyeArbol(){
    s_jugador *raiz;
    raiz = new s_jugador;
    cout << "                      " << endl;
    cout << "Digita numero del jugador: ";
    cin >> raiz->ID;
    cout << "Digita el nombre del jugador:  ";
    cin >> raiz->nombre;
    cout << "Digita puntaje del jugador: ";
    cin >> raiz->puntaje;
    raiz->izquierda = NULL;
    raiz->derecha = NULL;
    if (hayHijo(0)){
        raiz->izquierda = construyeArbol();
    }
    if (hayHijo(1)){
        raiz->derecha = construyeArbol();
    }
    return raiz;
}

s_jugador *busquedaBinaria(s_jugador *p, int valor){
    if (p == NULL){
        return NULL;
    }

    if (valor == p->ID){
        cout << "_____________________" << endl;
        cout << "Jugador encontrado" << endl;
        cout << "Numero: " << p->ID << endl;
        cout << "Nombre: " << p->nombre << endl;
        cout << "Puntaje: " << p->puntaje << endl;
        cout << "_____________________" << endl;
        return p;
    }
    else if (valor < p->ID){
        return busquedaBinaria(p->izquierda, valor);
    }
    else if (valor > p->ID){
        return busquedaBinaria(p->derecha, valor);
    }
    cout << "\n_____________________" << endl;
    cout << "Jugador no encontrado..." << endl;
    cout << "______________________" << endl;
}

