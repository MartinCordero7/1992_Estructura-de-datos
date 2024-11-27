#pragma once
#include "Nodo.cpp"
#include <string>

class Lista_Circular_Simple
{
public:
    Lista_Circular_Simple();
    ~Lista_Circular_Simple();

    void Insertar(std::string &nombre, std::string &segundoNombre, std::string &apellido, std::string &cedula);
    void Buscar(const std::string &cedula) const;
    void Eliminar(const std::string &cedula);
    void Mostrar() const;
    bool validarCedula(std::string &cedula);

private:
    Nodo *cabeza;
};
