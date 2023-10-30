#include <iostream>

using namespace std;

#define size 5

struct Nodo{
    int frenteCola;
    int finalCola;
    int elemento;
};

void Crear(struct Nodo *);
bool Vacia(struct Nodo *);
int Llena(Nodo *);
void Insertar(struct Nodo *, int);
void Eliminar(struct Nodo *);
int Dimension(Nodo *);

int main(){
    Nodo nodo;

    return 0;
}