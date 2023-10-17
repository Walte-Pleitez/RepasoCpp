#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:                   //Declaracionde metodos
    Persona(string, int); //Constructor Padre
    void MostrarPersona();
};
Persona::Persona(string nombre, int edad)//Definicion Constructor Padre
{
    this->nombre = nombre;
    this->edad = edad;
}
void Persona::MostrarPersona(){//Definicion de funcion Mostrar
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
}
class Alumno : public Persona{
    private:
    string IdAlumno;
    float cum;

    public:
    Alumno(string, int, string, float);//Declaracion de Constructor Hijo Alumno
    void MostrarAlumno();
};
//Definicion de Constructor Hijo
Alumno::Alumno(string nombre, int edad, string Id, float cum) : Persona(nombre, edad){
    this->IdAlumno = Id;
    this->cum = cum;
}
void Alumno::MostrarAlumno(){
    MostrarPersona();
    cout<<"Id alumno: "<< IdAlumno<<endl;
    cout<<"CUM: "<<cum<<endl;
}

int main()
{
    Alumno Estudiante = Alumno("Walter", 27, "00143023", 9.0);

    Estudiante.MostrarAlumno();

    return 0;
}