#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
using namespace std;
struct Nodo{
    char dato;
    Nodo *izquierdo;
    Nodo *derecho;
};
//prototipo de funcion
void mostrarArbol(Nodo *&arbol, int cont, int i);
Nodo *crearNodo(char);
Nodo *arbol = NULL;

int main(){
    int contador = 0;
    arbol = crearNodo('*');
    arbol->izquierdo = crearNodo('X');
    arbol->derecho = crearNodo('/');


    cout << endl << endl << endl;
    cout << "\nMostrado Arbol completo" << endl;
              for (int i = 0; i < 10; i++) {
                mostrarArbol(arbol,contador,i);
                cout << endl;
              }
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
void mostrarArbol(Nodo *&arbol, int cont, int i){
    if(arbol == NULL){//si el arbol esta vacio
      return;
    }else{//si el arbol tiene un nodo o mas
      mostrarArbol(arbol->izquierdo, cont+1, i);
      if(cont == i){
        cout << setw(10-i) << arbol->dato;
      }
      mostrarArbol(arbol->derecho, cont+1, i);
    }
}
