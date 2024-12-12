#ifndef LISTA_H
#define LISTA_H

#include "Node.h"

class Lista
{
private:
    Nodo *cabeza;

    string generarISBN();

public:
    Lista();
    ~Lista();
    void agregarNodo(const string &autor, const string &libro, const string &fechaPublicacion, const string &editorial);
    void mostrarLista();
    void buscarLibro(const string &libro);
    void eliminarLibro(const string &libro);
    void crearBackup(const string &nombreArchivo);
    void restaurarBackup(const string &nombreArchivo);
    void eliminarTodosLosLibros();
};

#endif
