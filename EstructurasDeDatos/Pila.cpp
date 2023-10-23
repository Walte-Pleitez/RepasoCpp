#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

//DECLARACION DE FUNCIONES
void Push(Nodo *&, int);
void Pop(Nodo *&, int &);

int main()
{
    struct Nodo *Pila = nullptr;
    int dato;

    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese un numero: " << endl;
        cin >> dato;

        Push(Pila, dato);
    }
    Pop(Pila, dato);

    return 0;
}
//DEFINICION DE FUNCIONES
//INSERTAR: Reservar memoria, Llenar dato, Llenar puntero, Asignar NuevoNodo a Pila
void Push(Nodo *&pila, int contenido)
{
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = contenido;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo; //La Pila siempre debe apuntar a la cima
    cout << "Se agrego un nuevo nodo a la Pila" << endl;
}
//ELIMINAR: Crear var auxiliar,
void Pop(Nodo *&pila, int &contenido){
    Nodo *aux = pila;

    contenido = aux->elemento;
    pila = aux->siguiente;
    delete aux;

    cout<<"Se elimino el nodo con valor: "<<contenido<<endl;
}