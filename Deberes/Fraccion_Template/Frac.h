/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Sabado,  9 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 9 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa pe permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
using namespace std;

template <typename T>
class Fraccion
{
public:
    Fraccion(T num1, T den1, T num2, T den2);

    void sumar(T &num_res, T &den_res);
    void restar(T &num_res, T &den_res);
    void multiplicar(T &num_res, T &den_res);

private:
    T num1, den1;
    T num2, den2;

    void simplificar(T &num, T &den);
};

#endif
