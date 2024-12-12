#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
  string autor;
  string libro;
  string fechaPublicacion;
  string editorial;
  string isbn;
  Nodo *siguiente;
  Nodo *anterior;

  Nodo(string a, string l, string f, string e, string i)
      : autor(a), libro(l), fechaPublicacion(f), editorial(e), isbn(i),
        siguiente(nullptr), anterior(nullptr) {}
};

#endif
