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

void cuentaRegresiva(int n)
{
    if (n <= 0)
        return; 
    cout << n << " ";
    cuentaRegresiva(n - 1); 
}

int main()
{
    cuentaRegresiva(5);
    return 0;
}
