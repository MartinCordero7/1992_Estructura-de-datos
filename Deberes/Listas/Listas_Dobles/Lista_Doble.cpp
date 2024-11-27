/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Sabado,  23 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 23 de noviembre de 2024
 * Enunciado del problema: Usando una lista doblemente enlazada realizar un manejo de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "Lista_Doble.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

Lista_Doble::Lista_Doble() : cabeza(nullptr), cola(nullptr) {}

Lista_Doble::~Lista_Doble()
{
    while (cabeza != nullptr)
    {
        Nodo *temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}

void Lista_Doble::Insertar(string &N1, string &N2, string &Ape, int count, string &ID)
{
    Nodo *nuevoNodo = new Nodo(N1, N2, Ape, ID);
    if (cabeza == nullptr)
    {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }
    else
    {
        cola->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(cola);
        cola = nuevoNodo;
    }
    Comprobar_existencia(N1, N2, Ape, count, nuevoNodo, ID);
}
bool Lista_Doble::validarCedula(string &cedula)
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

void Lista_Doble::Comprobar_existencia(string &N1, string &N2, string &Ape, int count, Nodo *nodo, string &ID)
{
    count = -1;
    Nodo *actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->getNombre1() == N1 && actual->getNombre2() == N2 && actual->getApellido() == Ape)
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
bool Lista_Doble::cedulaExistente(const string &cedula)
{
    return cedulasIngresadas.find(cedula) != cedulasIngresadas.end();
}

void Lista_Doble::agregarCedula(const string &cedula)
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
    cout << msj << ": ";
    while ((c = _getch()) != 13)
    {
        if (c >= '0' && c <= '9')
        {
            dato[i++] = c;
            cout << c;
        }
    }
    dato[i] = '\0';
    cout << endl;
    return dato;
}

void Lista_Doble::Eliminar(string &ID)
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->getCedula ()== ID)
        {
            if (actual->getAnterior() != nullptr)
            {
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
            }
            else
            {
                cabeza = actual->getSiguiente();
            }
            if (actual->getSiguiente() != nullptr)
            {
                actual->getSiguiente()->setAnterior(actual->getAnterior());
            }
            else
            {
                cola = actual->getAnterior();
            }
            delete actual;
            cout << "Nodo eliminado" << endl;

            return;
        }
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado para eliminar" << endl;
}

void Lista_Doble ::Buscar(string &N1, string &N2, string &Ape, string &ID)
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->getCedula() == ID)
        {
            cout << "Nodo encontrado:\n"
                 << "N1 = " << actual->getNombre1()
                 << ", \nNombre2 = " << actual->getNombre2()
                 << ", \nApellido = " << actual->getApellido()
                 << endl;
            return;
        }
        actual = actual->getSiguiente();
    }
    cout << "Nodo no encontrado" << endl;
}

void Lista_Doble::Mostrar() const
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        cout << "Nombre1: " << actual->getNombre1()
             << ", Nombre2: " << actual->getNombre2()
             << ", Apellido: " << actual->getApellido()
             << " -> <- ";
        actual = actual->getSiguiente();
    }
    cout << "nullptr" << endl;
}
