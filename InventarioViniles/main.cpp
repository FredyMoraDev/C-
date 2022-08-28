#include <iostream> //Librería principal para usar el cout y el cin.
#include "Inventario.hpp" //Librería que se usa para poder invocar funciones dentro de esta.
#include "Ortografia.hpp" // Se usa esta librería para poder usar caracteres ASCII principalmene para los acentos

using namespace std; // Se utiliza solamente para eliminar el std.

bool otraCaja(); /*Retornará un valor booleano, false si es 0 y un true si es 1.*/

inventario *hacerInventario();/*Retornará un apuntador *p tipo struct para poder hacer la estructura*/

void push(inventario *q);/*q Se le manda como parámetro el apuntador *q tipo struct, va enlazando los enlaces con las nuevas cajas que se van creando.*/

void llenaCaja();/*Esta función no retorna nada, va armando la caja junto con la función push */

void imprimeInventario(inventario *p, inventario *q);/* p Se le manda como parámetro el apuntador *p tipo struct.
 * q Se le manda como parámetro el apuntador *q tipo struct,para que así pueda imprimir los elementos de la struct.*/

char *buscarElemento(inventario *p, inventario *q, int valor);/* p Se le manda como parámetro el apuntador *p tipo struct.
 q Se le manda como parámetro el apuntador *q tipo struct valor El usuario digitará el ID que desea buscar.
  Retorna la caja con todos sus elementos, si no se encuentra la caja se retornará un valor nulo.*/

char *comprarElemento(inventario *p, inventario *q, int valor);/* p Se le manda como parámetro el apuntador *p tipo struct.
 q Se le manda como parámetro el apuntador *q tipo struct,valor El usuario digitará el ID que desea comprar.
 Retornará la caja con los elementos comprados por el usuario,si la caja no ha sido registrada, retornará un valor nulo.*/

char *comprarElementoA(inventario *p, int valor);/* p Se le mandá como parámetro el apuntador *p tipo estructura.
  valor Se le mandá como parámetro el ID que digita el usuario. Retornará la caja con los elementos comprados por el usuario,
  si el elemento no ha sido registrado, retornará un valor nulo.*/

char *devolucionDeVinyl(inventario *p, inventario *q, int elemento);/* p Se le manda como parámetro el apuntador *p tipo struct.
 q Se le manda como parámetro el apuntador *q tipo struct. elemento El usuario digitará el ID que desea regresar,Retornará un ticket generado si el ID ya ha sido registrado previamente,
  si el ID no es correcto el sistema retornará un valor nulo y un aviso al usuario.
 */

char *devolucionDevinylA(inventario *p, int elemento);/* p Se le mandá como parámetro el apuntdor *p tipo struct.
 elemento Se le mandá como parámetro el elemento que digita el usuario.Retornará un ticket generado si el equipo ya ha sido registrado prevamente,
 si el equipo no es corrector retornará un valor nulo y un aviso al usuario.*/

void imprimeTicketC(inventario *p, inventario *q);/* p Se le manda como parámetro el apuntador *p tipo struct.
 q Se le manda como parámetro el apuntador *q tipo struct,si el ticket ha sido generado previamente se imprimirá en consola, si no ha sido
  generado no imprimirá nada */

void imprimeTicketA();/* Si ya se ha generado el ticket previamente, este se imprimirá en un archivo .txt,
 si no ha sido generado el sistema mandará un error al usuario */

void imprimeTicketCArbol(inventario *p);/*p Se le mandá como parámetro el apuntador *p tipo struct.
  Si ya se ha generado el ticket previamente, este se imprimirá en un archivo .txt,si no ha sido generado el sistema mandará un aviso al usuario.*/

bool hayHijo(int n);/*n El parámetro n determinará que lado del árbol se quiere crear Retornará un true si el usuario presiona 's' y false cuando sea 'n'*/

void eliminaNodos(inventario *p);/* p Se le mandá como parámetro el apuntador *p, y eliminará de forma recursiva los hijos de la raíz madre.*/

inventario *contruyeArbol();/* Retornará el apuntador *raiz, así mismo se contruirá el árbol, con la ayuda de la función de hayHijo; determinará si es nodo izquierdo o derecho*/

void imprimeArbolEntreOrden(inventario *p);/*p Se le mandará como parámetro el apuntador *p tipo estructura, imprimirá en orden: entre - orden.*/

inventario *busquedaBinaria(inventario *p, int valor);/* p Se le mandá como parámetro el apuntdor *p tipo estructura.
 m valor Se le mandá como parámetro el ID que digité el usuario. Retornará el ID con todos sus elementos incluidos, si el ID que busca
 * no ha sido encontrado, el sistema mandará una notificación al usuario.*/

