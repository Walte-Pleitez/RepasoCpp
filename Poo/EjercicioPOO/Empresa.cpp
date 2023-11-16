#include <iostream>
#include <vector>

using namespace std;

class Empresa
{
private:
    vector<Persona> grupo1;
    vector<Persona> grupo2;

public:
Empresa();
void AgregarPersona(Persona p, int g);
void ImprimirGrupos();
void DineroTotalG1();
void DespertarPersona();
};