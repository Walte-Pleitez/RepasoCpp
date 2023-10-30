#include <iostream>

using namespace std;

struct Nodo
{
    int posicionCola;
    struct Nodo *siguiente;
};
struct Pincho
{
    string Fruta = "";
    struct Pincho *siguiente;
};
//FUNCIONES COLA
bool Vacia(Nodo *&);
void PushCola(Nodo *&, Nodo *&, int);
void PopCola(Nodo *&, Nodo *&);
void ImprimirCola(Nodo *&);
//FUNCIONES PILA
void PushFruta(Pincho *&, string);
void Imprimir(Pincho *&);
void PopPila(Pincho *&);

int main()
{
    //Variables para Cola
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int posicion, continuar = 1, eleccion;
    //Variables para Pila
    Pincho *pila = nullptr;
    string nombreFruta;
    int continuar2 = 1;
    int eleccion2;

    do
    {
        cout << "1)Agregar Cliente 2)Despachar Cliente 3)Ver Cola" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            cout << "Agregue posicion para el nuevo cliente" << endl;
            cin >> posicion;
            PushCola(frente, final, posicion);
            break;
        case 2:

            do
            {
                cout << "1)LLENAR PINCHO 2)MODIFICAR FRUTA TOP" << endl;
                cin >> eleccion2;
                switch (eleccion2)
                {
                case 1:
                    for (int i = 1; i < 7; i++)
                    {
                        cout << "Agregue nombre de fruta que desea: " << endl;
                        cin >> nombreFruta;
                        PushFruta(pila, nombreFruta);
                    }
                    Imprimir(pila);
                    PopCola(frente, final);
                    break;
                case 2:
                    string frutaTop = "";
                    PopPila(pila);
                    cout << "Ingrese nombre de la nueva fruta Top: " << endl;
                    cin >> frutaTop;
                    PushFruta(pila, frutaTop);
                    cout << "ACTUALIZACION DEL PINCHO LLENO" << endl;
                    Imprimir(pila);
                    break;
                }

                cout << "0)SIGUIENTE CLIENTE  1)ALGO MAS" << endl;
                cin >> continuar2;
            } while (continuar2 == 1);

            for (int i = 1; i < 7; i++)
            {
                PopPila(pila);
            }
            break;

        case 3:
            ImprimirCola(frente);
            break;
        }
        cout << "1)ADMIN CLIENTES  0)SALIR" << endl;
        cin >> continuar;
    } while (continuar == 1);

    return 0;
}
//FUNCIONES COLA
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
void PushCola(Nodo *&frente, Nodo *&final, int posicion)
{
    Nodo *nuevoCliente = new Nodo();

    nuevoCliente->posicionCola = posicion;
    nuevoCliente->siguiente = nullptr;

    if (Vacia(frente))
    {
        frente = nuevoCliente;
    }
    else
    {
        final->siguiente = nuevoCliente;
    }
    final = nuevoCliente;
    cout << "SE AGREGO UN NUEVO CLIENTE A LA COLA" << endl;
    cout << endl;
}
void PopCola(Nodo *&frente, Nodo *&final)
{
    Nodo *clienteDespachado = frente;

    if (frente == final)
    {
        frente = nullptr;
        final = nullptr;
    }
    else
    {
        frente = frente->siguiente;
    }
    delete clienteDespachado;
    cout << "CLIENTE DESPACHADO" << endl;
    cout << endl;
}
void ImprimirCola(Nodo *&frente)
{
    Nodo *printer = frente;

    while (printer != nullptr)
    {
        cout << "POSICIONES DE CLIENTES EN ESPERA: " << printer->posicionCola << endl;

        printer = printer->siguiente;
    }
}
//FUNCIONES PILA
void PushFruta(Pincho *&pila, string fruta)
{
    Pincho *nuevaFruta = new Pincho();

    nuevaFruta->Fruta = fruta;
    nuevaFruta->siguiente = pila;
    pila = nuevaFruta;

    cout << "Fruta agregada" << endl;

    cout << endl;
}
void Imprimir(Pincho *&pila)
{
    Pincho *print = pila;

    while (print != nullptr)
    {
        cout << "MUESTRA ORDEN DE FRUTAS EN PINCHO: " << print->Fruta << endl;
        print = print->siguiente;
    }
}
void PopPila(Pincho *&pila)
{
    Pincho *pinchoLleno = pila;

    pila = pinchoLleno->siguiente;
    delete pinchoLleno;
}