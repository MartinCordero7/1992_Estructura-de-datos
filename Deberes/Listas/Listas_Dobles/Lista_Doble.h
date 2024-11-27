/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Sabado,  23 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 23 de noviembre de 2024
 * Enunciado del problema: Usando una lista doblemente enlazada realizar un manejo de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "Nodo.cpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <set>

class Lista_Doble {
public:
    Lista_Doble();
    ~Lista_Doble();

    void Insertar(string& N1, string& N2, string& Ape,int count,string& ID);
    void Eliminar(string& ID);
    void Buscar(string& N1, string& N2, string& Ape, string& ID);
    void Comprobar_existencia(string& N1, string& N2, string& Ape, int count,Nodo* nodo,string& ID);
    void Mostrar() const;
    bool validarCedula(string &cedula);
     bool cedulaExistente(const string& cedula);
    void agregarCedula(const string& cedula);

private:
    Nodo* cabeza;
    Nodo* cola;
    set<string> cedulasIngresadas;
};
