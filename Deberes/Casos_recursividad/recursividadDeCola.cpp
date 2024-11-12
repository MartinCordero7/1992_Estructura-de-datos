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

void cuentaRegresivaCola(int n)
{
    if (n <= 0)
        return;
    cout << n << " ";
    cuentaRegresivaCola(n - 1); 
}

int main()
{
    cuentaRegresivaCola(10);
    return 0;
}
