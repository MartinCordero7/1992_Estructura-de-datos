/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "matriz.h"

template <size_t N>
Matriz<N>::Matriz() {
    std::srand(std::time(0)); // Inicializa la semilla para los valores aleatorios
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            datos[i][j] = std::rand() % 1000; // Valor aleatorio entre 0 y 999
        }
    }
}

template <size_t N>
int Matriz<N>::getValor(int f, int c) const {
    return datos[f][c];
}

template <size_t N>
void Matriz<N>::imprimir() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << datos[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Instancia explícita del template para evitar errores de linkeo
template class Matriz<3>;
