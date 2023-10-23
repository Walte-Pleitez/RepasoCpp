#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, int);
void Pop(Nodo *&, int);
void Imprimir(Nodo *&);

int main(){
    Nodo *Pila = nullptr;
    int input, continuar = 1;

    do{

        cout<<"1)Agregar Nodo  2)Imprimir  3)Eliminar  0)Salir"<<endl;
        cin>>continuar;
        if(continuar == 1){
            cout<<"Ingrese un valor para un Nodo: "<<endl;
            cin>>input;
            Push(Pila, input);
            continuar = 1;
        }
        else if(continuar == 2){
            cout<<"IMPRESION DE PILA"<<endl;
            Imprimir(Pila);
            continuar = 1;
        }
        else if(continuar == 3){
            Pop(Pila, input);
            continuar = 1;
        }
        else{
            continuar = 0;
        }

    }while(continuar == 1);

    return 0;
}

void Push(Nodo *&pila, int contenido){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = contenido;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;

    cout<<"Nodo agregado - Contenido: "<<contenido<<endl;
}
void Imprimir(Nodo *&pila){
    Nodo *pilaDisplay = pila;

    while(pilaDisplay != nullptr){
        cout<<"Valor: "<<pilaDisplay->elemento<<" - Dir.Valor: "<<pilaDisplay<<" - DirValorSig: "<<pilaDisplay->siguiente<<endl;

        pilaDisplay = pilaDisplay->siguiente;
    }
}

void Pop(Nodo *&pila, int contenido){
    Nodo *pilaAux = pila;

    contenido = pilaAux->elemento;
    pila = pilaAux->siguiente;
    delete pilaAux;

    cout<<"Nodo Eliminado - Valor sacado de Pila: "<<contenido<<endl;
}