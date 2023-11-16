#include <iostream>
#include "Personaje.cpp"

using namespace std;

int main()
{
    Personaje p1 = Personaje(100, 30, "Mago");
    Personaje p2 = Personaje(100, 50, "Guerrero");
    Personaje p3 = Personaje(100, 40, "Soporte");

    p1.Curar(p3.getDamage());
    p2.Damage(p1);

    cout << "IMPRIMIENDO CONDICION DE PARTICIPANTES" << endl;
    p1.MostrarInfo();
    p2.MostrarInfo();
    p3.MostrarInfo();

    return 0;
}