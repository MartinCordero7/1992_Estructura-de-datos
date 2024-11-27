/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Jueves,  21 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 21 de noviembre de 2024
 * Enunciado del problema: Usando una lista simple realizar la insercion de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "Nodo.cpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <set>

class Lista_Simple
{
public:
    Lista_Simple();
    ~Lista_Simple();

    void Insertar(string &N1, string &N2, string &Ape, int count, string &ID);
    void InsertarPorCola(string &N1, string &N2, string &Ape, string &ID);
    void Eliminar(string &ID);
    void Buscar(string &N1, string &N2, string &Ape, string &ID);
    void Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID);
    void Mostrar() const;
    void limpiarCadena(string &cadena);
    bool validarCedula(string &cedula);
    bool cedulaExistente(const string &cedula);
    void agregarCedula(const string &cedula);

private:
    Nodo *cabeza;
    Nodo *cola;
    set<string> cedulasIngresadas;
};
