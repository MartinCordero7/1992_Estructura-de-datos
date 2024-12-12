#include "Lista.cpp"
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    Lista lista;
    int opcionSeleccionada = 1;
    bool salir = false;

    while (!salir)
    {
        system("cls");

        cout << "\nMenú (Use las flechas para navegar y Enter para seleccionar):\n\n";

        for (int i = 1; i <= 8; i++)
        {
            if (i == opcionSeleccionada)
            {
                cout << "-> ";
            }
            else
            {
                cout << "   ";
            }

            switch (i)
            {
            case 1:
                cout << "1. Agregar un libro" << endl;
                break;
            case 2:
                cout << "2. Mostrar libros" << endl;
                break;
            case 3:
                cout << "3. Buscar un libro" << endl;
                break;
            case 4:
                cout << "4. Eliminar un libro" << endl;
                break;
            case 5:
                cout << "5. Eliminar todos los libros" << endl;
                break;
            case 6:
                cout << "6. Crear Backup" << endl;
                break;
            case 7:
                cout << "7. Restaurar Backup" << endl;
                break;
            case 8:
                cout << "8. Salir" << endl;
                break;
            }
        }

        char tecla = _getch();
        switch (tecla)
        {
        case 72:
            opcionSeleccionada--;
            if (opcionSeleccionada < 1)
                opcionSeleccionada = 8;
            break;
        case 80:
            opcionSeleccionada++;
            if (opcionSeleccionada > 8)
                opcionSeleccionada = 1;
            break;
        case 13:

            switch (opcionSeleccionada)
            {
            case 1:
            {
                string autor, libro, fecha, editorial, isbn;
                lista.agregarNodo(autor, libro, fecha, editorial);
                break;
            }
            case 2:
                lista.mostrarLista();
                break;
            case 3:
            {
                string libro;
                cout << "Ingrese el título del libro a buscar: ";
                getline(cin, libro);
                lista.buscarLibro(libro);
                break;
            }
            case 4:
            {
                string libro;
                cout << "Ingrese el título del libro a eliminar: ";
                getline(cin, libro);
                lista.eliminarLibro(libro);
                break;
            }
            case 5:
                lista.eliminarTodosLosLibros();
                break;
            case 6:
            {
                string nombreBaseArchivo;
                cout << "Ingrese el nombre base del archivo de respaldo (Presione espacio antes de ingresar el nombre): ";
                cin.ignore();
                getline(cin, nombreBaseArchivo);
                lista.crearBackup(nombreBaseArchivo);
                break;
            }
            case 7:
            {
                string rutaBackup;
                cout << "Ingrese la ruta completa del archivo de respaldo (Presione espacio antes de ingresar el nombre): ";
                cin.ignore();
                getline(cin, rutaBackup);
                lista.restaurarBackup(rutaBackup);
                break;
            }
            case 8:
                salir = true;
                break;
            }

            if (!salir)
            {
                cout << "\nPresione cualquier tecla para continuar...";
                _getch();
            }
            break;
        }
    }

    cout << "Saliendo del programa..." << endl;
    return 0;
}
