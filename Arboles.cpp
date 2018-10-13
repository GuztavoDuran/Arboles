#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *izquierdo;
    Nodo *derecho;
};
//prototipo de funcion
void menu(int []);
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *&, int);
Nodo *arbol = NULL;
int arreglo[50];
int main(){
    //int arreglo[6]={10,5,15,4,8,20};

    int datos, opcion, contador=0, x;
    bool bandera = true;
    do{
        cout << "\nMenu" << endl;
        cout << "1.- insertar datos" << endl;
        cout << "2.- mostrarArbol" << endl;
        cout << "3.- Salir" << endl;
        cin>>opcion;
        switch(opcion){
            case 1:
              cout << "total de datos:(maximo 50 valores) ";
              cin >> datos;
              for (size_t i = 0; i < datos; i++) {
                do{
                  cout << "inserte: ";
                  cin >> arreglo[i];
                  for (size_t j = 0; j < datos; j++) {
                    if(i != j){
                      if(arreglo[j] == arreglo[i]){
                        cout << "valor repetido " << endl;
                        bandera = false;
                        break;
                      }else{
                        //arreglo[i] = x;
                        bandera = true;
                      }
                    }
                  }
                }while (bandera != true);
                insertarNodo(arbol,arreglo[i]);
              }
              cout << endl;
              system("pause");
              break;


            case 2:
              cout << "\nMostrado Arbol completo" << endl;
              mostrarArbol(arbol, contador);
              system("pause");
              break;
        }//fin de switch
        system("cls");
    }while(opcion != 3);
	return 0;
}
//funcion para crear un nuevo nodo
Nodo *crearNodo (int n){
    Nodo *inicio = new Nodo ();
    inicio->dato = n;
    inicio->izquierdo = NULL;
    inicio->derecho = NULL;

    return inicio;
}
//insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){//si el arbol esta vacio
        Nodo *inicio = crearNodo(n);
        arbol = inicio;
    }else{//si el arbol tiene un noda mas
        int valorRaiz = arbol->dato;//obtenemos el valor de la raiz
        if(n < valorRaiz){//si el elemento es menor a la raiz, insertamos en izquierda
            insertarNodo(arbol->izquierdo, n);
        }else{//si el elemento es mayor a la izq, insertamos en derecha
            insertarNodo(arbol->derecho, n);
        }
    }
}

void mostrarArbol(Nodo *&arbol, int cont){
    if(arbol == NULL){//si el arbol esta vacio
        return;
    }else{//si el arbol tiene un nodo o mas
        mostrarArbol(arbol->derecho, cont+1);
        for(int i=0; i<cont;i++){
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierdo, cont+1);
    }
}

//insertar con un arreglo y se mape solito
//no acepte datos repetidos
//imprima hacia abajo
