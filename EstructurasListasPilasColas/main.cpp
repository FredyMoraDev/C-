#include <iostream>
using namespace std;

struct books{
    int clave_libro;
    char titulo[100];
    char autor[50];
    char categoria[100];
    books *link;
};

struct address{
    char name[50];
    char street[50];
    char city[50];
    char state[20];
    int pin;
    address *siguiente;
    address *anterior;
    address *link;
};

struct Moviedata{
    char movieTitle[70];
    char movieDirector[70];
    int yearReleased;
    int runningTime;
    int ID;
    Moviedata *link;
};

struct time{
    int seconds;
    int minutes;
    int hours;
    time *link;
};

struct student{
    int ID;
    char name[50];
    int enrollment;
    float average;
    student *link;
};

struct integers{
    int ID;
    int number;
    int number2;
    int number3;
    int number4;
    integers *link;
};

struct integers_2{
    int ID;
    int number;
    int number2;
    int number3;
    int number4;
    integers_2 *link2;
};

struct celulares{
    int ID;
    char marca[25];
    char modelo[25];
    float precio;
    celulares *siguiente;
};

struct books *p, *q;
struct address *p1, *q1;
struct Moviedata *p2, *q2;
struct time *p3, *q3;
struct integers *p4, *q4;
struct integers_2 *caja_nueva2, *caja_final2, *caja_inicial2;
struct celulares *p6, *q6;
struct student *caja_nueva, *caja_final, *caja_inicial;
bool OtraCaja();
void LlenarLista();
void LlenarListaD();
void LlenarListaC();
void ImprimeLista(books *p, books *q);
void ImprimeListaD(address *p1, address *q1);
void ImprimeListaC(Moviedata *p2, Moviedata *q2);
struct time *HacerCaja();
void Push(struct time *q3);
struct time *Pop();
void LlenarCaja();
void ImprimeCaja(struct time *p3, struct time *q3);
student *HacerCajaC();
void Enqueue(student *q);
student *Dequeue();
void ImprimeCola();
void LlenarCola();
integers *HacerColaA();
void Push(integers *q4);
void LlenarColaA();
void ImprimeColaA(integers *p4, integers *q4);
void CopiarColaA(integers_2 *q5, integers_2 *p5);
void LlenarListaC2();
void ImprimeListaC2(celulares *q6, celulares *p6);
void ImprimeColaB();
int main() {
    int opcion = 0, opcion2 = 0;
    //Variables 1er programa.
    p = NULL;
    q = NULL;
    //Variables 2do programa.
    p1 = NULL;
    q1 = NULL;
    //Variables 3er programa.
    p2 = NULL;
    q2 = NULL;
    //Variables 4to programa.
    p3 = NULL;
    q3 = NULL;
    //Variables 5to programa.
    caja_nueva = NULL;
    caja_final = NULL;
    caja_inicial = NULL;
    //Variables 6to programa.
    q4 = NULL;
    p4 = NULL,
    caja_nueva2 = NULL;
    caja_final2 = NULL;
    //Variables 7mo programa.
    p6 = NULL;
    q6 = NULL;

    do {
        cout << "                    " << endl;
        cout << "\nMENU: " << endl;
        cout << "1.- Lista ligada simple" << endl;
        cout << "2.- Lista ligada doblemente enlazada" << endl;
        cout << "3.- Listas ligadas circulares" << endl;
        cout << "4.- Pila" << endl;
        cout << "5.- Colas" << endl;
        cout << "6.- Salir" << endl;
        cout << "                    " << endl;
        cout << "\nIntroduzca su opcion: "<< endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                LlenarLista();
                ImprimeLista(p, q);
                break;
            case 2:
                LlenarListaD();
                ImprimeListaD(p1, q1);
                break;
            case 3:
                do {
                    cout << "\n1.- Lista ligada circular 1" << endl;
                    cout << "2.- Lista ligada circular 2" << endl;
                    cout << "3.- Salir al menu principal." << endl;
                    cout << "\nOpcion: "<< endl;
                    cin >> opcion2;
                    switch (opcion2) {
                        case 1:
                            LlenarListaC();
                            ImprimeListaC(p2, q2);
                            break;
                        case 2:
                            LlenarListaC2();
                            ImprimeListaC2(q6, p6);
                            break;
                        case 3:
                            cout << "\nRegresando al menu principal..." << endl;
                            break;
                        default:
                            cout << "\nElije una opcion valida" << endl;
                            break;
                    }
                } while (opcion2 != 3);
                break;
            case 4:
                LlenarCaja();
                ImprimeCaja(p3, q3);
                break;
            case 5:
                do {
                    cout << "\n1.- Cola 1" << endl;
                    cout << "2.- Cola 2" << endl;
                    cout << "3.- Salir al menu principal." << endl;
                    cout << "\nOpcion: "<<endl;
                    cin >> opcion2;
                    switch (opcion2) {
                        case 1:
                            LlenarCola();
                            ImprimeCola();
                            break;
                        case 2:
                            LlenarColaA();
                            ImprimeColaA(p4, q4);
                            CopiarColaA(caja_nueva2, caja_final2);
                            ImprimeColaB();
                            break;
                        case 3:
                            cout << "\nRegresando al menu principal..." << endl;
                            break;
                        default:
                            cout << "\nElije una opcion valida" << endl;
                            break;
                    }
                } while (opcion2 != 3);
                break;
            case 6:
                cout << "\nPrograma finalizado con exito..." << endl;
                break;
            default:
                cout << "\nError, elige una opcion valida"<< endl;
                break;
        }
    } while (opcion != 6);
    return 0;
}
bool OtraCaja(){
    char c;
    cout << "\nPresione S para agregar otra caja N para no: " << endl;
    cin >> c;
    return c == 's' || c == 'S';
}

