#include <iostream>

using namespace std;
//Los metodos y constructor se declaran dentro pero se definen afuera de la clase
class Fecha
{
private:
    int dia, mes, year; //Atributos

public:                   //Metodos
    Fecha(int, int, int); //Declaracion de Constructor1  Dia/Mes/Year
    Fecha(long);//Declaracion de Constructor2 DiaMesYear

    void MostrarFecha();
};//Fin Clase Fecha

Fecha::Fecha(int dia, int mes, int year) 
{ //Definicion de Constructor1
this->dia = dia;
this->mes = mes;
this->year = year;
}
Fecha::Fecha(long fecha){
year = int(fecha/10000);//Extrayendo Year
mes = int((fecha-year*10000)/100); //Extrayendo mes
dia = int(fecha-year*10000-mes*100);//Extrayendo dia
}
void Fecha::MostrarFecha(){
    cout<<"Fecha Actual: "<<dia<<"/"<<mes<<"/"<<year<<endl;
}

int main()
{
    Fecha Hoy = Fecha(15,10,2023);
    Fecha Now = Fecha(20230115); // Se ingresa YearMesDia

    Hoy.MostrarFecha();
    Now.MostrarFecha();

    return 0;
}