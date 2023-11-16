#define LibPoo_hpp
#include <iostream>
#include "Persona.cpp"
#include "Empresa.cpp"

using namespace std;

    Empresa(){}
    void AgregarPersona(Persona p, int g)
    {
        if (g == 1)
        {
            grupo1.push_back(p);
        }
        else if (g == 2)
        {
            grupo2.push_back(p);
        }
        else
        {
            cout << "No existe ese grupo" << endl;
        }
    }
    void ImprimirGrupos()
    {
        cout << "GRUPO 1:" << endl;
        for (int i = 0; i < grupo1.size(); i++)
        {
            cout << grupo1[i].toString() << endl;
        }
        cout << endl;
        cout << "GRUPO 2:" << endl;
        for (int i = 0; i < grupo1.size(); i++)
        {
            cout << grupo2[i].toString() << endl;
        }
    }
    void DineroTotalG1()
    {
        int suma = 0;

        for (int i = 0; i < grupo1.size(); i++)
        {
            suma = suma + grupo1[i].getDinero();
        }

        cout << "Dinero total del Grupo 1: " << suma << endl;
    }
    void DespertarPersona()
    {
        for (int i = 0; i < grupo1.size(); i++)
        {
            if (grupo1[i].getNombre == nombre)
            {
                if (grupo1[i].getDormir() == true)
                { //minuto alrededor 18:20 en video
                    System("cls");
                    int opcion;
                    cout << "Desea despertar a " << grupo1[i].getNombre() << "? // 1)SI 2)NO " << endl;
                    cin >> opcion;

                    if (opcion == 1)
                    {
                        grupo1[i].Despertar();
                    }
                    else
                    {
                        cout << "Que siga durmiendo... zzzz" << endl;
                    }
                }
                else
                {
                    System("cls");
                    int opcion;
                    cout << "Desea dormir a " << grupo1[i].getNombre() << "? // 1)SI 2)NO " << endl;
                    cin >> opcion;

                    if (opcion == 1)
                    {
                        grupo1[i].Dormir();
                    }
                    else
                    {
                        cout << "Que siga despierto..." << endl;
                    }
                }
            }
        }
        cout << endl;
        cout << "GRUPO 2:" << endl;
        for (int i = 0; i < grupo2.size(); i++)
        {
            if (grupo2[i].getNombre == nombre)
            {
                if (grupo2[i].getDormir() == true)
                { //minuto alrededor 18:20 en video
                    System("cls");
                    int opcion;
                    cout << "Desea despertar a " << grupo2[i].getNombre() << "? // 1)SI 2)NO " << endl;
                    cin >> opcion;

                    if (opcion == 1)
                    {
                        grupo2[i].Despertar();
                    }
                    else
                    {
                        cout << "Que siga durmiendo... zzzz" << endl;
                    }
                }
                else
                {
                    System("cls");
                    int opcion;
                    cout << "Desea dormir a " << grupo2[i].getNombre() << "? // 1)SI 2)NO " << endl;
                    cin >> opcion;

                    if (opcion == 1)
                    {
                        grupo2[i].Dormir();
                    }
                    else
                    {
                        cout << "Que siga despierto..." << endl;
                    }
                }
            }
        }
    }

    //PERSONA
    Persona(){}
Persona(string name, int age, int money, bool sleeping){
    nombre = name;
    edad = age;
    dinero = money;
    durmiendo = sleeping;
}
string getNombre(){
    return nombre;
}
int getDinero(){
    return dinero;
}
bool getDormir(){
    return durmiendo;
}
void toString(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Dinero: "<<dinero<<endl;
    if(durmiendo == true){
        cout<<"Durmiendo... zzzzzz "<<endl;
    }
    else if(durmiendo == false){
        cout<<"¡¡¡ No estoy durmiendo !!!!"<<endl;
    }
}
void Despertar(){
    durmiendo = false;
}
void Dormir(){
    durmiendo = true;
}