#include <iostream>
/*EJERCICIO 1:
Agregar elementos a la Pila hasta que el usuario quiera, despues mostrar los numeros introducidos 
*/
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, int);
void Imprimir(Nodo *);
void Pop(Nodo *&, int);

int main(){
    struct Nodo *Pila = nullptr;
    int continuar=1, dato;

    do{
        int contador = 0, respuesta;
        cout<<"Agregue elemento "<<endl;
        cin>>dato;
        Push(Pila, dato);

        cout<<"1) Agregar otro Nodo 0) Salir"<<endl;
        cin>>respuesta;
        if(respuesta==1){
            continuar = 1;
        }
        else{
            continuar = 0;
        }
    }while(continuar==1);
    Imprimir(Pila);

    return 0;
}
void Push(Nodo *&pila, int contenido){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = contenido;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
    cout<<"--------- Nodo con valor: "<<contenido<<" agregado ---------"<<endl;
}
void Imprimir(Nodo *pila){
    Nodo *pilaTemp = pila;

    while(pilaTemp != nullptr){
        cout<<"Valor: "<<pilaTemp->elemento<<" - Dir. de Valor: "<<pilaTemp<<" - Dir. sig valor: "<<pilaTemp->siguiente<<endl;

        pilaTemp = pilaTemp->siguiente;
    }
}
void Pop(Nodo *&pila, int contenido){
    Nodo *aux = pila;

    contenido = aux->elemento; 
    pila = aux->siguiente;
    delete aux;

    cout<<"Se elimino Nodo con valor: "<<contenido<<endl;
}