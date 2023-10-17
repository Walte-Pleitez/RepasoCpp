#include <iostream>
//Crear una clase llamada Persona y generar de ella la clase empleado y estudiante.
//De la clase estudiantes generar la clase universitario (Mediante Herencia).
using namespace std;

//DEFINICION DE CLASES
class Persona{
    private:
    string nombre;
    int edad;

    public:
    Persona(string, int);//Declaracion de Constructor Padre
    void MostrarDatos();
};
class Estudiante : public Persona{
    private:
    string nombre;
    int edad;
    string nie;

    public:
    Estudiante(string, int, string);//Declaracion de Constructor Hijo Estudiante
    void MostrarDatosAlumno();
};
class Empleado : public Persona{
    private:
    string nombre;
    int edad;
    float salario;

    public:
    Empleado(string, int, float);//Declaracion de Constructor Hijo Empleado
    void MostrarDatosEmpleado();
};
class Universitario : public Estudiante{
    private:
    string nombre;
    int edad;
    string nie;
    float cum; 

    public:
    Universitario(string, int, string, float);
    void MostrarDatosUniversitario();
};

//DEFINICION DE CONSTRUCTORES
Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}// Fin Constructor Padre
Estudiante::Estudiante(string nombre, int edad, string nie) : Persona(nombre, edad) {
    this->nie = nie;
}//Fin Constructor Hijo Estudiante
Empleado::Empleado(string nombre, int edad, float salario) : Persona(nombre, edad){
    this->salario = salario;
}//Fin Constructor Hijo Empleado
Universitario::Universitario(string nombre, int edad, string nie, float cum) : Estudiante(nombre, edad, nie){
    this->cum = cum;
}

//DEFINICION DE METODOS MIEMBROS
void Persona::MostrarDatos(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
}
void Estudiante::MostrarDatosAlumno(){
    MostrarDatos();
    cout<<"NIE: "<<nie<<endl;
}
void Empleado::MostrarDatosEmpleado(){
    MostrarDatos();
    cout<<"Salario: "<<salario<<endl;
}
void Universitario::MostrarDatosUniversitario(){
    MostrarDatosAlumno();
    cout<<"CUM: "<<cum<<endl;
}

int main(){
    Persona person1 = Persona("Duvan", 25);
    Empleado employee = Empleado("Marlene", 29, 900.00);
    Estudiante student = Estudiante("Walter", 27, "00143023");
    Universitario freshman = Universitario("Oswaldo", 27, "00143023", 9.0);

    cout<<"DATOS DE PERSONA"<<endl;
    person1.MostrarDatos();
    cout<<endl;
    cout<<"DATOS DE EMPLEADO"<<endl;
    employee.MostrarDatosEmpleado();
    cout<<endl;
    cout<<"DATOS DE ESTUDIANTE"<<endl;
    student.MostrarDatosAlumno();
    cout<<endl;
    cout<<"DATOS DE UNIVERSITARIO"<<endl;
    freshman.MostrarDatosUniversitario();

    return 0;
}