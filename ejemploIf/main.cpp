#include <iostream>
#define N 3
using namespace std;

int main(){
    int opc, pmayor;
    float n1, n2,n3,mayor;

    struct persona {
    char nombre [20];
    float promedio;
    } persona[N];
    do {
        cout<<"____________________________________________________"<<endl;
        cout<<"1. Ejemplo de uso de if"<<endl;
    	cout<<"2. ejemplo de uso if-else"<<endl;
    	cout<<"3. salir"<<endl;
    	cout<<"Seleccione una opcion:"<<endl;
    	cout<<"______________________________________________________"<<endl;
    	cin>>opc;

        switch(opc){
            case 1:
                for (int i = 0 ; i < N ; i++ ){
                    cout<<"Dame el nombre " << i+1 << " sin usar espacios:"<<endl;
                    cin>>persona[i].nombre;
                    cout<<"Dame el promedio del alumno :"<<endl;
                    cin>> persona[i].promedio;
                }
                for (int i = 0; i < N; ++i)
                    if (persona[i].promedio > mayor){
                        mayor = persona[i].promedio;
                        pmayor = i;
                    }
                cout<<"El alumno con mejor promedio es:"<<persona[pmayor].nombre<<endl;
                cout<<"Su promedio es: "<<persona[pmayor].promedio<<endl;
                break;

                case 2:
                cout << "Introduzca el primer numero:"<<endl;
                cin>>n1;
                cout << "Introduzca el segundo numero:"<<endl;
                cin>>n2;
                cout<<"Introduzca el tercer numero:"<<endl;
                cin >> n3;
                if ( n1 >= n2 && n1 >= n3 )
                    cout<< n1 <<"  es el numero mayor"<<endl;
                else
                    if ( n2 > n3 )
                        cout<< n2 <<"  es el numero mayor"<<endl;
                    else
                        cout<< n3 <<"  es el numero mayor" << endl;
                    break;

                    case 3:
                    cout<<"Gracias por usar el programa"<<endl;
                    break;

                    default:
                        cout<<"Opcion no valida"<<endl;
                        break;
        }
    }while(opc != 3);
    return 0;
}
