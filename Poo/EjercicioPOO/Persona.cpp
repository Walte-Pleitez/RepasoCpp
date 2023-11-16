#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
    int dinero;
    bool durmiendo;

public:
Persona(string name, int age, int money, bool sleeping);
string getNombre();
int getDinero();
bool getDormir();
void toString();
void Despertar();
void Dormir();
};