void LlenarLista(){
    while (OtraCaja()){
        q = new books;
        cout << "                    " << endl;
        cout << "Digita la clave del libro: "<< endl;
        cin >> q->clave_libro;
        cout << "Digita el titulo: " << endl;
        cin >> q->titulo;
        cout << "Digita el autor: "<< endl;
        cin >> q->autor;
        cout << "Digita la categoria: "<< endl;
        cin >> q->categoria;
        q->link = p;
        p = q;
    }
}

void ImprimeLista(books *p, books * q){
    p = q;
    for(;p != NULL;) {
        cout << "                    " << endl;
        cout << "Clave: " << q->clave_libro << endl;
        cout << "Titulo: " << q->titulo << endl;
        cout << "Autor: " << q->autor << endl;
        cout << "Categoria: " << q->categoria << endl;
        cout << "                    " << endl;
        q = q->link;
        delete p;
        p = q;
    }
}

void LlenarListaD(){
    while (OtraCaja()){
        q1 = new address;
        cout << "                    " << endl;
        cout << "Digita el nombre: " << endl;
        cin >> q1->name;
        cout << "Digita la calle: "<< endl;
        cin >> q1->street;
        cout << "Digita la ciudad: "<< endl;
        cin >> q1->city;
        cout << "Digita el estado: "<< endl;
        cin >> q1->state;
        cout << "Digita el C.P.: "<< endl;
        cin >> q1->pin;
        cout << "                    " << endl;
        q1->siguiente = p1;
        q1->anterior = NULL;
        if (p1 != NULL){
            p1->anterior = q1;
        }
        p1 = q1;
    }
}

void ImprimeListaD(address *p1, address *q1){
    p1 = q1;
    for(; p1 != NULL;) {
        cout << "                    " << endl;
        cout << "Nombre: " << q1->name << endl;
        cout << "Calle: " << q1->street << endl;
        cout << "Ciudad: " << q1->city << endl;
        cout << "Estado: " << q1->state << endl;
        cout << "Codigo postal: " << q1->pin << endl;
        q1 = q1->siguiente;
        delete p;
        p1 = q1;
    }
}

