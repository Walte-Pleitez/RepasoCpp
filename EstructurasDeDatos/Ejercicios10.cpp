#include <iostream>
#include <string>

using namespace std;

struct Direccion
{
    string Pais = "";
    string Departamento = "";
    string Ciudad = "";
};
struct Pack
{
    int numSeg;
    string nombreRem;
    string nombreDest;
    int fragil;
    struct Direccion dondeEnt;
    string Prioridad[3] = {"3 Dias", "7 Dias", "15 Dias"};
};
struct Nodo
{
    struct Pack Paquete;
    struct Nodo *siguiente;
};

bool Vacia(Nodo *&);
void Recoleccion(Nodo *&, Nodo *&, Nodo, int, int);
void PushPaquete(Nodo *&, Nodo *&, Nodo, int &, int);
void MostrarInput(Nodo, int);
void MostrarPacks(Nodo *&, int);
void PopPaquete(Nodo *&, Nodo *&);

int main()
{
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    Nodo input; //REVISAR SI SE DEBIA PASAR POR REFERENCIA
    int continuar = 1, eleccion;

    cout << "********** BIENVENIDO AL SISTEMA DE SEGUIMIENTO DE PAQUETES **********" << endl;

    do
    {
        //Recursos para NUEVO PAQUETE
        int idPack = 0, continuar2 = 1, diasElegidos;

        cout << "1)Agregar Paquete 2)Trackeo 3)Actualizar Entrega 4)Mostrar Cola 0)Salir" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            do
            {
                idPack++;
                Recoleccion(frente, final, input, idPack, diasElegidos);
                PushPaquete(frente, final, input, idPack, diasElegidos);
                //MostrarInput(input, diasElegidos);

                cout << "0)MENU GRAL 1)AGREGAR PAQUETE" << endl;
                cin >> continuar2;
            } while (continuar2 == 1);
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            cout << "---------- PAQUETES EN LA LISTA ----------" << endl; //Para fecha de entrega llamar a Prioridad (P)
            MostrarPacks(frente, diasElegidos);
            break;
        case 0:
            continuar = eleccion;
            break;
        }

    } while (continuar == 1);

    return 0;
}
//FUNCIONES COLA: Basicas, toString, fragil para toString, prioridad para toString.
//Basicas:
bool Vacia(Nodo *&frente)
{
    if (frente == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Recoleccion(Nodo *&frente, Nodo *&final, Nodo input, int idPack, int diasElegidos)
{
    cout<<"Prueba1 Recol: "<<input.Paquete.nombreRem<<" - final: "<<input.Paquete.nombreDest<<" - idPack: "<<idPack<<" - Dias: "<<diasElegidos<<endl;
    cout<<"Prueba2 Recol: "<<frente->Paquete.nombreRem<<" - final: "<<input.Paquete.nombreRem<<" - idPack: "<<idPack<<" - Dias: "<<diasElegidos<<endl;

    idPack++; //Sirve para Id de seguimiento
    cout << "AVISO: Escriba punto (.) cuando termine de ingresar datos" << endl;
    cout << endl;
    cout << "Ingrese su nombre como Remitente: " << endl;
    getline(cin, input.Paquete.nombreRem, '.');
    cout << "Ingrese el nombre del Destinatario: " << endl;
    getline(cin, input.Paquete.nombreDest, '.');
    cout << "0)Paquete No fragil 1)Paquete fragil" << endl;
    cin >> input.Paquete.fragil;

    cout << "INGRESE DIRECCION EN EL ORDEN QUE SE INDICA y finalice con un punto (.)" << endl;
    cout << "Pais: " << endl;
    getline(cin, input.Paquete.dondeEnt.Pais, '.');
    cout << "Departamento: " << endl;
    getline(cin, input.Paquete.dondeEnt.Departamento, '.');
    cout << "Ciudad: " << endl;
    getline(cin, input.Paquete.dondeEnt.Ciudad, '.');
    cout << "ELIJA LA RAPIDEZ DE ENTREGA DE ACUERDO A LAS OPCIONES: " << endl;
    cout << "0) 3 Dias  1) 7 Dias  2) 15 Dias" << endl;
    cin >> diasElegidos;
}
void PushPaquete(Nodo *&frente, Nodo *&final, Nodo input, int &idPack, int diasElegidos)
{//lA PRUEBA DIO ERROR, LOS VALORES NO LLEGAN HASTA AQUI.
    Nodo *nuevoPack = new Nodo(); //reserva de memoria
    cout<<"Prueba Push: "<<frente->Paquete.nombreRem<<" - final: "<<input.Paquete.nombreRem<<" - idPack: "<<idPack<<" - Dias: "<<diasElegidos<<endl;

    //Asignacion de info al paquete
    nuevoPack->Paquete.numSeg = idPack;
    nuevoPack->Paquete.nombreRem = input.Paquete.nombreRem;
    nuevoPack->Paquete.nombreDest = input.Paquete.nombreDest;
    nuevoPack->Paquete.fragil = input.Paquete.fragil;
    nuevoPack->Paquete.dondeEnt.Pais = input.Paquete.dondeEnt.Pais;
    nuevoPack->Paquete.dondeEnt.Departamento = input.Paquete.dondeEnt.Departamento;
    nuevoPack->Paquete.dondeEnt.Ciudad = input.Paquete.dondeEnt.Ciudad;
    nuevoPack->Paquete.Prioridad[diasElegidos];

    nuevoPack->siguiente = nullptr;
    //Condiciones de encolamiento de paquetes
    if (Vacia(frente))
    { //si esta vacia se queda en el frente
        frente = nuevoPack;
    }
    else
    { //Si tiene packs se encola hasta el final
        final->siguiente = nuevoPack;
    }
    final = nuevoPack;
}

void MostrarInput(Nodo input, int diasElegidos)
{
    cout << "******************** DATOS INGRESADOS ********************" << endl;
    cout << "REMITENTE: " << input.Paquete.nombreRem << endl;
    cout << "DESTINATARIO: " << input.Paquete.nombreDest << endl;
    cout << "TIPO DE PAQUETE: ";
    if (input.Paquete.fragil == 1)
    {
        cout << "Paquete Fragil" << endl;
    }
    else if (input.Paquete.fragil == 0)
    {
        cout << "Paquete No Fragil" << endl;
    }
    else
    {
        cout << "Dato ingresado no valido, siga las instrucciones" << endl;
    }
    cout << "---------- DIRECCION ----------" << endl;
    cout << "MUNICIPIO: " << input.Paquete.dondeEnt.Ciudad << endl;
    cout << "DEPARTAMENTO: " << input.Paquete.dondeEnt.Departamento << endl;
    cout << "PAIS: " << input.Paquete.dondeEnt.Pais << endl;
    cout << "TIEMPO DE ENTREGA: " << input.Paquete.Prioridad[diasElegidos] << endl;
    cout << "******************** Fin Ingreso ********************" << endl;
}
void MostrarPacks(Nodo *&frente, int diasElegidos)
{
    Nodo *temp = frente;

    while (temp != nullptr)
    {
        cout << "********** Paquete " << frente->Paquete.numSeg << " **********" << endl;
        cout << "ID PAQUETE: " << frente->Paquete.numSeg << endl;
        cout << "REMITENTE: " << frente->Paquete.nombreRem << endl;
        cout << "DESTINATARIO: " << frente->Paquete.nombreDest << endl;
        cout << "ENTREGA: " << frente->Paquete.Prioridad[diasElegidos] << endl;
        cout << "****************************************" << endl;

        temp = temp->siguiente;
    }
}
void PopPaquete(Nodo *&frente, Nodo *&final)
{
    if (!Vacia(frente))
    {
        Nodo *temporal = frente;
        if (frente == final)
        {
            frente = nullptr;
            final = nullptr;
        }
        else
        {
            frente = temporal->siguiente;
        }
        delete temporal;
    }
}
//FUNCIONES PRIORIDAD: fecha estimada entrega y ubicacion actual; setEntrega, setDireccion
//FUNCIONES DIRECCION
