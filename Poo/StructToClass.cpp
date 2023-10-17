#include <iostream>

using namespace std;

struct Reloj
{
    int horas, minutos;

    void Lee();
    void Escribe() const;//Para indicar que esta funcion miembro no odifica al objeto que la llama usamos const
    void Avanza(int min);
};

int main()
{
    int n;
    struct Reloj Clock;
    
    cout << "Hora en Reloj" << endl;
    Clock.Lee();
    cout << "Cuanto Minutos sumamos?" << endl;
    cin >> n;

    Clock.Avanza(n);
    Clock.Escribe();

    return 0;
}

void Reloj::Lee()
{
    char c;
    cin >> horas >> c >> minutos;
}
void Reloj::Escribe() const
{
    if (horas < 10)
    {
        cout << 0;
    }

    cout << horas << ":";

    if (minutos < 10)
    {
        cout << 0;
    }

    cout << minutos;
}
void Reloj::Avanza(int min)
{
    if (min < 0)
    {
        return;
    }

    minutos += min;

    if (minutos > 60)
    {
        horas += minutos / 60;
        minutos = minutos % 60;
        horas = horas % 24;
    }
}