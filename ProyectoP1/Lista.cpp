#include "Lista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;

Lista::Lista() : cabeza(nullptr) {}

Lista::~Lista()
{
    eliminarTodosLosLibros();
}

void Lista::eliminarTodosLosLibros()
{
    if (!cabeza)
    {
        cout << "La lista ya está vacía." << endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        Nodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);

    cabeza = nullptr;
    cout << "Todos los libros han sido eliminados." << endl;
}

char *ingresarLetras(const char *msj)
{
    static char dato[25];
    char c;
    int i = 0;
    int cursorPos = 0;
    cout << msj << ": ";
    while (true)
    {
        c = _getch();
        if (c == 13)
        {
            dato[i] = '\0';
            cout << endl;
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
                cout << "\b \b";
                cout << dato + cursorPos << " ";
                for (int j = 0; j <= i - cursorPos; j++)
                    cout << "\b";
            }
        }
        else if (c == 0 || c == -32)
        {
            char teclaEspecial = _getch();
            if (teclaEspecial == 75 && cursorPos > 0)
            {
                cursorPos--;
                cout << "\b";
            }
            else if (teclaEspecial == 77 && cursorPos < i)
            {
                cout << dato[cursorPos];
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
            cout << dato + cursorPos - 1;
            for (int j = 0; j < i - cursorPos; j++)
                cout << "\b";
        }
    }
    return dato;
}
void Lista::crearBackup(const string &nombreBaseArchivo)
{
    if (!cabeza)
    {
        cout << "La lista está vacía. No hay datos para respaldar." << endl;
        return;
    }

    time_t ahora = time(0);
    tm *tiempoLocal = localtime(&ahora);

    int dia = tiempoLocal->tm_mday;
    int mes = tiempoLocal->tm_mon + 1;
    int anio = tiempoLocal->tm_year + 1900;
    int hora = tiempoLocal->tm_hour;
    int minuto = tiempoLocal->tm_min;
    int segundo = tiempoLocal->tm_sec;

    string rutaDirectorio = "C:/Users/alejo/Programas U/Proyecto/";

    string nombreArchivo = rutaDirectorio + nombreBaseArchivo + "_" +
                           to_string(anio) + "_" + to_string(mes) + "_" + to_string(dia) + "_" +
                           to_string(hora) + "_" + to_string(minuto) + "_" + to_string(segundo) + ".txt";

    ofstream archivo(nombreArchivo);
    if (!archivo)
    {
        cout << "No se pudo crear el archivo de respaldo." << endl;
        return;
    }

    archivo << "Respaldo generado el: "
            << dia << "/" << mes << "/" << anio << " "
            << hora << ":" << minuto << ":" << segundo << "\n\n";

    Nodo *actual = cabeza;
    do
    {
        archivo << "Autor: " << actual->autor << '\n';
        archivo << "Libro: " << actual->libro << '\n';
        archivo << "Fecha de Publicacion: " << actual->fechaPublicacion << '\n';
        archivo << "Editorial: " << actual->editorial << '\n';
        archivo << "ISBN: " << actual->isbn << '\n';
        archivo << "----------------------------------------\n";

        actual = actual->siguiente;
    } while (actual != cabeza);

    archivo.close();
    cout << "Respaldo creado exitosamente en el archivo: " << nombreArchivo << endl;
}

void Lista::restaurarBackup(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de respaldo." << endl;
        return;
    }

    string linea, autor, libro, fechaPublicacion, editorial, isbn;

    while (getline(archivo, linea))
    {

        if (linea.empty() || linea.find("Respaldo generado el:") != string::npos)
            continue;

        if (linea.find("Autor: ") == 0)
        {
            autor = linea.substr(7);
        }
        else if (linea.find("Libro: ") == 0)
        {
            libro = linea.substr(7);
        }
        else if (linea.find("Fecha de Publicacion: ") == 0)
        {
            fechaPublicacion = linea.substr(21);
        }
        else if (linea.find("Editorial: ") == 0)
        {
            editorial = linea.substr(11);
        }
        else if (linea.find("ISBN: ") == 0)
        {
            isbn = linea.substr(6);

            Nodo *nuevo = new Nodo(autor, libro, fechaPublicacion, editorial, isbn);
            if (!cabeza)
            {
                cabeza = nuevo;
                cabeza->siguiente = cabeza;
                cabeza->anterior = cabeza;
            }
            else
            {
                Nodo *ultimo = cabeza->anterior;
                nuevo->siguiente = cabeza;
                nuevo->anterior = ultimo;
                ultimo->siguiente = nuevo;
                cabeza->anterior = nuevo;
            }

            autor.clear();
            libro.clear();
            fechaPublicacion.clear();
            editorial.clear();
            isbn.clear();
        }
    }

    archivo.close();
    cout << "Respaldo restaurado exitosamente desde el archivo: " << nombreArchivo << endl;
}

