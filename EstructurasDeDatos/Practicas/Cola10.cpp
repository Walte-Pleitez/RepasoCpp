#include <iostream>

using namespace std;

struct Nodo{
    int n;
    struct Nodo *siguiente;
};
bool Vacia(Nodo *&);
void Push(Nodo *&, Nodo *&, int);
void Imprimir(Nodo *&);
void Pop(Nodo *&, Nodo *&);

int main(){
    Nodo *frente = nullptr;
    Nodo *final = nullptr;

    return 0;
}
bool Vacia(Nodo *&){}
void Push(Nodo *&, Nodo *&, int){}
void Imprimir(Nodo *&){}
void Pop(Nodo *&, Nodo *&){}
