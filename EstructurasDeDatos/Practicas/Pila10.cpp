#include <iostream>

using namespace std;

struct Nodo{
    int n;
    struct Nodo *siguiente;
};
bool Vacia(Nodo *&);
void Push(Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&);

int main(){
    Nodo *Pila = nullptr;

    return 0;
}
bool Vacia(Nodo *&){}
void Push(Nodo *&, int){}
void Imprimir(Nodo *&){}
void Pop(Nodo *&){}