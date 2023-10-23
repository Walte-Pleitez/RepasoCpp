#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, Nodo *&, int);
bool Vacia(Nodo *&frente);
void Pop(Nodo *&, Nodo *&, int &);

int main(){
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int continuar = 1, eleccion, input;

    do{
        cout<<"1)Agregar Nodo 2)Eliminar Nodo 3)Imprimir Nodo"<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
            cout<<"Ingrese el valor del Nodo: "<<endl;
            cin>>input;
            Push(frente, final, input);
            continuar = 1;
            break;
            case 2:
            Pop(frente, final, input);
            continuar = 1;
            break;
        }

        cout<<"1)MENU 0)SALIR"<<endl;
        cin>>continuar;

    }while(continuar == 1);

    return 0;
}

bool Vacia(Nodo *&frente){
    if(frente == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Push(Nodo *&frente, Nodo *&final, int dato){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = dato,
    nuevoNodo->siguiente = nullptr;

    if(Vacia(frente)){
        frente = nuevoNodo;
    }
    else{
        final->siguiente = nuevoNodo;
    }

    final = nuevoNodo;

    cout<<"Se agrego un Nodo a la Cola con valor: "<<dato<<endl;
    cout<<endl;
}

void Pop(Nodo *&frente, Nodo *&final, int &dato){
    dato = frente->elemento;
    Nodo *aux = frente;

    if(frente == final){
        frente = nullptr;
        final = nullptr;
    }
    else{
        frente = frente->siguiente;
    }
    delete aux;

    cout<<"Nodo eliminado con valor: "<<dato<<endl;
}

