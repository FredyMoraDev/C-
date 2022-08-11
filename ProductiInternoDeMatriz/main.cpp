#include <iostream>
using namespace std;

void LimpiarMemoriau(int *vector1);
void LimpiarMemoriav(int *vector2);
void LimpiarMatriz(int **A,int n);
void PideDatosVectorU(int *vector1, int tam);
void PideDatosVectorV(int *vector2, int tam);
double productoPunto(int *u,int *v, int n);
void PideDatosMatriz(int **A,int n,int m);
void prodMatrizVector(int **A,int *v,int n,int m);
void PideDatosMatrizB(int **B,int n,int m);
void MatrizPorMatriz(int **A,int **B,int n1,int m1,int m2);

int main(){
    int n,m,n1,m1,n2,m2,opc;
    int *v,*u,**A,**B;
    int **prodMatrMatr;
    int *prodMartVect;
    do{
        cout<<"\tProducto de matriz"<< endl;
        cout<<"\t Elije una opcion"<< endl;
        cout<<"1. Producto interior o producto punto"<< endl;
        cout<<"2. Producto interior de matriz o vector"<< endl;
        cout<<"3. Producto interno de matriz por matriz"<< endl;
        cout<<"4. SALIR"<< endl;
        cin>>opc;

        switch(opc){
            case 1:
                cout<<"De que tamanio son los vectores U y V: "<< endl;
                cin>> n;
                v = new int[n];
                u = new int[n];
                cout<<"Cuales son los datos de vector U "<< endl;
                PideDatosVectorU(u,n);
                cout<<"Cuales son los datos de vector V "<< endl;
                PideDatosVectorV(v,n);
                cout<<"El producto punto de u por v es: "<< productoPunto(u,v,n)<< endl;
                LimpiarMemoriau(u);
                LimpiarMemoriav(v);
                break;

            case 2:
                cout<<"De que tamanio es el vector?: "<< endl ;
                cin >> n;
                v = new int[n];
                cout<<"Cuales son los datos de vector V: "<<endl;
                PideDatosVectorV(v,n);
                prodMartVect = new int[n];
                A = new int *[n];
                cout << "La matriz debe tener "<< n <<" renglones" <<"\n\n Cuantas columnas tiene?"<< endl;
                cin >> m;
                for(int i = 0; i < n ; i++){
                    A[i]=new int [m];
                }
                PideDatosMatriz(A,n,m);
                prodMatrizVector(A,v,n,m);
                LimpiarMemoriav(v);
                LimpiarMatriz(A,n);
                break;

            case 3:
                cout<<"Tamanio es la matriz A"<< endl;
                cout<<"Cuantos Renglones: "<< endl;
                cin >> n1;
                cout << "Cuantas Columnas: "<< endl;
                cin >> m1;
                A = new int *[n1];
                for(int i = 0 ; i < n1 ; i++){
                    A[i]=new int [m1];
                }
                cout<<"Tamanio es la matriz B"<<endl;
                cout<<"Cuantos renglones: "<<endl;
                cin >> n2;
                cout<<"Cuantas Columnas: "<<endl;
                cin >> m2;
                if(m1!=n2){
                    cout<<"Error! el numero de columnas de A debe ser igual al de renglones de B"<< endl;
                    break;
                }
                B = new int *[n2];
                for(int i = 0 ;i < n2 ; i++){
                    B[i]=new int [m2];
                }
                prodMatrMatr=new int *[n1];
                for(int i = 0 ; i < n1 ; i++){
                    prodMatrMatr[i]=new int [m2];
                }
                cout<<"Proporciona los datos de la matriz A "<<endl;
                PideDatosMatriz(A,n1,m1);
                cout << "--------------------------------------" << endl;
                cout<<"Proporciona los datos de la matriz B "<<endl;
                PideDatosMatrizB(B,n2,m2);
                cout << "--------------------------------------" << endl;
                MatrizPorMatriz(A,B,n1,m1,m2);
                LimpiarMatriz(A,n1);
                LimpiarMatriz(B,n2);
                break;

            case 4:
                cout<<"SALIENDO..."<< endl;
                break;

            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opc!=4);
    return 0;
}
void PideDatosVectorU(int *vector1, int tam){
    for (int i=0;i<tam;i++){
        cout<<"  Dato "<< i+1 <<" : "<<endl;
        cin>>vector1[i];
    }
}

void PideDatosVectorV(int *vector2, int tam){
    for (int i=0;i<tam;i++){
        cout<<"  Dato "<< i+1 << " : "<<endl;
        cin>>vector2[i];
    }
}

double productoPunto(int *u,int *v, int n){
    int prod = 0;
    for(int i = 0; i < n; i++){
        prod = prod + u[i]*v[i];
    }
    return prod;
}

void prodMatrizVector(int **A,int *v,int n,int m){
    double *prod;
    prod = new double[n];
    for( int i = 0; i < n ; i++){
        prod[i]=0;
        for(int j = 0; j < m ; j++){
            prod[i]=prod[i]+A[i][j]*v[j];
        }
    }
    cout<<" El producto de A*V es : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<"| "<< prod[i] <<" | "<<endl;
    }
    }

void PideDatosMatriz(int **A,int n,int m){
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            cout<<" Dame dato para la posicion ("<<i<<","<<j<<") : ";
            cin>>A[i][j];
        }
    }
}
void PideDatosMatrizB(int **B,int n,int m){
    for(int i = 0;i < n ;i++){
        for(int j = 0; j < m; j++){
            cout<<"Dame dato para la posicion ("<<i<<","<<j<<") : ";
            cin>>B[i][j];
        }
    }
}
void MatrizPorMatriz(int **A,int **B,int n1,int m1,int m2){
    int**prod;
    prod=new int *[n1];
    for(int i=0;i<n1;i++){
        prod[i]=new int [m1];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            prod[i][j]=0;
            for(int k=0;k<m2;k++){
                prod[i][j]= prod[i][j]+A[i][k]*B[k][j];
            }
        }
    }
    cout<<"El producto de la matriz A y B es: "<<endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cout<<"\t"<<prod[i][j]<<endl;
        }
    }
}

void LimpiarMatriz(int **A,int n){
    if(A != NULL){
        for(int i=0; i<n; i++){
            if (A[i] != NULL){
                delete[] A [i];
            }
        }
        delete [] A;
    }
}

void LimpiarMemoriau(int *vector1){
    if(vector1 !=NULL){
        delete[] vector1;
    }
}

void LimpiarMemoriav(int *vector2){
    if(vector2 !=NULL){
        delete[] vector2;
    }
}