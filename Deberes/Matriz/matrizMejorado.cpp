/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX 3 // Puedes reemplazarlo con una constante en tiempo de compilación si deseas flexibilidad

using namespace std;

int sumaRecursivaMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int f, int c)
{
    if (f == 0 && c == 0)
        return mat1[f][c] + mat2[f][c];

    // Cálculo de la posición actual y movimiento a la siguiente celda
    int suma = mat1[f][c] + mat2[f][c];
    if (c > 0)
        return suma + sumaRecursivaMatrices(mat1, mat2, f, c - 1);
    else
        return suma + sumaRecursivaMatrices(mat1, mat2, f - 1, MAX - 1);
}

int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX];
    srand(time(0));

    // Inicialización de las matrices con valores aleatorios entre 0 y 999
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            mat1[i][j] = rand() % 1000;
            mat2[i][j] = rand() % 1000;
        }
    }

    // Imprimir la primera matriz
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // Imprimir la segunda matriz
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    // Calcular la suma total usando la función recursiva
    cout << "Suma de Matrices es: " << sumaRecursivaMatrices(mat1, mat2, MAX - 1, MAX - 1) << endl;

    return 0;
}
