#include <iostream>

using namespace std;

int main(){
    int opc;
    float a,*ptr;
    do {
        cout << "_______________MENU______________" << endl;
        cout << " Problema 1" << endl;
        cout << " Problema 2" << endl;
        cout << " Problema 3" << endl;
        cout << " Problema 4" << endl;
        cout << " Salir 5" << endl;
        cout << " Elige una opcion" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                ptr = &a;// a ptr se le asigna la direccion de a
                *ptr = 24;//  a ptr se le asigna el valor de 24
                cout << "Direccion de memoria de a " << &a << endl;
                cout << "Direccion de memoria de *ptr  " << &ptr << endl;
                cout << "a vale: " << a << endl;
                cout << "ptr vale: " << ptr << endl;
                cout << "el valor el que apunta ptr vale: " << *ptr << endl;
                break;

            case 2:
                float **ptr2;
                ptr2 = &ptr;
                cout << "Direccion de memoria de **ptr2 " << &ptr << endl;
                *ptr = 60;
                cout << "EL valor que apunta **ptr2 es " << *ptr << endl;
                break;

            case 3:
                int i,j;
                int *a1, *b, *c;
                a1 = &i;
                b = &i;
                c = &j;
                *b = 8;
                *c = 9;
                *a1 = 2*  *b + *c +  3 * *b;
                cout << "EL valor de i es : " << i << endl;
                cout << "EL valor de j es : " << j << endl;
                break;

            case 4:
            {
                float  x = 30;
                float y = 45;
                float *ptr1, *pt2, **ptr3;
                ptr1 = &x;
                pt2 = &y;
                ptr3 = &ptr1;
                x = *ptr1 + x;
                *pt2 = 3 * y + 2 * **ptr3;
                *ptr3 = &y;
                ptr3 = &pt2;
                *ptr3 = &x;
                **ptr3 = *pt2 - *ptr1 * x;
                *ptr3 = &y;
                cout << "El valor de x es: " << x << endl;
                cout << "El valor de y es: " << y << endl;
            }break;

            case 5:
                cout << "Hasta luego" << endl;
                break;

            default:
                cout << "Opcion no valida" << endl;
              break;
        }
        }while(opc != 5);


    return 0;
}