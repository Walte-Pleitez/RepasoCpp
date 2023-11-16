#include <iostream>

using namespace std;

struct Nodo
{
    int n;
    struct Nodo *siguiente;
};

void InsertarInicio(Nodo *&, int);
void InsertarFinal(Nodo *&, int);
void InsertarMedio(Nodo *&, int, int);
void EliminarInicio(Nodo *&);
void EliminarFinal(Nodo *&);
void Imprimir(Nodo *&);

int main()
{
    Nodo *Lista = nullptr;
    int input, continuar = 1, continuar2 = 1, eleccion1, eleccion2, posicionMedia;

    do
    {
        cout << "--------------- 1)Insertar 2)Eliminar 3)Imprimir ---------------" << endl;
        cin >> eleccion1;
        switch (eleccion1)
        {
        case 1:
            //INSERTAR
            cout << "********** MENU INSERTAR **********" << endl;
            do
            {
                cout << "1)Inicio 2)Medio 3)Final" << endl;
                cin >> eleccion2;
                switch (eleccion2)
                {
                case 1:
                    cout << "Ingrese valor para el Nodo al Inicio: " << endl;
                    cin >> input;
                    InsertarInicio(Lista, input);
                    break;
                case 2:
                    cout << "Ingrese posicion al medio: " << endl;
                    cin >> posicionMedia;
                    cout << "Ingrese valor para el Nodo al Medio: " << endl;
                    cin >> input;
                    InsertarMedio(Lista, posicionMedia, input);
                    break;
                case 3:
                    cout<<"Ingrese valor para el Nodo del final: "<<endl;
                    cin>>input;
                    InsertarFinal(Lista, input);
                    break;
                }

                cout << "1)MENU INSERTAR  0)SALIR" << endl;
                cin >> continuar2;
            } while (continuar2 == 1);
            break;
        case 2:
            //ELIMINAR
            cout << "********** MENU ELIMINAR **********" << endl;
            do
            {
                cout << "1)Inicio 2)Medio 3)Final" << endl;
                cin >> eleccion2;

                switch (eleccion2)
                {
                case 1:
                    EliminarInicio(Lista);
                    break;
                case 2:
                    EliminarFinal(Lista);
                    break;
                }

                cout << "1)MENU ELIMINAR  0)SALIR" << endl;
                cin >> continuar2;
            } while (continuar2 == 1);
            break;
        case 3:
            //IMPRIMIR
            Imprimir(Lista);
            break;
        }
        cout << "1)MENU  0)SALIR" << endl;
        cin >> continuar;
    } while (continuar == 1);

    return 0;
}
void InsertarInicio(Nodo *&lista, int input)
{
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->n = input;
    nuevoNodo->siguiente = nullptr;

    if (lista != nullptr)
    {
        nuevoNodo->siguiente = lista;
    }
    lista = nuevoNodo;

    cout << "Se agrego un Nodo al Inicio" << endl;
    cout << endl;
}
void InsertarFinal(Nodo *&lista, int input)
{
    Nodo *nuevoNodo = new Nodo();
    Nodo *temporal = lista;

    nuevoNodo->n = input;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (lista != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}
void InsertarMedio(Nodo *&lista, int input, int posicion)
{
    Nodo *nuevoNodo = new Nodo();
    Nodo *temporal = lista;

    nuevoNodo->n = input;
    nuevoNodo->siguiente = nullptr;

    posicion--;

    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}
void EliminarInicio(Nodo *&lista)
{
    Nodo *temporal = lista;

    if (temporal != nullptr)
    {
        lista = temporal->siguiente;

        delete temporal;
        cout<<"Se elimino el primer Nodo de la Lista"<<endl;
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}
void EliminarFinal(Nodo *&lista)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        // Si el nodo no es el ultimo
        if (temporal->siguiente != nullptr)
        {
            // Se realiza la iteraciones hasta encontra el ultimo nodo que apunte a nullptr
            while (temporal->siguiente != nullptr)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacena el penultimo nodo sera quien apunte nullptr
            temporal2->siguiente = nullptr;
            // Se libera la memoria del nodo ultimo
            delete temporal;
            temporal = nullptr;
        }
        else // Si unicamente se encontraba un nodo en la lista
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

void Imprimir(Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->n << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia"<<endl;
    }
}