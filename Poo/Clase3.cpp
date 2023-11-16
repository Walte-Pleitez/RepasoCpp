#include <iostream>

using namespace std;

class Persona{
    private:
    string nombre;
    int edad;

    public:
    Persona(string, int);
    string getNombre();
    int getEdad();
    void setNombre(string);
    void setEdad(int);
};
Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}
string Persona::getNombre(){
    return nombre;
}
int Persona::getEdad(){
    return edad;
}
void Persona::setNombre(string nombre){
    this->nombre = nombre;
}
void Persona::setEdad(int edad){
    this->edad = edad;
}

int main(){
    string nombre;
    int edad;
    Persona p1 = Persona("Walter", 27);
    Persona p2 = Persona("Katya", 29);

    cout<<"Nombre: "<<p1.getNombre()<<" Edad: "<<p1.getEdad()<<endl;
    cout<<"Nombre: "<<p2.getNombre()<<" Edad: "<<p2.getEdad()<<endl;

    cout<<"Ingrese un nombre nuevo: "<<endl;
    cin>>nombre;
    cout<<"Ingrese una nueva edad: "<<endl;
    cin>>edad;

    p1.setEdad(edad);
    p1.setNombre(nombre);

    cout<<"Nombre: "<<p1.getNombre()<<" Edad: "<<p1.getEdad()<<endl;
    cout<<"Nombre: "<<p2.getNombre()<<" Edad: "<<p2.getEdad()<<endl;

    return 0;
}