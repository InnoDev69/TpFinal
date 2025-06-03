#include <iostream>
#include "../headers/game_logic.h"
#include "../headers/constants.h"
#include "../headers/game_display.h"
using namespace std;
// Función para confirmar si el jugador quiere ir a batalla
bool confirmar_batalla(int soldados, int comida, float pasiva_probabilidad) {
    cout << "Estado actual:" << endl;
    cout << "Soldados: " << soldados << endl;
    cout << "Comida: " << comida << endl;
    cout << "Probabilidad base: " << pasiva_probabilidad << endl << endl;
    
    int respuesta;
    cout << "¿Deseas continuar? 1(SI) / 2(NO): ";
    cin >> respuesta;
    return respuesta == 1;
}