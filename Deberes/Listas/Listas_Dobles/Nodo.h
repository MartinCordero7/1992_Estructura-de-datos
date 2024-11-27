/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Sabado,  23 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 23 de noviembre de 2024
 * Enunciado del problema: Usando una lista doblemente enlazada realizar un manejo de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include <iostream>
#include <string>

using namespace std;

class Nodo
{
private:
    string Nombre1;
    string Nombre2;
    string Apellido;

    string Cedula;
    Nodo *Siguiente;
    Nodo *Anterior;

public:
    string getNombre2(void);
    void setNombre2(string newNombre2);
    Nodo(string N1, string N2, string Ape, string ID, Nodo *S = nullptr, Nodo *A = nullptr);
    ~Nodo();
    string getNombre1(void);
    string getCedula(void);
    void setNombre1(string newNombre1);
    void setCedula(string newCedula);
    string getApellido(void);
    void setApellido(string newApellido);
    Nodo *getSiguiente(void);
    void setSiguiente(Nodo *newSiguiente);
    Nodo *getAnterior(void);
    void setAnterior(Nodo *newAnterior);
};
