#include "Lista.cpp"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <limits>

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
                cout << "8. Filtrar libros por periodo de anios" << endl;
                break;

            case 9:
                cout << "9. Salir" << endl;
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
            {
                int anioInicio, anioFin;
                time_t t = time(nullptr);
                tm *now = localtime(&t);
                int anioActual = now->tm_year + 1900;

                while (true)
                {
                    cout << "Ingrese el año de inicio (4 dígitos, al menos 5 años antes del anio actual): ";
                    cin >> anioInicio;
                    if (cin.fail() || anioInicio < 1000 || anioInicio > anioActual - 5)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Por favor, ingrese un anio válido (4 dígitos y debe ser al menos 5 años antes del anio actual)." << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                while (true)
                {
                    cout << "Ingrese el anio de fin (4 dígitos): ";
                    cin >> anioFin;
                    if (cin.fail() || anioFin < 1000 || anioFin > anioActual)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Por favor, ingrese un año válido (4 digitos y no mayor al anio actual)." << endl;
                    }
                    else if (anioFin < anioInicio)
                    {
                        cout << "El anio de fin debe ser mayor o igual al anio de inicio." << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                lista.filtrarPorPeriodo(anioInicio, anioFin);
                break;
            }

            case 9:
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
