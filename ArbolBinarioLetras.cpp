#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

struct Nodo{
    char dato;
    Nodo *izquierdo;
    Nodo *derecho;
};
//prototipo de funcion
Nodo *crearNodo(char);
void insertarNodo(Nodo *&, char);
void mostrarArbol(Nodo *&, int);
//recorridos
void preOrden(Nodo *&);
void enOrden(Nodo *&);
void postOrden(Nodo *&);
Nodo *arbol = NULL;

int main(){
    //int arreglo[6]={10,5,15,4,8,20};
    string cadena;//cadena de caractetes que se van a insertar
    int datos, opcion, contador=5, x;
    bool bandera = true;
    do{
        cout << "\nMenu" << endl;
        cout << "1.- insertar caracteres " << endl;
        cout << "2.- mostrarArbol" << endl;
        cout << "3.- Recorridos" << endl;
        cout << "4.- Salir" << endl;

        cin>>opcion;
        switch(opcion){
            case 1:
              cout << "insertar caracteres (sin espacios)";
              cin.ignore();//limpiar el buffer
					    getline(cin,cadena);
              for (int i = 0; i < cadena.length(); i++) {
                insertarNodo(arbol,cadena[i]);
              }
              cout << endl;
              system("pause");
              break;


            case 2:
              cout << "\nMostrado Arbol completo" << endl;
              mostrarArbol(arbol, contador);
              system("pause");
              break;

            case 3:
              cout << "Recorridos " << endl;
              cout << "\n\n En orden   :  ";   enOrden(arbol);
              cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
              cout << "\n\n Post Orden :  ";   postOrden(arbol);
              cout << endl << endl;
              system("pause");
              break;
            case 4:
              break;
        }//fin de switch
        system("cls");
    }while(opcion != 4);
	return 0;
}
//funcion para crear un nuevo nodo
Nodo *crearNodo (char n){
    Nodo *inicio = new Nodo ();
    inicio->dato = n;
    inicio->izquierdo = NULL;
    inicio->derecho = NULL;

    return inicio;
}
//insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, char n){
    if(arbol == NULL){//si el arbol esta vacio
        Nodo *inicio = crearNodo(n);
        arbol = inicio;
    }else{//si el arbol tiene un noda mas
        char valorRaiz = arbol->dato;//obtenemos el valor de la raiz
        if(n < valorRaiz){//si el elemento es menor a la raiz, insertamos en izquierda
            insertarNodo(arbol->izquierdo, n);
        }else{//si el elemento es mayor a la izq, insertamos en derecha
            insertarNodo(arbol->derecho, n);
        }
    }
}

void mostrarArbol(Nodo *&arbol, int n){
  if(arbol==NULL)
        return;
   mostrarArbol(arbol->derecho, n+1);

   for(int i=0; i<n; i++)
       cout<<"   ";


   cout<< arbol->dato <<endl;

   mostrarArbol(arbol->izquierdo, n+1);
}

void preOrden(Nodo *&arbol){
  if(arbol!=NULL){
    cout << arbol->dato <<" ";
    preOrden(arbol->izquierdo);
    preOrden(arbol->derecho);
  }
}
void enOrden(Nodo *&arbol){
  if(arbol!=NULL){
    enOrden(arbol->izquierdo);
    cout << arbol->dato << " ";
    enOrden(arbol->derecho);
  }
}
void postOrden(Nodo *&arbol){
  if(arbol!=NULL){
    postOrden(arbol->izquierdo);
    postOrden(arbol->derecho);
    cout << arbol->dato << " ";
  }
}
