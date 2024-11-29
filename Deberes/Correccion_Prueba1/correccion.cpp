/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Martin Alejandro Cordero Viteri
 * FECHA CREACION: Jueves,  28 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 28 de noviembre de 2024
 * Enunciado del problema: Correccion de la prueba
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void cifrar_palabras(vector<string> &lista, char objetivo, int desplazamiento)
{

    auto cifrar_cesar = [desplazamiento](char c) -> char
    {
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            return (c - base + desplazamiento) % 26 + base;
        }
        return c;
    };

    for (string &palabra : lista)
    {
        ::transform(palabra.begin(), palabra.end(), palabra.begin(),
                    [objetivo, &cifrar_cesar](char c)
                    {
                        return (c == objetivo) ? cifrar_cesar(c) : c;
                    });
    }
}

int main()
{

    vector<string> lista = {"ana", "lana", "ariana"};
    char objetivo = 'a';
    int desplazamiento = 3;

    cifrar_palabras(lista, objetivo, desplazamiento);

    for (const string &palabra : lista)
    {
        cout << palabra << ' ';
    }
    cout << endl;

    return 0;
}
