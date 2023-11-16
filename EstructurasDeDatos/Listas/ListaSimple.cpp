#include <iostream>
//La Lista es lo mismo que la Pila en que ambas son LIFO
using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

void PushInicio(Nodo *&lista, int dato);
void Imprimir(Nodo *&);

int main()
{
    Nodo *Lista = nullptr;
    int input, continuar = 1, eleccion;

    do
    {
        cout << "1)Agregar Nodo 2)Imprimir Nodo 3) EliminarNodo" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            cout << "Ingrese un valor para el Nodo: " << endl;
            cin >> input;
            PushInicio(Lista, input);
            break;
        case 2:
            Imprimir(Lista);
            break;
        case 3:
            //
            break;
        }

    } while (continuar == 1);

    return 0;
}

void PushInicio(Nodo *&lista, int dato)
{
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->elemento = dato;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {//Si está vacia solo la lista engancha a nuevoNodo
        lista = nuevoNodo;
    }
    else
    {//Si no esta vacía también nuevoNodo engancha a lista  con su puntero interno
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}

void Imprimir(Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}