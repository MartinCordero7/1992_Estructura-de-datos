/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Jueves,  21 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 21 de noviembre de 2024
 * Enunciado del problema: Usando una lista simple realizar la insercion de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "Nodo.h"
#include <string>
using namespace std;

string Nodo::getNombre1(void)
{
    return Nombre1;
}

void Nodo::setNombre1(string newNombre1)
{
    Nombre1 = newNombre1;
}

string Nodo::getApellido(void)
{
    return Apellido;
}

string Nodo::getCedula(void)
{
    return Cedula;
}

void Nodo::setCedula(string newCedula)
{
    Cedula = newCedula;
}

void Nodo::setApellido(string newApellido)
{
    Apellido = newApellido;
}

std::string Nodo::getNombre2(void)
{
    return Nombre2;
}

void Nodo::setNombre2(string newNombre2)
{
    Nombre2 = newNombre2;
}

Nodo::Nodo(string N1, string N2, string Ape, string ID, Nodo *S)
{
    Nombre1 = N1;
    Nombre2 = N2;
    Apellido = Ape;
    Siguiente = S;
    Cedula = ID;
}

Nodo::~Nodo()
{
    // Destructor
}

Nodo *Nodo::getSiguiente(void)
{
    return Siguiente;
}

void Nodo::setSiguiente(Nodo *newSiguiente)
{
    Siguiente = newSiguiente;
}
