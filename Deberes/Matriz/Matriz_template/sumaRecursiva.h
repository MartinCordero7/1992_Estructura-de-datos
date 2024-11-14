/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/#ifndef SUMARECURSIVA_H
#define SUMARECURSIVA_H

#include "matriz.h"

template <size_t N>
class SumaRecursiva {
public:
    static int suma(const Matriz<N>& mat1, const Matriz<N>& mat2, int f, int c);
};

template <size_t N>
int SumaRecursiva<N>::suma(const Matriz<N>& mat1, const Matriz<N>& mat2, int f, int c) {
    if (f == 0 && c == 0)
        return mat1.getValor(f, c) + mat2.getValor(f, c);

    int sumaActual = mat1.getValor(f, c) + mat2.getValor(f, c);
    if (c > 0)
        return sumaActual + SumaRecursiva<N>::suma(mat1, mat2, f, c - 1);
    else
        return sumaActual + SumaRecursiva<N>::suma(mat1, mat2, f - 1, N - 1);
}

#endif
