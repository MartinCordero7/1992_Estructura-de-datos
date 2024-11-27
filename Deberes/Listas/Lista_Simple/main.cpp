/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri, Ricardo Xavier Altamirano Pineda
 * FECHA CREACION: Jueves,  21 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 21 de noviembre de 2024
 * Enunciado del problema: Usando una lista simple realizar la insercion de datos
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "Lista_Simple.cpp"
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
        cin.ignore(123, '\n');
    }

    return opcion;
}

int main()
{
    Lista_Simple lista;

    int opcion;
    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
        {
            string nombre1, nombre2, ape, id;
            nombre1 = ingresarLetras("Ingrese el primer nombre");
            lista.limpiarCadena(nombre1);
            nombre2 = ingresarLetras("Ingrese el segundo nombre");
            lista.limpiarCadena(nombre2);
            ape = ingresarLetras("Ingrese el apellido");
            lista.limpiarCadena(ape);
            id = ingresarNumeros("Ingrese la cedula");
            lista.limpiarCadena(id);
            while (!lista.validarCedula(id))
            {
                cout << "Ingrese una cedula valida: ";
                id = ingresarNumeros("Ingrese la cedula");
                lista.limpiarCadena(id);
            }
            lista.InsertarPorCola(nombre1, nombre2, ape, id);
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
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
