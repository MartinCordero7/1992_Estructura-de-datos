#include "Lista_Circular_Simple.h"
#include <iostream>
#include <conio.h>

Lista_Circular_Simple::Lista_Circular_Simple() : cabeza(nullptr) {}

Lista_Circular_Simple::~Lista_Circular_Simple()
{
    if (cabeza)
    {
        Nodo *actual = cabeza;
        do
        {
            Nodo *temp = actual;
            actual = actual->siguiente;
            delete temp;
        } while (actual != cabeza);
    }
}

bool esNombreValido(const std::string &str)
{
    // Verifica que solo contenga letras y espacios
    for (char c : str)
    {
        if (!isalpha(c) && c != ' ') // Asegura que no haya números o caracteres especiales
        {
            std::cout << "El nombre o apellido solo puede contener letras y espacios." << std::endl;
            return false;
        }
    }
    return true;
}

bool Lista_Circular_Simple::validarCedula(std::string &cedula)
{
    // Verifica que la cédula tenga exactamente 10 dígitos y solo contenga números
    if (cedula.length() != 10)
    {
        std::cout << "La cédula debe tener exactamente 10 dígitos." << std::endl;
        return false;
    }

    for (char c : cedula)
    {
        if (!isdigit(c)) // Asegura que solo haya números
        {
            std::cout << "La cédula solo puede contener números." << std::endl;
            return false;
        }
    }

    // Validación del algoritmo de cédula (ya implementado correctamente)
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

void Lista_Circular_Simple::Insertar(std::string &nombre, std::string &segundoNombre, std::string &apellido, std::string &cedula)
{
    // Validar la cédula
    if (!validarCedula(cedula))
    {
        std::cout << "Cédula inválida. No se puede insertar el nodo." << std::endl;
        return;
    }

    // Validar que los nombres y apellidos no contengan números
    if (!esNombreValido(nombre) || !esNombreValido(segundoNombre) || !esNombreValido(apellido))
    {
        std::cout << "Nombre, segundo nombre o apellido contienen caracteres no válidos." << std::endl;
        return;
    }

    // Crear el nuevo nodo
    Nodo *nuevoNodo = new Nodo(nombre, segundoNombre, apellido, cedula);

    // Si la lista está vacía, el nuevo nodo será el único elemento
    if (!cabeza)
    {
        cabeza = nuevoNodo;
        cabeza->siguiente = cabeza; // Se apunta a sí mismo (es una lista circular)
    }
    else
    {
        Nodo *actual = cabeza;

        // Recorrer hasta el último nodo
        while (actual->siguiente != cabeza)
        {
            actual = actual->siguiente;
        }

        // Conectar el último nodo con el nuevo nodo
        actual->siguiente = nuevoNodo;

        // Conectar el nuevo nodo con la cabeza (mantener la circularidad)
        nuevoNodo->siguiente = cabeza;
    }

    std::cout << "Nodo insertado correctamente: " << nuevoNodo->getDatos() << std::endl;
}

void Lista_Circular_Simple::Buscar(const std::string &cedula) const
{
    if (!cabeza)
    {
        std::cout << "Lista vacía" << std::endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        if (actual->cedula == cedula)
        {
            std::cout << "Nodo encontrado: " << actual->getDatos() << std::endl;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Nodo no encontrado con cédula: " << cedula << std::endl;
}

void Lista_Circular_Simple::Eliminar(const std::string &cedula)
{
    if (!cabeza)
    {
        std::cout << "Lista vacía" << std::endl;
        return;
    }

    Nodo *actual = cabeza;
    Nodo *previo = nullptr;

    do
    {
        if (actual->cedula == cedula)
        {
            if (actual == cabeza && actual->siguiente == cabeza)
            {
                delete actual;
                cabeza = nullptr;
            }
            else if (actual == cabeza)
            {
                Nodo *ultimo = cabeza;
                while (ultimo->siguiente != cabeza)
                {
                    ultimo = ultimo->siguiente;
                }
                cabeza = cabeza->siguiente;
                ultimo->siguiente = cabeza;
                delete actual;
            }
            else
            {
                previo->siguiente = actual->siguiente;
                delete actual;
            }
            std::cout << "Nodo eliminado con cédula: " << cedula << std::endl;
            return;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Nodo no encontrado para eliminar con cédula: " << cedula << std::endl;
}

void Lista_Circular_Simple::Mostrar() const
{
    if (!cabeza)
    {
        std::cout << "Lista vacía" << std::endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        std::cout << actual->getDatos() << " -> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    std::cout << "cabeza" << std::endl;
}
