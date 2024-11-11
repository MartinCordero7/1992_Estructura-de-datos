/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Sabado,  9 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 9 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa pe permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include "Frac.h"

template <typename T>
T gcd(T a, T b)
{
    while (b != 0)
    {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

template <typename T>
Fraccion<T>::Fraccion(T num1, T den1, T num2, T den2) : num1(num1), den1(den1), num2(num2), den2(den2)
{
    if (den1 == 0 || den2 == 0)
    {
        cerr << "Error: el denominador no puede ser cero." << endl;
        den1 = den1 == 0 ? 1 : den1;
        den2 = den2 == 0 ? 1 : den2;
    }
}

template <typename T>
void Fraccion<T>::simplificar(T &num, T &den)
{
    T divisor = gcd(num, den);
    num /= divisor;
    den /= divisor;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

template <typename T>
void Fraccion<T>::sumar(T &num_res, T &den_res)
{
    num_res = num1 * den2 + num2 * den1;
    den_res = den1 * den2;
    simplificar(num_res, den_res);
}

template <typename T>
void Fraccion<T>::restar(T &num_res, T &den_res)
{
    num_res = num1 * den2 - num2 * den1;
    den_res = den1 * den2;
    simplificar(num_res, den_res);
}

template <typename T>
void Fraccion<T>::multiplicar(T &num_res, T &den_res)
{
    num_res = num1 * num2;
    den_res = den1 * den2;
    simplificar(num_res, den_res);
}
template <typename T>
void Fraccion<T>::dividir(T &num_res, T &den_res)
{
    num_res = num1 / num2;
    den_res = den1 / den2;
    simplificar(num_res, den_res);
}

template class Fraccion<int>;
