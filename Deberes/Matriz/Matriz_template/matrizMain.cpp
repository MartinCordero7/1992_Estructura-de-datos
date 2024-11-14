/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
#include "matriz.h"
#include "sumaRecursiva.h"
#include "matrix.cpp"

int main() {
    const int N = 3;
    Matriz<N> mat1;
    Matriz<N> mat2;

    std::cout << "Matriz 1:" << std::endl;
    mat1.imprimir();

    std::cout << "\nMatriz 2:" << std::endl;
    mat2.imprimir();

    // Suma recursiva de las matrices
    int sumaTotal = SumaRecursiva<N>::suma(mat1, mat2, N - 1, N - 1);
    std::cout << "\nSuma de Matrices es: " << sumaTotal << std::endl;

    return 0;
}
