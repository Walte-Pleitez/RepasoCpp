#include <iostream>
//hecho en 24 min
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguente;
};
bool Vacia(Nodo *&);
void Push(Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&);

int main(){
    Nodo *Pila = nullptr;
    int input, continuar = 1, eleccion;

    do{
        cout<<"1)Agregar Nodo 2)Imprimir Nodos 3)Eliminar Nodo"<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
            cout<<"Ingrese un valor para el Nodo: "<<endl;
            cin>>input;
            Push(Pila, input);
            break;
            case 2:
            Imprimir(Pila);
            break;
            case 3:
            Pop(Pila);
            break;
        }

        cout<<"1)MENU  0)SALIR"<<endl;
        cin>>continuar;
    }while(continuar == 1);

    return 0;
}
bool Vacia(Nodo *&pila){
    if(pila == nullptr){
        return true;
    }
    else{
        return false;
    }
}
void Push(Nodo *&pila, int dato){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = dato;
    nuevoNodo->siguente = pila;
    pila = nuevoNodo;

    cout<<"Se agrego un Nodo con valor: "<<dato<<endl;
}
void Imprimir(Nodo *&pila){
    Nodo *printer = pila;
    int contador = 0;
     while(printer != nullptr){
         contador++;

         cout<<"Valor: "<<printer->elemento<<" Posicion: "<<contador<<" DirValor: "<<printer<<" DirValorSig: "<<printer->siguente<<endl;

         printer = printer->siguente;
     }
}
void Pop(Nodo *&pila){
    int contenedor;
    Nodo *aux = pila;

    contenedor = aux->elemento;
    pila = aux->siguente;
    delete aux;

    cout<<"Se elimino un Nodo con valor: "<<contenedor<<endl;
}