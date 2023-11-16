#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    string nombre;
    string apellido;
    int edad;
    float estatura;

public:
    Persona();
    string getNombre();
    int getEdad();
    float getEstatura();
    void setEdad(int edad);
    void setEstatura(float estatura);
};
//CONSTRUCTOR
Persona::Persona()
{
}
//METODOS DE CLASE
string Persona::getNombre()
{
    return nombre;
}
int Persona::getEdad()
{
    return edad;
}
float Persona::getEstatura()
{
    return estatura;
}
void Persona::setEdad(int edad)
{
    this->edad = edad;
}
void Persona::setEstatura(float estatura)
{
    this->estatura = estatura;
}
//METODOS DEL EJERCICIO

int main()
{
    Persona p1 = Persona();

    p1.setEdad(27);
    p1.setEstatura(1.69);
    cout<<p1.getEdad()<<endl;
    cout<<p1.getEstatura();


    return 0;
}