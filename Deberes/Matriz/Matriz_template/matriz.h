/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib>
#include <ctime>

template <size_t N>
class Matriz {
public:
    Matriz(); // Constructor
    int getValor(int f, int c) const; // Obtener el valor en una posición
    void imprimir() const; // Imprimir la matriz

private:
    int datos[N][N];
};

#endif
