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

void funcionA(int n);
void funcionB(int n);

void funcionA(int n)
{
    if (n <= 0)
        return;
    cout << "A: " << n << " ";
    funcionB(n - 1); 
}

void funcionB(int n)
{
    if (n <= 0)
        return;
    cout << "B: " << n << " ";
    funcionA(n / 2); 
}

int main()
{
    funcionA(10);
    return 0;
}
