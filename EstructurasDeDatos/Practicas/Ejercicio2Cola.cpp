#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, Nodo *&, int);
bool Vacia(Nodo *&);
void Pop(Nodo *&, Nodo *&, int &);
void Imprimir(Nodo *&);

int main(){
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int input, continuar = 1, eleccion;

    do{
        cout<<"1)Agregar Nodo 2)Eliminar nodo 3)Imprimir"<<endl;
        cin>>eleccion;

        switch(eleccion){
            case 1:
            cout<<"Ingrese un valor para el Nodo: "<<endl;
            cin>>input;
            Push(frente, final, input);
            break;
            case 2:
            cout<<"Se eliminara el primer Nodo ingresado"<<endl;
            Pop(frente, final, input);
            break;
            case 3:
            cout<<"INFORMACION ALMACENADA: "<<endl;
            Imprimir(frente);
            break;
        }
        cout<<"1)MENU  0)SALIR"<<endl;
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
    nuevoNodo->elemento = dato;
    nuevoNodo->siguiente = nullptr;

    if(Vacia(frente)){
        frente = nuevoNodo;
    }
    else{
        final->siguiente = nuevoNodo;
    }
    final = nuevoNodo;

    cout<<"Se Agrego un Nodo con valor: "<<dato<<endl;
}

void Pop(Nodo *&frente, Nodo *&final, int &dato){

    Nodo *aux = frente;
    dato = aux->elemento;

    if(frente == final){
        frente = nullptr;
        final = nullptr;
    }
    else{
        frente = frente->siguiente;
    }
    delete aux;

    cout<<"Nodo con valor: "<<dato<<" Eliminado"<<endl;
}

void Imprimir(Nodo *&frente){
    int contador = 0;
    Nodo *printer = frente; 
    while(printer != nullptr){
        contador = contador + 1;
        cout<<"Valor: "<<printer->elemento<<" Posicion: "<<contador<<" DirValor: "<<printer<<" DirValorSig: "<<printer->siguiente<<endl;

        printer = printer->siguiente;
    }
}