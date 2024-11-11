/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Sabado,  9 de noviembre de 2024
 * FECHA MODIFICACION: Sabado, 9 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa pe permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
#include "Frac.cpp"
#include <cstdio>
using namespace std;

int main()
{
    int num1, den1, num2, den2;
    int num_res, den_res;

    printf("Ingrese el numerador de la primera fraccion: ");
    scanf("%d", &num1);
    printf("Ingrese el denominador de la primera fraccion: ");
    scanf("%d", &den1);

    printf("Ingrese el numerador de la segunda fraccion: ");
    scanf("%d", &num2);
    printf("Ingrese el denominador de la segunda fraccion: ");
    scanf("%d", &den2);

    Fraccion<int> fraccionCalc(num1, den1, num2, den2);

    fraccionCalc.sumar(num_res, den_res);
    printf("Suma: %d/%d\n", num_res, den_res);

    fraccionCalc.restar(num_res, den_res);
    printf("Resta: %d/%d\n", num_res, den_res);

    fraccionCalc.multiplicar(num_res, den_res);
    printf("Multiplicacion: %d/%d\n", num_res, den_res);

    fraccionCalc.dividir(num_res, den_res);
    printf("Division: %d/%d\n", num_res, den_res);

    return 0;
}
