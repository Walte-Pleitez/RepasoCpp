#include <iostream>

using namespace std;

struct Nodo
{
    int Cartucho;
    struct Nodo *siguiente;
};

void Push(int);
void Imprimir();

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
    Imprimir();

    return 0;
}

void Push(int Bala)
{
    struct Nodo *Cartuchos = new Nodo(); //creación del cartucho que se apilara en la recamara

    Cartuchos->Cartucho = Bala;      //Ingresar Bala en Cartucho que se apilara
    Cartuchos->siguiente = Recamara; //Cartucho que se apilara se conecta con la Recamara para ser parte de la Pila de Cartuchos en la Recamara
    Recamara = Cartuchos;            //Recamara pone el gatillo en el ultimo cartucho
}

void Imprimir(){//Servira para ver cuantas balas hay en la recamara

    struct Nodo *RecamaraTemporal = Recamara; //La RecamaraTemporal se conecta con la Original para tener el mismo control de cartuchos

    while(RecamaraTemporal != nullptr){ //Si la recamara no esta vacia entonces ejecutara el codigo
        cout<<"# Cartucho de la recamara: "<<RecamaraTemporal->Cartucho<<endl;//Imprime el numero de lista del cartucho
        cout<<" - Dir.Memoria cartucho a disparar: "<<RecamaraTemporal<<endl;//Imprime la Dir. Memoria del cartucho
        cout<<" - Dir.Memoria Cartucho siguiente para disparar: "<<RecamaraTemporal->siguiente<<endl; //Imprime Dir. Memoria de siguiente cartucho

        //El numero del siguiente cartucho es menor cada vez, por eso llegara hasta null para que no haya bucle infinito
        RecamaraTemporal = RecamaraTemporal ->siguiente;
    }
}

        