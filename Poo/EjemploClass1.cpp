#include <iostream>

using namespace std;

class Persona{
    private: //Atributos
    string nombre;
    int edad;

    public: //Metodos
    Persona(string nombre, int edad); //CONSTRUCTOR: Inicializa las caracteristicas del objeto
    void Leer();
    void Correr();
};
//Inicializacion del Constructor (inicializa los atributos de la clase)
Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}
void Persona::Leer(){
    cout<<"Mi nombre es: "<<nombre<<", Mi edad es: "<<edad<<", Y estoy leyendo."<<endl;
}
void Persona::Correr(){
    cout<<"Nombre: "<<nombre<<", edad: "<<edad<<", y estoy corriendo."<<endl;
}

int main(){
    Persona P1 = Persona("Walter", 27);
    Persona P2("Katya", 29);

    P1.Leer();
    P2.Correr();

    return 0;
}