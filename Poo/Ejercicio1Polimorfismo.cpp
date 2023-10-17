#include <iostream>
//CREAR JERARQUIA ANIMAL PADRE DE HUMANO Y PERRO, Y SU POLIMORFISMO CON EL METODO COMER();
using namespace std;

//CREACION DE CLASES
class Animal{
    private:
    string nombre;
    int edad;

    public:
    Animal(string, int);
    virtual void comer();
};
class Persona : public Animal{
    private:
    string nombre;
    int edad;
    string telefono;

    public:
    Persona(string, int, string);
    void comer();
};
class Perro : Animal{
    private:
    string nombre;
    int edad;
    string raza;

    public:
    Perro(string, int,string);
    void comer();
};
//CREACION DE METODOS CONSTRUCTORES
Animal::Animal(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}
Persona::Persona(string nombre, int edad, string telefono) : Animal(nombre, edad){
    this->telefono = telefono;
}
Perro::Perro(string nombre, int edad, string raza) : Animal(nombre, edad){
    this->raza = raza;
}

//CREACION DE METODOS MIEMBROS
void Animal::comer(){
    cout<<"Comiendo..."<<endl;
}
void Persona::comer(){
    Animal::comer();
    cout<<"Persona comiendo"<<endl;
}
void Perro::comer(){
    Animal::comer();
    cout<<"Perro comiendo"<<endl;
}


int main(){
    Animal animal1 = Animal("Pegaso", 10000);
    Persona person1 = Persona("Walter", 27, "6920-5969");
    Perro dog1 = Perro("Rocky", 5, "Lobo");

    animal1.comer();
    cout<<endl;
    person1.comer();
    cout<<endl;
    dog1.comer();

    return 0;
}