/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Miercoles,  6 de noviembre de 2024
 * FECHA MODIFICACION: Miercoles, 6 de noviembre de 2024
 * Enunciado del problema: Crear las funciones para ingresar entero, flotante, string double
 * depende de lo que pida y de acuerdo a la necesidad se hace el casting.
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int ingresar(const char *msj, int)

{
    printf("%s", msj);
    char cad[20], c;
    int i = 0;
    while ((c = getch()) != 13)
    {
        if (c >= '0' && c <= '9')
        {
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    return atoi(cad);
}

float ingresar(const char *msj, float)
{
    printf("%s", msj);
    char cad[20], c;
    int i = 0;
    bool hasDot = false;
    while ((c = getch()) != 13)
    {
        if ((c >= '0' && c <= '9') || (c == '.' && !hasDot))
        {
            printf("%c", c);
            if (c == '.')
                hasDot = true;
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    return atof(cad);
}

double ingresar(const char *msj, double)
{
    printf("%s", msj);
    char cad[20], c;
    int i = 0;
    bool hasDot = false;
    while ((c = getch()) != 13)
    {
        if ((c >= '0' && c <= '9') || (c == '.' && !hasDot))
        {
            printf("%c", c);
            if (c == '.')
                hasDot = true;
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    return strtod(cad, nullptr);
}

void ingresar(const char *msj, char *str, int size)
{
    printf("%s", msj);
    char c;
    int i = 0;
    while ((c = getch()) != 13 && i < size - 1)
    {
        if (isprint(c))
        {
            printf("%c", c);
            str[i++] = c;
        }
    }
    str[i] = '\0';
}

int main()
{
    int entero = ingresar("Ingrese un valor entero: ", 0);
    printf("\nValor entero ingresado: %d\n", entero);

    float flotante = ingresar("Ingrese un valor flotante: ", 0.0f);
    printf("\nValor flotante ingresado: %.2f\n", flotante);

    double doble = ingresar("Ingrese un valor doble: ", 0.0);
    printf("\nValor doble ingresado: %.5lf\n", doble);

    char cadena[50];
    ingresar("Ingrese una cadena de caracteres: ", cadena, 50);
    printf("\nCadena ingresada: %s\n", cadena);

    return 0;
}