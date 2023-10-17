#include <iostream>

using namespace std;

class PuntoCartesiano{
    private:
    int x, y;

    public:
    PuntoCartesiano(); //Declaracion de Constructor
    void setPunto(int, int);
    int getPuntoX();
    int getPuntoY();
};

PuntoCartesiano::PuntoCartesiano(){//Definicion de Constructor
} 
void PuntoCartesiano::setPunto(int x, int y){
    this->x = x;
    this->y = y;
}
int PuntoCartesiano::getPuntoX(){
    return x;
}
int PuntoCartesiano::getPuntoY(){
    return y;
}

int main(){
    PuntoCartesiano Punto1;

    Punto1.setPunto(3,5);
    cout<<"El punto del plano cartesiano es: "<<"("<<Punto1.getPuntoX()<<","<<Punto1.getPuntoY()<<")"<<endl;

    return 0;
}