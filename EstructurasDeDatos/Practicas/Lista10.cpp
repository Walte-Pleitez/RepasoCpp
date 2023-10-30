#include <iostream>

using namespace std;

struct Nodo{
    int n;
    struct Nodo *siguiente;
};
bool Vacia(Nodo *&);
void PushInicio(Nodo *&, int);
void PushFinal(Nodo *&, int n);
void PushEnmedio(Nodo *&, int, int);
void Imprimir(Nodo *&);

int main(){
    Nodo *Lista = nullptr;

    return 0;
}
bool Vacia(Nodo *&){}
void PushInicio(Nodo *&lista, int n){}
void PushFinal(Nodo *&lista, int ndato){}
void Imprimir(Nodo *&lista){}
void PushEnmedio(Nodo *&lista, int dato, int posicion){}

