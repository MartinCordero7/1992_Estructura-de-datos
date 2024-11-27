/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Jueves,  21 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 21 de noviembre de 2024
 * Enunciado del problema: Usando una lista simple realizar la insercion de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "Lista_Simple.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

Lista_Simple::Lista_Simple() : cabeza(nullptr), cola(nullptr) {}

Lista_Simple::~Lista_Simple()
{
    while (cabeza != nullptr)
    {
        Nodo *temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
    cola = nullptr;
}

void Lista_Simple::InsertarPorCola(string &N1, string &N2, string &Ape, string &ID)
{
    Nodo *nuevoNodo = new Nodo(N1, N2, Ape, ID);
    if (cola == nullptr)
    {
        cabeza = cola = nuevoNodo;
    }
    else
    {
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
    agregarCedula(ID);
}

void Lista_Simple::limpiarCadena(string &cadena)
{
    cadena.erase(remove_if(cadena.begin(), cadena.end(), [](char c)
                           { return !isalnum(c) && c != ' '; }),
                 cadena.end());
}

void Lista_Simple::Insertar(string &N1, string &N2, string &Ape, int count, string &ID)
{
    Nodo *nuevoNodo = new Nodo(N1, N2, Ape, ID);
    if (cabeza == nullptr)
    {
        cabeza = cola = nuevoNodo;
    }
    else
    {
        Nodo *actual = cabeza;
        while (actual->getSiguiente() != nullptr)
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
    Comprobar_existencia(N1, N2, Ape, count, nuevoNodo, ID);
}

bool Lista_Simple::validarCedula(string &cedula)
{
    if (cedula.length() != 10)
    {
        return false;
    }

    for (char c : cedula)
    {
        if (!isdigit(c))
        {
            cout << "Ingrese solo numeros";
            return false;
        }
    }

    int suma = 0;
    for (int i = 0; i < 9; i++)
    {
        int digito = cedula[i] - '0';
        if (i % 2 == 0)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int digitoVerificador = cedula[9] - '0';
    int resultado = 10 - (suma % 10);
    if (resultado == 10)
    {
        resultado = 0;
    }

    return digitoVerificador == resultado;
}

void Lista_Simple::Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID)
{
    count = -1;
    Nodo *actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->getNombre1() == N1 && actual->getNombre2() == N2 && actual->getApellido() == Ape && actual->getCedula() == ID)
        {
            count++;
        }
        actual = actual->getSiguiente();
    }

    if (cedulaExistente(ID))
    {
        cout << "La cédula ya ha sido ingresada anteriormente." << endl;
        cin >> ID;
    }
    else
    {
        agregarCedula(ID);
    }
}

bool Lista_Simple::cedulaExistente(const string &cedula)
{
    return cedulasIngresadas.find(cedula) != cedulasIngresadas.end();
}

void Lista_Simple::agregarCedula(const string &cedula)
{
    cedulasIngresadas.insert(cedula);
}

char *ingresarLetras(const char *msj)
{
    static char dato[25];
    char c;
    int i = 0;         
    int cursorPos = 0; 
    std::cout << msj << ": ";
    while (true)
    {
        c = _getch();
        if (c == 13)
        { 
            dato[i] = '\0';
            std::cout << std::endl;
            break;
        }
        else if (c == 8)
        { 
            if (cursorPos > 0)
            {
                for (int j = cursorPos - 1; j < i - 1; j++)
                {
                    dato[j] = dato[j + 1];
                }
                i--;
                cursorPos--;
                dato[i] = '\0';
                std::cout << "\b \b";
                std::cout << dato + cursorPos << " ";
                for (int j = 0; j <= i - cursorPos; j++)
                    std::cout << "\b";
            }
        }
        else if (c == 0 || c == -32)
        { 
            char teclaEspecial = _getch();
            if (teclaEspecial == 75 && cursorPos > 0)
            { 
                cursorPos--;
                std::cout << "\b";
            }
            else if (teclaEspecial == 77 && cursorPos < i)
            { 
                std::cout << dato[cursorPos];
                cursorPos++;
            }
        }
        else if ((isalpha(c) || c == ' ') && i < 24)
        { 
            
            if (c == ' ' && (i == 0 || dato[cursorPos - 1] == ' '))
            {
                continue;
            }
            
            for (int j = i; j > cursorPos; j--)
            {
                dato[j] = dato[j - 1];
            }
            dato[cursorPos] = c;
            i++;
            cursorPos++;
            dato[i] = '\0';
            std::cout << dato + cursorPos - 1;
            for (int j = 0; j < i - cursorPos; j++)
                std::cout << "\b";
        }
    }
    return dato;
}

char *ingresarNumeros(const char *msj)
{
    static char dato[25];
    char c;
    int i = 0;
    int cursorPos = 0;
    std::cout << msj << ": ";
    while (true)
    {
        c = _getch();
        if (c == 13)
        {
            dato[i] = '\0';
            std::cout << std::endl;
            break;
        }
        else if (c == 8)
        {
            if (cursorPos > 0)
            {
                for (int j = cursorPos - 1; j < i - 1; j++)
                {
                    dato[j] = dato[j + 1];
                }
                i--;
                cursorPos--;
                dato[i] = '\0';
                std::cout << "\b \b";
                std::cout << dato + cursorPos << " ";
                for (int j = 0; j <= i - cursorPos; j++)
                    std::cout << "\b";
            }
        }
        else if (c == 0 || c == -32)
        {
            char teclaEspecial = _getch();
            if (teclaEspecial == 75 && cursorPos > 0)
            {
                cursorPos--;
                std::cout << "\b";
            }
            else if (teclaEspecial == 77 && cursorPos < i)
            {
                std::cout << dato[cursorPos];
                cursorPos++;
            }
        }
        else if (isdigit(c) && i < 24)
        {
            for (int j = i; j > cursorPos; j--)
            {
                dato[j] = dato[j - 1];
            }
            dato[cursorPos] = c;
            i++;
            cursorPos++;
            dato[i] = '\0';
            std::cout << dato + cursorPos - 1;
            for (int j = 0; j < i - cursorPos; j++)
                std::cout << "\b";
        }
    }
    return dato;
}

void Lista_Simple::Eliminar(string &ID)
{
    Nodo *actual = cabeza;
    Nodo *anterior = nullptr;

    while (actual != nullptr)
    {
        if (actual->getCedula() == ID)
        {
            if (anterior != nullptr)
            {
                anterior->setSiguiente(actual->getSiguiente());
            }
            else
            {
                cabeza = actual->getSiguiente();
            }
            delete actual;
            cout << "Nodo eliminado" << endl;

            return;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado para eliminar" << endl;
}

void Lista_Simple::Buscar(string &N1, string &N2, string &Ape, string &ID)
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->getCedula() == ID)
        {
            cout << "Nodo encontrado:\n"
                 << "Nombre1 = " << actual->getNombre1()
                 << ", Nombre2 = " << actual->getNombre2()
                 << ", Apellido = " << actual->getApellido()
                 << ", Cedula = " << actual->getCedula()
                 << endl;
            return;
        }
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado" << endl;
}

void Lista_Simple::Mostrar() const
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        cout << "Nombre1: " << actual->getNombre1()
             << ", Nombre2: " << actual->getNombre2()
             << ", Apellido: " << actual->getApellido()
             << "Cedula = " << actual->getCedula()
             << endl;
        actual = actual->getSiguiente();
    }
    cout << "nullptr" << endl;
}