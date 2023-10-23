#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    Nodo *siguiente;
};

void Push(Nodo *&, int);
void Imprimir(Nodo *);
void Pop(Nodo *&, int);

int main(){
    int dato, continuar=1, answer;
    Nodo *Pila = nullptr;

    do{
        cout<<"Ingrese un valor: "<<endl;
        cin>>dato;

        Push(Pila, dato);

        cout<<"1)AGREGAR VALOR 2)SALIR "<<endl;
        cin>>continuar;

        if(continuar==1){
            continuar=1;
        }
        else{
            continuar = 0;
        }
    }while(continuar == 1);

    Imprimir(Pila);

    cout<<"1) Eliminar una Nodo 0) Seguir normalmente"<<endl;
    cin>>answer;
    if(answer==1){
        Pop(Pila, dato);
        cout<<"--------- Pila actualizada ---------"<<endl;
        Imprimir(Pila);
    }
    else{
        cout<<"Pila terminada"<<endl;
    }

    return 0;
}

void Push(Nodo *&pila, int contenido){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = contenido;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;

    cout<<"---------- Nodo Agregado ----------"<<endl;
}
void Imprimir(Nodo *pila){
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
}