#include <iostream>
//Nombre en ASCII: 87 65 76 84 69 82
using namespace std;

int main()
{
    //string nombre[6] = {87, 65, 76, 84, 69, 82};
    float valor;

    int suma = (87 + 65 + 76 + 84 + 69 + 82) % 6;
    cout << suma << endl; // el numero es la posicion donde almaceno la palabra

    return 0;
}
