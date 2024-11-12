/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Lunes,  11 de noviembre de 2024
 * FECHA MODIFICACION: Lunes, 11 de noviembre de 2024
 * Enunciado del problema: Crear un ejemplo con cada tipo de recursividad
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
using namespace std;

bool esPar(int n);
bool esImpar(int n);

bool esPar(int n)
{
    if (n == 0)
        return true;
    return esImpar(n - 1); 
}

bool esImpar(int n)
{
    if (n == 0)
        return false;
    return esPar(n - 1); 
}

int main()
{
    int numero = 5;
    if (esPar(numero))
        cout << numero << " es par";
    else
        cout << numero << " es impar";
    return 0;
}
