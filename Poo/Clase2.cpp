#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);
    string getNombre();
    int getEdad();
    void setNombre(string nombre);
    void setEdad(int edad);
};
Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}
string Persona::getNombre()
{
    return nombre;
}
int Persona::getEdad()
{
    return edad;
}
void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Persona::setEdad(int edad)
{
    this->edad = edad;
}

int main()
{
    string nombre;
    int edad;
    Persona p1 = Persona("Walter", 27);
    Persona p2 = Persona("Katya", 29);

    cout << "Nombre: " << p1.getNombre() << " - Edad: " << p1.getEdad() << endl;
    cout << "Nombre2: " << p2.getNombre() << " - Edad: " << p2.getEdad() << endl;

    cout << "Ingrese un nombre1 nuevo: " << endl;
    cin >> nombre;
    cout << "Ingrese una edad1 nuevo: " << endl;
    cin >> edad;

    p1.setNombre(nombre);
    p1.setEdad(edad);

    cout << "Nombre: " << p1.getNombre() << " - Edad: " << p1.getEdad() << endl;

    cout << "Ingrese un nombre2 nuevo: " << endl;
    cin >> nombre;
    cout << "Ingrese una edad2 nuevo: " << endl;
    cin >> edad;

    p2.setNombre(nombre);
    p2.setEdad(edad);

    cout << "Nombre2: " << p2.getNombre() << " - Edad2: " << p2.getEdad() << endl;

    return 0;
}