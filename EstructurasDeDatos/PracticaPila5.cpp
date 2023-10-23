#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&);

int main(){
    Nodo *Pila = nullptr;
    int input, eleccion, continuar = 1;

    do{
        cout<<"1) Agregar Nodo 2)Imprimir Pila 3)Eliminar Nodo"<<endl;
        cin>>eleccion;

    switch(eleccion){
        case 1:
        cout<<"Ingrese el valor para el nodo"<<endl;
        cin>>input;
        Push(Pila, input);
        cout<<"---------- Se agrego un nuevo Nodo con valor: "<<input<<"----------"<<endl;
        break;
        case 2:
        cout<<"---------- Pila: ---------"<<endl;
        Imprimir(Pila);
        break;
        case 3:
        Pop(Pila);
        break;
    }

    cout<<"1) MENU 0) SALIR"<<endl;
    cin>>continuar;
    }while(continuar == 1);

    return 0;
}

void Push(Nodo *&pila, int n){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
    cout<<endl;
}
void Imprimir(Nodo *&pila){
    Nodo *pilaActual = pila;

    while(pilaActual != nullptr){
        cout<<"Valor: "<<pilaActual->elemento<<" Dir.Valor: "<<pilaActual<<" DirSigValor: "<<pilaActual->siguiente<<endl;

        pilaActual = pilaActual->siguiente;
    }
}
void Pop(Nodo *&pila){
    Nodo *pilaAux = pila;
    int dato;

    pila = pilaAux->siguiente;
    dato = pilaAux->elemento;
    delete pilaAux;

    cout<<"--------- Se elimino un nodo con valor: "<<dato<<" ----------"<<endl;
    cout<<endl;
}