void LlenarListaC(){
    while (OtraCaja()){
        q2 = new Moviedata;
        cout << "                    " << endl;
        cout << "Digita el ID: " << endl;
        cin >> q2->ID;
        cout << "Digita el nombre de la pelicula: "<< endl;
        cin >> q2->movieTitle;
        cout << "Digita el director de la pelicula: "<< endl;
        cin >> q2->movieDirector;
        cout << "Digita el anio de lanzamiento: "<< endl;
        cin >> q2->yearReleased;
        cout << "Digita el tiempo de duracion: "<< endl;
        cin >> q2->runningTime;
        q2->link = q2;
        if(p2 == NULL){
            p2 = q2;
        }
        q2->link = p2->link;
        p2->link = q2;
    }
}

void ImprimeListaC(Moviedata *q2, Moviedata *p2) {
    q2 = p2;
    for (; p2->ID >= 1;){
        p2 = q2;
        cout << "                    " << endl;
        cout << "ID: " << q2->ID << endl;
        cout << "Pelicula: " << q2->movieTitle << endl;
        cout << "Director: " << q2->movieDirector << endl;
        cout << "Anio de lanzamiento: " << q2->yearReleased << endl;
        cout << "Duracion: " << q2->runningTime << endl;
        q2 = q2->link;
        delete p2;
        p2 = q2;
    }
}

struct time *HacerCaja(){
    q3 = new struct time;
    if (q3 == NULL){
        return NULL;
    }
    cout << "                    " << endl;
    cout << "Dame los segundos: "<< endl;
    cin >> q3->seconds;
    cout << "Dame los minutos: " << endl;
    cin >> q3->minutes;
    cout << "Dame las horas: "<< endl;
    cin >> q3->hours;
    return  q3;
}

void Push(struct time *q3){
    if (q3 == NULL){
        return;
    }
    q3->link = p3;
    p3 = q3;
}

struct time *Pop(){
    q3 = p3;
    if (p3 != NULL){
        p3 = p3->link;
    }
    return q3;
}

void LlenarCaja(){
    while (OtraCaja()){
        Push(HacerCaja());
    }
}

void ImprimeCaja(struct time *p3, struct time *q3){
    p3 = q3;
    for(;p3 != NULL;){
        cout << "                    " << endl;
        cout << "Segundos: " << q3->seconds << endl;
        cout << "Minutos: " << q3->minutes << endl;
        cout << "Horas: " << q3->hours << endl;
        q3 = q3->link;
        delete p3;
        p3 = q3;
    }
}

student *HacerCajaC(){
    student *q;
    q = new student;
    cout << "                    " << endl;
    cout << "Digita tu ID: "<< endl;
    cin >> q->ID;
    cout << "Digita tu nombre: " << endl ;
    cin >> q->name;
    cout << "Digita el anio de tu inscripcion: "<< endl;
    cin >> q->enrollment;
    cout << "Digita tu promedio: " << endl ;
    cin >> q->average;
    cout << "                    " << endl;
    return q;
}

void Enqueue(student *q){
    if (q == NULL){
        return;
    }
    q->link = NULL;
    if (caja_final == NULL){
        caja_inicial = q;
    }
    else {
        caja_final->link = q;
    }
    caja_final = q;
}

void LlenarCola(){
    while (OtraCaja()){
        Enqueue(HacerCajaC());
    }
}

student *Dequeue(){
    if (caja_inicial == NULL){
        return NULL;
    }
    student *q;
    q = caja_inicial;
    caja_inicial = caja_inicial->link;
    q->link = NULL;
    if (caja_inicial == NULL){
        caja_final = NULL;
    }
    return q;
}

void ImprimeCola(){
    caja_nueva = caja_inicial;
    while ((caja_nueva = Dequeue()) != NULL){
        cout << "                    " << endl;
        cout << "ID: " << caja_nueva->ID << endl;
        cout << "Nombre: " << caja_nueva->name << endl;
        cout << "Anio de inscripcion: " << caja_nueva->enrollment << endl;
        cout << "Promedio: " << caja_nueva->average << endl;
        cout << "                    " << endl;
        caja_nueva = caja_nueva->link;
        delete caja_nueva;
    }
}

