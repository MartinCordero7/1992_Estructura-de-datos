#include "Lista_Circular_Simple.cpp"
#include <iostream>
#include <string>

using namespace std;

int menu() {
    int opcion;
    cout << "\n--- Menú ---" << endl;
    cout << "1. Insertar nodo" << endl;
    cout << "2. Buscar nodo por cédula" << endl;
    cout << "3. Eliminar nodo por cédula" << endl;
    cout << "4. Mostrar lista" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    return opcion;
}

int main() {
    Lista_Circular_Simple lista;

    int opcion;
    do {
        opcion = menu();

        switch (opcion) {
            case 1: {
                string nombre, segundoNombre, apellido, cedula;
                cin.ignore();
                cout << "Ingrese el nombre: ";
                getline(cin, nombre);
                cout << "Ingrese el segundo nombre: ";
                getline(cin, segundoNombre);
                cout << "Ingrese el apellido: ";
                getline(cin, apellido);
                cout << "Ingrese la cédula: ";
                getline(cin, cedula);
                lista.Insertar(nombre, segundoNombre, apellido, cedula);
                break;
            }
            case 2: {
                string cedula;
                cin.ignore();
                cout << "Ingrese la cédula a buscar: ";
                getline(cin, cedula);
                lista.Buscar(cedula);
                break;
            }
            case 3: {
                string cedula;
                cin.ignore();
                cout << "Ingrese la cédula a eliminar: ";
                getline(cin, cedula);
                lista.Eliminar(cedula);
                break;
            }
            case 4:
                lista.Mostrar();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
