#include <iostream>

using namespace std;

class Perro{
    private:
    string nombre, raza;

    public:
    Perro(string, string); //Declaracion de Constructor
    ~Perro(); //Declaracion de Destructor
    void MostrarDatos();
    void Jugar();
};

Perro::Perro(string nombre, string raza){//Definicion del Constructor
    this->nombre = nombre;
    this->raza = raza;
}
Perro::~Perro(){} //Definicion del Destructor
void Perro::MostrarDatos(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Raza: "<<raza<<endl;
}
void Perro::Jugar(){
    cout<<"El perro "<<nombre<<", esta jugando."<<endl;
}

int main(){
    Perro perro1 = Perro("Rocky", "Lobo");

    perro1.MostrarDatos();
    perro1.Jugar();

    perro1.~Perro();

    return 0;
}