integers *HacerColaA(){
    q4 = new integers;
    cout << "                    " << endl;
    cout << "Digita el ID: " <<endl ;
    cin >> q4->ID;
    cout << "Digita el primer numero: "<< endl ;
    cin >> q4->number;
    cout << "Digita el segundo numero: "<< endl ;
    cin >> q4->number2;
    cout << "Digita el tercer numero: "<< endl;
    cin >> q4->number3;
    cout << "Digita el cuarto numero: "<< endl;
    cin >> q4->number4;
    cout << "                    " << endl;
    return q4;
}

void Push(integers * q4){
    if (q4 == NULL){
        return;
    }
    q4->link = p4;
    p4 = q4;
}

void LlenarColaA(){
    while (OtraCaja()){
        Push(HacerColaA());
    }
}

void ImprimeColaA(integers *p4, integers *q4){
    p4 = q4;
    cout << "\nImprimiendo datos..." << endl;
    for(;p4 != NULL;){
        cout << "                    " << endl;
        cout << "ID: " << q4->ID << endl;
        cout << "Numero 1: " << q4->number << endl;
        cout << "Numero 2: " << q4->number2 << endl;
        cout << "Numero 3: " << q4->number3 << endl;
        cout << "Numero 4: " << q4->number4 << endl;
        cout << "                    " << endl;
        q4 = q4->link;
        p4 = q4;
    }
}

void EnqueueA(integers_2 *q5){
    if (q5 == NULL){
        return;
    }
    q5->link2 = NULL;
    if (caja_final2 == NULL){
        caja_inicial2 = q5;
    }
    else {
        caja_final2->link2 = q5;
    }
    caja_final2 = q5;
}

void CopiarColaA(integers_2 *q5, integers_2 *p5){
    integers *aux;
    p5 = q5;
    cout << "\nElementos copiados..." << endl;
    for(;q4 != NULL;){
        q5 = new integers_2;
        q5->ID = q4->ID;
        q5->number = q4->number;
        q5->number2 = q4->number2;
        q5->number3 = q4->number3;
        q5->number4 = q4->number4;
        EnqueueA(q5);
        aux = q4;
        q4 = q4->link;
        aux->link = NULL;
        delete aux;
    }
}

void ImprimeColaB(){
    integers_2 *aux;
    while (caja_inicial2 != NULL) {
        cout << "                    " << endl;
        cout << "ID: " << caja_inicial2->ID << endl;
        cout << "Numero 1: " << caja_inicial2->number << endl;
        cout << "Numero 2: " << caja_inicial2->number2 << endl;
        cout << "Numero 3: " << caja_inicial2->number3 << endl;
        cout << "Numero 4: " << caja_inicial2->number4 << endl;
        cout << "                    " << endl;
        aux = caja_inicial2;
        caja_inicial2 = caja_inicial2->link2;
        aux->link2 = NULL;
        delete aux;
    }
}

void LlenarListaC2(){
    while (OtraCaja()){
        q6 = new celulares;
        cout << "                    " << endl;
        cout << "Digita el ID: "<< endl;
        cin >> q6->ID;
        cout << "Digita la marca: "<< endl;
        cin >> q6->marca;
        cout << "Digita el modelo: "<< endl;
        cin >> q6->modelo;
        cout << "Digita el precio: "<< endl;
        cin >> q6->precio;
        cout << "                    " << endl;
        q6->siguiente = q6;

        if(p6 == NULL){
            p6 = q6;
        }
        q6->siguiente = p6->siguiente;
        p6->siguiente = q6;
    }
}

void ImprimeListaC2(celulares *q6, celulares *p6) {
    q6 = p6;
    for (; p6->ID >= 1;) {
        p6 = q6;
        cout << "                    " << endl;
        cout << "ID: " << q6->ID << endl;
        cout << "Marca: " << q6->marca << endl;
        cout << "Modelo: " << q6->modelo << endl;
        cout << "Precio: " << q6->precio << endl;
        cout << "                    " << endl;
        q6 = q6->siguiente;
        delete p6;
        p6 = q6;
    }
}