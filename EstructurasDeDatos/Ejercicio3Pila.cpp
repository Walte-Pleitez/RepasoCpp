#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    Nodo *siguiente;
};

void Push(Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&, int);

int main(){
    Nodo *Pila = nullptr;
    int input, continuar = 1;

    do{
        cout<<"1)Agregar Nodo a Pila 2)Imprimir Pila 3)Eliminar Nodo 4)Salir"<<endl;
        cin>>continuar;
        if(continuar == 1){
            cout<<"Ingrese el valor del Nodo: "<<endl;
            cin>>input;
            Push(Pila, input);
            continuar == 1;
        }
        else if(continuar == 2){
            Imprimir(Pila);
            continuar = 1;
        }
        else if(continuar == 3){
            Pop(Pila, input);
            continuar = 1;
            cout<<"---------- PILA ACTUALIZADA ----------"<<endl;
            Imprimir(Pila);
        }
        else{
            continuar = 0;
        }
        
    }while(continuar == 1);

    cout<<"Condicion final de la Pila: "<<endl;
    Imprimir(Pila);

    return 0;
}
void Push(Nodo *&pila, int contenido){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = contenido;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}
void Imprimir(Nodo *&pila){
    Nodo *pilaTemp = pila;
    while(pilaTemp != nullptr){
        cout<<"Valor: "<<pilaTemp->elemento<<" - Dir.Valor: "<<pilaTemp<<" - Dir.Sig.Valor: "<<pilaTemp->siguiente<<endl;

        pilaTemp = pilaTemp->siguiente;
    }
}
void Pop(Nodo *&pila, int contenido){
    Nodo *pilaAux = pila;

    contenido = pilaAux->elemento;
    pila = pilaAux->siguiente;
    delete pilaAux;

    cout<<"---------- Valor: "<<contenido<<" Eliminado ----------"<<endl;
}