char *ingresarNumerosConLimite(const char *msj, int limiteInferior, int limiteSuperior)
{
    static char dato[25];
    char c;
    int i = 0;
    cout << msj << ": ";
    while (true)
    {
        c = _getch();
        if (c == 13)
        {
            dato[i] = '\0';
            if (i > 0)
            {
                int valor = atoi(dato);
                if (valor >= limiteInferior && valor <= limiteSuperior)
                {
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "\nEntrada fuera de rango. Intente de nuevo.\n";
                    i = 0;
                    cout << msj << ": ";
                }
            }
            else
            {
                cout << "\nEntrada vacía. Intente de nuevo.\n";
                cout << msj << ": ";
            }
        }
        else if (c == 8)
        {
            if (i > 0)
            {
                cout << "\b \b";
                i--;
                dato[i] = '\0';
            }
        }
        else if (isdigit(c) && i < 24)
        {
            dato[i] = c;
            dato[i + 1] = '\0';
            int valor = atoi(dato);
            if (valor <= limiteSuperior)
            {
                cout << c;
                i++;
            }
        }
    }
    return dato;
}

string Lista::generarISBN()
{
    srand(time(0));                          // Inicializa el generador aleatorio
    string prefijo = "978";                  // Prefijo estándar
    string grupo = "84";                     // Código para español
    string editor = to_string(rand() % 100); // Simulación del código del editor
    string numeroTitulo = to_string(rand() % 1000000);
    string base = prefijo + grupo + editor + numeroTitulo;

    int suma = 0;
    for (size_t i = 0; i < base.size(); ++i)
    {
        int digito = base[i] - '0';
        suma += (i % 2 == 0) ? digito : digito * 3;
    }
    int digitoControl = (10 - (suma % 10)) % 10;

    return base + to_string(digitoControl);
}

bool esFechaValida(int dia, int mes, int anio)
{
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1)
        return false;

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        diasPorMes[1] = 29;

    return dia <= diasPorMes[mes - 1];
}

void Lista::agregarNodo(const string &mensajeAutor, const string &mensajeLibro, const string &mensajeFecha, const string &mensajeEditorial)
{
    cout << "Ingrese los datos del libro:" << endl;

    string autor = ingresarLetras("Ingrese el autor");
    if (autor.empty())
    {
        cout << "El autor no puede estar vacío." << endl;
        return;
    }

    string libro;
    cout << "Ingrese el título del libro: ";
    getline(cin, libro);
    if (libro.empty())
    {
        cout << "El título del libro no puede estar vacío." << endl;
        return;
    }

    int mes = atoi(ingresarNumerosConLimite("Ingrese el mes de publicación", 1, 12));
    int limiteDias = (mes == 2) ? 29 : ((mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : 31);
    int dia = atoi(ingresarNumerosConLimite("Ingrese el día de publicación", 1, limiteDias));
    int anioActual = 2024;
    int anio = atoi(ingresarNumerosConLimite("Ingrese el año de publicación", 1, anioActual));

    if (!esFechaValida(dia, mes, anio))
    {
        cout << "Fecha inválida. Por favor, intente de nuevo." << endl;
        return;
    }
    string fechaPublicacion = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);

    string editorial = ingresarLetras("Ingrese la editorial");
    if (editorial.empty())
    {
        cout << "La editorial no puede estar vacía." << endl;
        return;
    }

    string isbn = generarISBN();

    Nodo *nuevo = new Nodo(autor, libro, fechaPublicacion, editorial, isbn);

    if (!cabeza)
    {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }
    else
    {
        Nodo *ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }

    cout << "Libro agregado correctamente. ISBN generado: " << isbn << endl;
}

void Lista::mostrarLista()
{
    if (!cabeza)
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        cout << "Autor: " << actual->autor
             << ", Libro: " << actual->libro
             << ", Fecha de Publicación: " << actual->fechaPublicacion
             << ", Editorial: " << actual->editorial
             << ", ISBN: " << actual->isbn << endl;
        actual = actual->siguiente;
    } while (actual != cabeza);
}

void Lista::buscarLibro(const string &libro)
{
    if (!cabeza)
    {
        cout << "La lista está vacía. No se puede buscar." << endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        if (actual->libro == libro)
        {
            cout << "Libro encontrado:" << endl;
            cout << "Autor: " << actual->autor << ", Libro: " << actual->libro
                 << ", Fecha de Publicación: " << actual->fechaPublicacion
                 << ", Editorial: " << actual->editorial << endl;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    cout << "Libro no encontrado." << endl;
}

void Lista::eliminarLibro(const string &libro)
{
    if (!cabeza)
    {
        cout << "La lista está vacía. No se puede eliminar." << endl;
        return;
    }

    Nodo *actual = cabeza;
    do
    {
        if (actual->libro == libro)
        {
            if (actual == cabeza && cabeza->siguiente == cabeza)
            {

                delete actual;
                cabeza = nullptr;
            }
            else
            {
                Nodo *anterior = actual->anterior;
                Nodo *siguiente = actual->siguiente;

                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;

                if (actual == cabeza)
                {
                    cabeza = siguiente;
                }

                delete actual;
            }

            cout << "Libro eliminado correctamente." << endl;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    cout << "Libro no encontrado. No se puede eliminar." << endl;
}
