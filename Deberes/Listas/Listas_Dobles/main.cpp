/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Sabado,  23 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 23 de noviembre de 2024
 * Enunciado del problema: Usando una lista doblemente enlazada realizar un manejo de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "Lista_Doble.cpp"
#include <iostream>
#include <string>

using namespace std;

int menu()
{
    int opcion;
    cout << "\n--- Menu ---" << endl;
    cout << "1. Insertar Nodo" << endl;
    cout << "2. Eliminar Nodo" << endl;
    cout << "3. Buscar Nodo" << endl;
    cout << "4. Mostrar Lista" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opcion: ";

    while (!(cin >> opcion))
    {
        cout << "Opcion invalida. Por favor, ingrese un numero: ";
        cin.clear();
    }

    return opcion;
}

int main()
{
    Lista_Doble lista;
    int count = 0;

    int opcion;
    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
        {
            string nombre1, nombre2, ape, id;
            lista.agregarCedula(id);
            nombre1 = ingresarLetras("Ingrese el primer nombre");
            nombre2 = ingresarLetras("Ingrese el segundo nombre");
            ape = ingresarLetras("Ingrese el apellido");
            id = ingresarNumeros("Ingrese la cedula");
            while (lista.validarCedula(id) == false)
            {
                cout << "Ingrese una cedula valida: ";
                id = ingresarNumeros("Ingrese la cedula");
            }
            lista.Insertar(nombre1, nombre2, ape, count, id);

            break;
        }
        case 2:
        {
            string id;
            cout << "Ingrese la cedula del nodo a eliminar: ";
            cin >> id;

            lista.Eliminar(id);
            break;
        }

        case 3:
        {
            string nombre1, nombre2, ap, id;
            cout << "Ingrese la cedula del nodo a buscar: ";
            cin >> id;

            lista.Buscar(nombre1, nombre2, ap, id);
            break;
        }
        case 4:
            cout << "Lista actual: ";
            lista.Mostrar();
            break;
        case 5:
            cout << "Saliendo del programa...." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
