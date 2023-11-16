#include <iostream>
#include <vector>
#include "LibPoo.hpp"
//#include "Empresa.cpp"
//#include "Persona.cpp"

using namespace std;
//ARREGLAR BUCLE

int main()
{
    Empresa e = Empresa();
    Persona p1 = Persona("Walter", 15,1000,true);
    Persona p2 = Persona("Oswaldo", 19,1500,true);
    Persona p3 = Persona("Pleitez", 22,2000,true);
    Persona p4 = Persona("Torres", 25,2300,true);
    Persona p5 = Persona("Osvaldo", 27,3000,true);
    Persona p6 = Persona("Adiel", 39,30100,true);

    e.AgregarPersona(p1,1);
    e.AgregarPersona(p2,1);
    e.AgregarPersona(p3,1);
    e.AgregarPersona(p4,2);
    e.AgregarPersona(p5,2);
    e.AgregarPersona(p6,2);

    e.ImprimirGrupos();

    return 0;
}