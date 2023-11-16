#include <iostream>

using namespace std;

struct Nodo
{
    int posicion;
    struct Nodo *siguiente;
};

void PushLista(Nodo *&, int);
void MostrarLista(Nodo *&);
void BuscarLista(Nodo *&, int);
void PopLista(Nodo *&, int);

int main()
{
    Nodo *Lista = nullptr;
    int Posicion, continuar = 1, eleccion, valorBuscado;

    do
    {
        cout << "1)Agregar a Lista  2)Mostrar Lista 3)Buscar en Lista 4)Eliminar en Lista" << endl;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:
            cout << "Ingrese la posicion en la lista: " << endl;
            cin >> Posicion;
            PushLista(Lista, Posicion);
            break;
        case 2:
            MostrarLista(Lista);
            break;
        case 3:
            cout << "Ingrese el valor a buscar: " << endl;
            cin >> valorBuscado;
            BuscarLista(Lista, valorBuscado);
            break;
        case 4:
            cout << "Ingrese el elemento a borrar: " << endl;
            cin >> valorBuscado;
            PopLista(Lista, valorBuscado);
            break;
        }

        cout << "1)seguir  0)Salir" << endl;
        cin >> continuar;
    } while (continuar == 1);

    return 0;
}
void PushLista(Nodo *&lista, int input)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->posicion = input;

    Nodo *aux1 = lista;
    Nodo *aux2;
    //Si la Lista ya tiene datos y la posicion input es mayor que la ultima ya existente, se cumple el while
    //Mientras mas grande sea el numero mas al final quedara y mas abajo en la lista.
    while ((aux1 != nullptr) && (aux1->posicion < input))
    {
        aux2 = aux1;            //aux2 va guardando cada nuevo elemento que recorre aux1
        aux1 = aux1->siguiente; //aux1 recorre la lista y guarda cada elemento de ella
    }

    if (lista == aux1)
    { //Para saber si va al principio y porque no cumplio la condicion del while
        lista = nuevoNodo;
    }
    else
    { //Si entro al while vendra hacia aqui
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;

    cout << "Elemento: " << input << " Insertado en la lista" << endl;
}
void MostrarLista(Nodo *&lista)
{
    Nodo *printer = lista;

    while (printer != nullptr)
    {
        cout << "Posicion en Lista: " << printer->posicion << endl;

        printer = printer->siguiente;
    }
}
void BuscarLista(Nodo *&lista, int valor)
{
    Nodo *Buscador = lista;
    bool bandera = false;
    //Recorre mientras no este vacia y la posicion sea menor a la que se busca
    while ((Buscador != nullptr) && (Buscador->posicion <= valor))
    {
        if (Buscador->posicion == valor)
        { //si existe envia true (cuando llega a la posicion buscada)
            bandera = true;
        }
        Buscador = Buscador->siguiente; //si no existe se mantiene recorriendo la Lista.
    }
    if (bandera == true)
    {
        cout << "El elemento " << valor << " ha sido encontrado en la Lista" << endl;
    }
    else
    {
        cout << "No se encontro el elemento" << valor << " en la Lista" << endl;
    }
}
void PopLista(Nodo *&lista, int valor)
{
    if (lista != nullptr)
    {
        Nodo *auxBorrar;
        Nodo *anterior = nullptr;
        auxBorrar = lista;

        while ((auxBorrar != nullptr) && (auxBorrar->posicion != valor))
        {
            anterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        }
        if (auxBorrar == nullptr)
        {
            cout << "El elemento no existe en la lista" << endl;
        }
        else if (anterior == nullptr)
        { //si el buscado para eliminar es el primero de la lista
            lista = lista->siguiente;
            delete auxBorrar;
            cout << "Se borro el primer elemento: " << valor << ", de la lista" << endl;
        }
        else
        { //si el buscado se encuentra en la lista pero no es el primero
            anterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
            cout << "Se borro el elemento " << valor << " de la lista" << endl;
        }
    }
}