void imprimeLista(inventario *p, inventario *q);/*p Se le mandá como parámetro el apuntador *p tipo estructura q Se le mandá como parámetro el apuntador *q tipo estructura.*/

int main() {
    // Variables definidas a 0 para evitar algún tipo de error.
    int op, op2 = 0, busq = 0, com = 0;
    int op3 = 0, man = 0;
    // Variables globales definidas a null para evitar errores en la implementación de otras funciones.
    p = NULL;
    q = NULL;
    do {
        cout << "\nMEN" << U << " PROYECTO FINAL DE ESTRUCTURAS DE DATOS: " << endl;
        cout << "______________________________" << endl;
        cout << "[1].- Pila" << endl;
        cout << "[2].- " << A << "rbol" << endl;
        cout << "[3].- Lista ligada" << endl;
        cout << "[4].- Salir" << endl;
        cout << "______________________________" << endl;
        cout << "\nIndique su opci" << o << "n :\n"<< endl;
        cin >> op;
        switch (op) {
            case 1:
                cout << "_______________________________________"<< endl;
                cout << "Bienvenido a la tienda Vinyl Revival "<< endl;
                cout << "_______________________________________"<< endl;
                cout<<""<<endl;;
                cout<<"          *******              \n";
                cout<<"      ***************          \n";
                cout<<"    *******************        \n";
                cout<<"  ***********************      \n";
                cout<<" *************************     \n";
                cout<<"************  *************    \n";
                cout<<"***********    ************    \n";
                cout<<"************  *************    \n";
                cout<<"***************************    \n";
                cout<<" *************************      \n";
                cout<<"  ***********************       \n";
                cout<<"    *******************         \n";
                cout<<"      ***************           \n";
                cout<<"          *******               \n";
                cout << "_______________________________________"<< endl;
                cout <<"      VINYL NEVER DIE             "<< endl;
                cout << "_______________________________________"<< endl;

                // Menú de opciones mostradas al usuario.
                do {
                    cout << "\nMEN" << U << ": " << endl;
                    cout << "_______________________________________"<< endl;
                    cout << "[1].- Guardar datos del artista" << endl;
                    cout << "[2].- Imprimir lista " << endl;
                    cout << "[3].- Buscar ID" << endl;
                    cout << "[4].- Comprar vinyl" << endl;
                    cout << "[5].- Regresar vinyl" << endl;
                    cout << "[6].- Imprimir ticket de compra" << endl;
                    cout << "[7].- Salir" << endl;
                    cout << "_______________________________________"<< endl;
                    cout << "\nPor favor seleccione una opci" << o << "n: \n";
                    cin >> op2;
                    switch (op2) {
                        case 1:
                            llenaCaja();// Se llena la caja para que después se puedan usar las demás opciones.
                            break;
                        case 2:
                            imprimeInventario(p, q); // Se imprimen los elementos guardados en la caja.
                            break;
                        case 3:
                            cout << "\nIntroduce el ID que buscas: "<< endl;; // El usuario introduce el ID que desea buscar, el valor que da el usuario
                            cin >> busq;// se guardará enla variable busq y entrará en la función de buscarElemento.
                            buscarElemento(p, q, busq);
                            break;
                        case 4:
                            cout << "\nIntroduce el ID del vinyl que deseas comprar: "<< endl;;// El usuario deberá de introducir el ID del VINYL que desea comprar
                            cin >> com; // el valor que de el usuario se guardará en la variable com y entrar en la función de comprarElemento.
                            comprarElemento(p, q, com);
                            break;
                        case 5:
                            cout << "\nIntroduce el ID de tu vinyl: "<< endl;;// El usuario deberá de introducir el ID de su equipo comprado previamente,
                            cin >> man; //este valorse guardará en la variable man y entrará en la función de mantenimientoEquipo.
                            devolucionDeVinyl(p, q, man);
                            break;
                        case 6:
                            do {
                                cout << "\n[1].- Imprimir ticket en consola" << endl;
                                cout << "[2].- Imprimir ticket en archivo" << endl;
                                cout << "[3].- Regresar al men" << u << "principal " << endl;
                                cout << "\nOpci" << o <<"n: "<< endl;;
                                cin >> op3;
                                switch (op3) {
                                    case 1:
                                        imprimeTicketC(p, q);// Solamente se manda la función de imprimeTicket y esta generará un ticket al usuario.
                                        break;
                                    case 2:
                                        imprimeTicketA(); // Se invoca la función imprimeTicketA y esta mostrar los elementos comprados por el usuario.
                                        break;
                                    case 3:
                                        cout << "\n________________________________________" << endl;
                                        cout << "|Regresando al men" << u <<" principal... |" << endl;
                                        cout << "\n________________________________________" << endl;
                                        break;
                                    default:
                                        cout << "\nElija una opci" << o << "n v" << a << "lida" << endl;
                                        break;
                                }
                            } while (op3 != 3);
                            break;
                        case 7:
                            cout << "\nRegrese pronto...VINYL NEVER DIE" << endl;
                            break;
                        default:
                            cout << "\nPor favor, elija una opci"<< o << "n v"<< a << "lida" << endl;
                            break;
                    }
                } while (op2 != 7);
                break;
            case 2:
                cout << "_______________________________________"<< endl;
                cout << "Bienvenido a la tienda Vinyl Revival "<< endl;
                cout << "_______________________________________"<< endl;
                cout<<""<<endl;;
                cout<<"          *******              \n";
                cout<<"      ***************          \n";
                cout<<"    *******************        \n";
                cout<<"  ***********************      \n";
                cout<<" *************************     \n";
                cout<<"************  *************    \n";
                cout<<"***********    ************    \n";
                cout<<"************  *************    \n";
                cout<<"***************************    \n";
                cout<<" *************************      \n";
                cout<<"  ***********************       \n";
                cout<<"    *******************         \n";
                cout<<"      ***************           \n";
                cout<<"          *******               \n";
                cout << "_______________________________________"<< endl;
                cout <<"      VINYL NEVER DIE             "<< endl;
                cout << "_______________________________________"<< endl;

                do {
                    cout << "\nMEN" << U << ": " << endl;
                    cout << "__________________________________" << endl;
                    cout << "[1].- Guardar datos del artista" << endl;
                    cout << "[2].- Imprimir lista " << endl;
                    cout << "[3].- Buscar ID" << endl;
                    cout << "[4].- Comprar vinyl" << endl;
                    cout << "[5].- Regresar vinyl" << endl;
                    cout << "[6].- Imprimir ticket de compra" << endl;
                    cout << "[7].- Salir" << endl;
                    cout << "__________________________________" << endl;
                    cout << "\nPor favor seleccione una opci" << o << "n: "<< endl;;
                    cin >> op2;
                    switch (op2) {
                        case 1:
                            p = contruyeArbol();// Se construye el arból para que después se puedan usar las demás opciones.
                            break;
                        case 2:
                            imprimeArbolEntreOrden(p);// Se construye el arból para que después se puedan usar las demás opciones.
                            break;
                        case 3:
                            cout << "\nIntroduce el ID que buscas: "<< endl;;// El usuario introduce el ID que desea buscar, el valor que de el usuario
                            cin >> busq;//se guardará en la variable busq y entrará en la función de buscarElemento.
                            busquedaBinaria(p, busq);
                            break;
                        case 4:
                            cout << "\nIntroduce el ID del vinyl que deseas comprar: "<< endl;; //El usuario deberá de introducir el ID del vinyl que desea comprar,
                            cin >> com;//el valor que de el usuario se guardará en la variable com y entrará en la función de comprarElemento.
                            comprarElementoA(p, com);
                            break;
                        case 5:
                            cout << "\nIntroduce el ID de tu vinyl: "<< endl;;//El usuario deberá de introducir el ID del vinyl que comrpo previamente
                            cin >> man; //* este valorse guardará en la variable man y entrará en la función de devolucionDevinylA
                            devolucionDevinylA(p, man);
                            break;
                        case 6:
                            do {
                                cout << "\n[1].- Imprimir ticket en consola" << endl;
                                cout << "[2].- Imprimir ticket en archivo" << endl;
                                cout << "[3].- Men" << u << " principal" << endl;
                                cout << "\nOpci" << o << "n: "<< endl;;
                                cin >> op3;
                                switch (op3) {
                                    case 1:
                                        imprimeTicketCArbol(p);// Solamente se manda la función de imprimeTicket y esta generará un ticket al usuario.
                                        break;
                                    case 2:
                                        imprimeTicketA();// Se invoca la función imprimeTicketA y esta mostrará los elementos comprados por el usuario.
                                        break;
                                    case 3:
                                        cout << " " << endl;
                                        cout << "Regresando al men" << u << " principal..." << endl;
                                        cout << " " << endl;
                                        break;
                                    default:
                                        cout << "\nElija una opci" << o << "n v" << a << "lida" << endl;
                                        break;
                                }
                            } while (op3 != 3);
                            break;
                        case 7:
                            cout << "\nRegrese pronto...VINYL NEVER DIE" << endl;
                            break;
                        default:
                            cout << "\n" << endl;
                            cout << "\nPor favor, elija una opci" << o << "n v" << a << "lida" << endl;
                            cout << "\n" << endl;
                            break;
                    }
                } while (op2 != 7);
                break;
            case 3:
                cout << "_______________________________________"<< endl;
                cout << "Bienvenido a la tienda Vinyl Revival "<< endl;
                cout << "_______________________________________"<< endl;
                cout<<""<<endl;;
                cout<<"          *******              \n";
                cout<<"      ***************          \n";
                cout<<"    *******************        \n";
                cout<<"  ***********************      \n";
                cout<<" *************************     \n";
                cout<<"************  *************    \n";
                cout<<"***********    ************    \n";
                cout<<"************  *************    \n";
                cout<<"***************************    \n";
                cout<<" *************************      \n";
                cout<<"  ***********************       \n";
                cout<<"    *******************         \n";
                cout<<"      ***************           \n";
                cout<<"          *******               \n";
                cout << "_______________________________________"<< endl;
                cout <<"      VINYL NEVER DIE             "<< endl;
                cout << "_______________________________________"<< endl;

                do {
                    cout << "\nMEN" << U << ": " << endl;
                    cout << "__________________________________" << endl;
                    cout << "[1].- Guardar datos del artista" << endl;
                    cout << "[2].- Imprimir lista " << endl;
                    cout << "[3].- Buscar ID" << endl;
                    cout << "[4].- Comprar vinyl" << endl;
                    cout << "[5].- Regresar vinyl" << endl;
                    cout << "[6].- Imprimir ticket de compra" << endl;
                    cout << "[7].- Salir" << endl;
                    cout << "__________________________________" << endl;
                    cout << "\nPor favor seleccione una opci" << o << "n: "<< endl;;
                    cin >> op2;
                    switch (op2) {
                        case 1:
                            llenaCaja();// Se llena la caja para que después se puedan usar las demás opciones.
                            break;
                        case 2:
                            imprimeLista(p, q);// Se imprimen los elementos guardados en la caja.
                            break;
                        case 3:
                            cout << "\nIntroduce el ID que buscas: "<< endl;;// El usuario introduce el ID que desea buscar, el valor que da el usuario
                            cin >> busq;//se guardará enla variable busqy entrará en la función de buscarElemento.
                            buscarElemento(p, q, busq);
                            break;
                        case 4:
                            cout << "\nIntroduce el ID del vinyl que deseas comprar: "<< endl;;// El usuario deberá de introducir el ID del vinyl que desea comprar
                            cin >> com;// el valor que de el usuario se guardará en la variable com y entrará en la función de comprarElemento.
                            comprarElemento(p, q, com);
                            break;
                        case 5:
                            cout << "\nIntroduce el ID de tu vinyl: "<< endl;;// El usuario deberá de introducir el ID de su vinyl comprado previamente,
                            cin >> man; //este valorse guardará en la variable man y entrará en la función de devolucionDeVinyl
                            devolucionDeVinyl(p, q, man);
                            break;
                        case 6:
                            do {
                                cout << "\n[1].- Imprimir ticket en consola" << endl;
                                cout << "[2].- Imprimir ticket en archivo" << endl;
                                cout << "[3].- Men" << u << " principal" << endl;
                                cout << "\nOpci" << o << "n: "<< endl;;
                                cin >> op3;
                                switch (op3) {
                                    case 1:
                                        imprimeTicketC(p, q);// Solamente se manda la función de imprimeTicket y esta generará un ticket al usuario.
                                        break;
                                    case 2:
                                        imprimeTicketA();// Se invoca la función imprimeTicketA y esta mostrará los elementos comprados por el usuario.
                                        break;
                                    case 3:
                                        cout << "\n" << endl;
                                        cout << "Regresando al men" << u << " principal..." << endl;
                                        cout << " " << endl;
                                        break;
                                    default:
                                        cout << "\nElija una opci" << o << "n v" << a << "lida" << endl;
                                        break;
                                }
                            } while (op3 != 3);
                            break;
                        case 7:
                            cout << "\nRegrese pronto...VINYL NEVER DIE" << endl;
                            break;
                        default:
                            cout << "\n" << endl;
                            cout << "\nPor favor, elija una opci" << o <<"n v" << a << "lida" << endl;
                            cout << "\n" << endl;
                            break;
                    }
                } while (op2 != 7);
                break;
            case 4:
                cout << " _____________________________ " << endl;
                cout << "|     Saliendo del sistema    |" << endl;
                cout << " _____________________________ " << endl;
                break;
            default:
                cout << "\nPorfavor, elija una opci" << o << "n v" << a << "lida" << endl;
                break;
        }
    } while (op != 4);
    return 0;
}