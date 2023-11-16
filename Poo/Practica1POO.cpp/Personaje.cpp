#include <iostream>
//#include "PersonajeMain.cpp"

using namespace std;

class Personaje
{
private:
    int vida;
    int damage;
    string clase;

public:
    Personaje(int vida, int damage, string clase)
    {
        this->vida = vida;
        this->damage = damage;
        this->clase = clase;
    }
    int getVida()
    {
        return this->vida;
    }
    int getDamage()
    {
        return this->damage;
    }
    string getClase()
    {
        return this->clase;
    }
    void setVida(int vidaNueva)
    {
        this->vida = vidaNueva;
    }
    void setDamage(int damageNuevo)
    {
        this->damage = damageNuevo;
    }
    void setClase(string nuevaClase)
    {
        this->clase = nuevaClase;
    }
    void MostrarInfo()
    {
        cout << endl;
        cout << "Clase: " << this->clase << endl;
        cout << "Danio: " << this->damage << endl;
        cout << "Vida: " << this->vida << endl;
        cout << endl;
    }
    void Curar(int curar)
    {
        this->vida = this->vida + curar;
    }
    void Damage(Personaje p)
    {
        this->vida = this->vida - p.getDamage();
    }
};