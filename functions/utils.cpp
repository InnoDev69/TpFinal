#include <iostream>
#include <string>
#include "../headers/utils.h"
#include "../headers/constants.h"
using namespace std;

int siCasaExiste(int casa) {
    if (casa < 0 || casa >= 4) {
        cout << "Casa no válida. Elige una casa entre 0 y 3." << endl;
        return -1; // Indica error
    }
    return casa; // Casa valida
}

int obtenerMinimo(int a, int b) {
    /*
    1. Usa el operador ternario (condición ? valor_si_verdadero : valor_si_falso)
    2. Si a < b es verdadero, retorna a
    3. Si a < b es falso, retorna b
    */
    return (a < b) ? a : b;
}

string decimalAPorcentaje(float valor) {
    return to_string(int(valor * 100)) + "%";
}