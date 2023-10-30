#include <iostream>
// 5:23 a 6:07
using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};
bool Vacia(Nodo *&);
void Push(Nodo *&, Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&, Nodo *&);

int main()
{
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int input, continuar = 1, eleccion;

    do
    {
        cout << "1)Agregar Nodo 2)Imprimir Nodo 3)Eliminar Nodo" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
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
        default:
        cout<<"Ingrese una opcion disponible: "<<endl;
        }

        cout << "1)MENU  0)SALIR" << endl;
        cin >> continuar;
    } while (continuar == 1);

    return 0;
}
bool Vacia(Nodo *&frente)
{
    if (frente == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Push(Nodo *&frente, Nodo *&final, int dato)
{
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = dato;
    nuevoNodo->siguiente = nullptr;

    if (Vacia(frente))
    {
        frente = nuevoNodo;
    }
    else
    {
        final->siguiente = nuevoNodo;
    }
    final = nuevoNodo;
}
void Imprimir(Nodo *&frente){
    Nodo *printer = frente;
    int contador = 0;

    while(printer != nullptr){
        contador++;
        cout<<"Valor: "<<printer->elemento<<" Posicion: "<<contador<<" DirValor: "<<printer<<" DirValorSig: "<<printer->siguiente<<endl;
     printer = printer->siguiente;
    }
    
}

void Pop(Nodo *&frente, Nodo *&final){
    int dato;
    Nodo *aux = frente;

    dato = aux->elemento;
    frente = aux->siguiente;
    if(frente == final){
        frente = nullptr;
        final = nullptr;
    }
    else{
        final = aux->siguiente;
    }
    delete aux;

    cout<<"Se Elimino un Nodo con valor: "<<dato<<endl;
}