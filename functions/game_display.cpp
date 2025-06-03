#include "../headers/game_display.h"
#include <iostream>

using namespace std;

void mostrar_estado(int batalla_actual, int oro, int comida, int soldados, float pasiva_probabilidad) {
    cout << "---------------------------------------" << endl;
    cout << "Batalla actual: " << batalla_actual << endl;
    cout << "Oro: " << oro << endl;
    cout << "Comida: " << comida << endl;
    cout << "Soldados: " << soldados << endl;
    cout << "Probabilidad base: " << pasiva_probabilidad << endl;
    cout << "---------------------------------------" << endl;
}

// Función para mostrar el menú principal
void mostrar_menu_principal(int batalla_actual, int oro, int comida, int soldados, float pasiva_probabilidad) {
    mostrar_estado(batalla_actual, oro, comida, soldados, pasiva_probabilidad);
    cout << "1. IR A LA BATALLA" << endl;
    cout << "2. TIENDA" << endl;
    cout << "3. SALIR" << endl;
    cout << "---------------------------------------" << endl;
    cout << "OPCION: ";
}