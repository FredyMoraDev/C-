#include <iostream>

using namespace std;
struct s_materia{
    char nombre[30];
    float calific;
};
void LiberarMemoria(struct s_materia *arr);
void ImprimeDatosMaterias(struct s_materia *arr,int n);
void LlenarDatosMaterias(struct s_materia *arr,int n);
float Promedio(float cal[7]);
double LeerArray(double **ArrayA,int N, int M);
double Triplicar(double **ArrayA,double **ArrayB, int N, int M);
void imprimirArrays(double **ArrayA,double **ArrayB,int N, int M);
void liberarA(double **ArrayA,int N);
void liberarB(double **ArrayB,int N);

int main() {
    int opc,N,M;
    float calif[7];
    double **ArrayA,**ArrayB;

    do {
        cout << "____________________________________________________" << endl;
        cout << "1.- Promedios y liberando memoria" << endl;
        cout << "2.- Arreglo triplicado" << endl;
        cout << "3.- LlenadatosMaterias y liberando memoria" << endl;
        cout << "4.- Salir" << endl;
        cout << "Indica tu opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Promedios" << endl;
                Promedio(calif);
                break;

            case 2:
                //Entrada de datos
                cout << "Dame el valor de la fila: ";
                cin >> N;
                cout << "Dame el valor de la columna: ";
                cin >> M;
                ArrayA = new double *[N];
                for (int i = 0; i < N; i++) {
                    ArrayA[i] = new double[M];
                }
                LeerArray(ArrayA,N,M);
                //Alojamiento de memoria.
                ArrayB = new double *[N];
                for (int i = 0; i < N; i++) {
                    ArrayB[i] = new double[M];
                }
                //Proceso
                Triplicar(ArrayA,ArrayB,N,M);
                //Alojamiento de memoria.
                //Imprimir datos.
                imprimirArrays(ArrayA,ArrayB,N,M);
                //Desalojamiento de memoria.
                liberarA(ArrayA,N);
                liberarB(ArrayB,N);
                break;
            case 3:
                //Entrada
                struct s_materia *arr;
                int n;
                cout << "Dame el tamannio del arreglo: \n" <<endl;
                cin >>n;
                arr = new struct s_materia[n];
                //llenar datos
                LlenarDatosMaterias(arr,n);
                //imprimir dato
                ImprimeDatosMaterias(arr,n);
                //Desalojar memoria
                LiberarMemoria (arr);
                break;

            case 4:
                puts("Saliendo...");
                break;

                default:
                    cout << "Esa opcion no existe";
                    break;
        }
    }while (opc != 4);
    return 0;
}

float Promedio(float calif[7]){
        float sum = 0.0, Promedio = 0.0;
        for (int i = 0; i < 7; i++){
            cout <<"Dame la calificacion " << i + 1 << ": \n";
            cin >> calif[i];
            sum += calif[i];
        }
        Promedio = sum / 7;
        cout << "El promedio es: "<< Promedio << endl ;
        return Promedio;
    }

void LiberarMemoria (struct s_materia *arr) {
        if (arr != NULL){
            delete [] arr;
        }
}

void ImprimeDatosMaterias(struct s_materia *arr,int n){
    for (int i = 0; i < n ; ++i) {
        cout <<"_________________________________________" << endl;
        cout << "La materia "<< i+1<<" es: "<<arr[i].nombre<< endl;
        cout << "La calificacion es: "<<arr[i].calific<< endl;
    }
}

void LlenarDatosMaterias(struct s_materia *arr,int n){
    cout <<""<<endl;
    for (int i = 0; i < n ; ++i) {
        cout << "Dame el nombre de la materia "<< i+1 <<endl;
        cin >>arr[i].nombre;
        cout << "Dame la calificacion de la materia "<< i+1<<endl;
        cin >> arr[i].calific;
    }
}

double LeerArray( double **ArrayA, int N, int M){
    //Captura de datos.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Dame un valor para la posicion ["<<i<<"] ["<<j<<"] :\n ";
            cin >> ArrayA[i][j];
        }
    }
}

double Triplicar(double **ArrayA,double **ArrayB, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ArrayB[i][j] = ArrayA[i][j]*3;
        }
    }
}

void imprimirArrays(double **ArrayA,double **ArrayB,int N, int M){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "El valor del Arreglo A en la posicion ["<<i<<"] ["<<j<<"]- es: " << ArrayA[i][j] << "\n";
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "El valor del Arreglo B en la posicion ["<<i<<"] ["<<j<<"]- es: " << ArrayB[i][j] << "\n";
        }
    }
}

void liberarA(double **ArrayA,int N){
    if (ArrayA != NULL) {
        for (int i = 0; i < N; i++) {
            delete[] ArrayA[i];
        }
        delete[] ArrayA;
    }
}

void liberarB(double **ArrayB,int N){
    if (ArrayB != NULL) {
        for (int i = 0; i < N; i++) {
            delete[] ArrayB[i];
        }
        delete[] ArrayB;
    }
}
