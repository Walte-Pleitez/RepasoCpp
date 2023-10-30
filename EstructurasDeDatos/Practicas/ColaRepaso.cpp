#include <iostream>

using namespace std;

struct Nodo{
    int n;
    struct Nodo *siguiente;
};

bool Vacia(Nodo *&);
void Push(Nodo *&, Nodo *&, int &);
void Imprimir(Nodo *&);
void Pop(Nodo *&, Nodo *&);

int main(){
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int input, continuar = 1, eleccion;

    do{
        cout<<"1)Agregar Nodo 2)Imprimir Nodos 3)Eliminar Nodo"<<endl;
        cin>>eleccion;
        switch(eleccion){
            case 1:
            cout<<"Ingrese un valor para el Nodo: "<<endl;
            cin>>input;
            Push(frente, final, input);
            break;
            case 2:
            Imprimir(frente);
            break;
            case 3:
            Pop(frente, final);
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
void Push(Nodo *&frente, Nodo *&final, int &n){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->n = n;
    nuevoNodo->siguiente = nullptr;

    if(Vacia(frente)){
        frente = nuevoNodo;
    }
    else{
        final->siguiente = nuevoNodo;//cada nuevo nodo entra por el final
    }
    final = nuevoNodo;

    cout<<"Se agrego un Nodo con valor: "<<n<<endl;
}
void Imprimir(Nodo *&frente){
    Nodo *printer = frente;
    cout<<"********** CONTENIDO **********"<<endl;

    while(printer != nullptr){
        cout<<"Valor: "<<printer->n<<" Dir: "<<printer<<" DirValSig: "<<printer->siguiente<<endl;

        printer = printer->siguiente;
    }
}
void Pop(Nodo *&frente, Nodo *&final){
    int n;
    Nodo *aux = frente; //Se asigna todo el contenido a aux

    n = aux->n;

    if(frente == final){
        frente = nullptr;
        final = nullptr;
    }
    else{
        frente = frente->siguiente;
    }
    delete aux;

    cout<<"Se elimino un Nodo con valor: "<<n<<endl;
}