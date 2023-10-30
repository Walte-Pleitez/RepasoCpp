#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, int);
bool Vacia(Nodo *&);
void Imprimir(Nodo *&);
void Pop(Nodo *&);

int main(){
    Nodo *Pila = nullptr;
    int input, continuar = 1, eleccion;

    do{
        cout<<"1)Agregar Nodo  2)Imprimir Nodo  3)Eliminar Nodo"<<endl;
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

        cout<<"1)MENU 0)SALIR"<<endl;
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
void Push(Nodo *&pila, int n){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;

    cout<<"Se agrego un nuevo nodo con valor: "<<n<<endl;
}
void Imprimir(Nodo *&pila){
    Nodo *printer = pila;
    int contador = 0;

    cout<<"********** CONTENIDO DE LA PILA **********"<<endl;

    while(printer != nullptr){
        contador++;
        cout<<"Valor: "<<printer->elemento<<" Posicion: "<<contador<<" Dir: "<<printer<<" DirSig: "<<printer->siguiente<<endl;

        printer = printer->siguiente;
    }
}
void Pop(Nodo *&pila){
    int n;
    Nodo *aux = pila;

    n = aux->elemento;
    pila = aux->siguiente;
    delete aux;
    
    cout<<"Se elimino un Nodo con valor: "<<n<<endl;
}