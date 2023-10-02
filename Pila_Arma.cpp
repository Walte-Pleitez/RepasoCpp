#include <iostream>

using namespace std;

struct Nodo
{
    int Cartucho;
    struct Nodo *siguiente;
};

void Push(int);
//void Imprimir();

struct Nodo *Recamara = nullptr; //Creación de cartucho principal

int main()
{
    int Municion; //Representa el numero de lista de la bala dentro de la Recamara

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese la bala: " << endl;
        cin >> Municion;

        Push(Municion); //Ingreso de la Bala
    }

    return 0;
}

void Push(int Bala)
{
    struct Nodo *Cartuchos = new Nodo(); //creación del cartucho que se apilara en la recamara

    Cartuchos->Cartucho = Bala;      //Ingresar Bala en Cartucho que se apilara
    Cartuchos->siguiente = Recamara; //Cartucho que se apilara se conecta con la Recamara para ser parte de la Pila de Cartuchos en la Recamara
    Recamara = Cartuchos;            //Recamara pone el gatillo en el ultimo cartucho
}
/*
void Imprimir(){
    struct Nodo *RecamaraTemporal = Recamara; //La RecamaraTemporal se conecta con la Original para tener el mismo control de cartuchos
}
*/