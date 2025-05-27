#include <iostream>
#include "data/game_display.h"
#include "data/constants.h"

using namespace std;

void mostrar_estado(int batalla_actual, int oro, int comida, int soldados, float pasiva_probabilidad) {
    cout << "---------------------------------------" << endl;
    cout << "            Juego de Tronos            " << endl;
    cout << "---------------------------------------" << endl;
    cout << "~TARGARYEN" << endl;
    cout << "|Batallas realizadas : " << batalla_actual << endl;
    cout << "|Presupuesto         : " << PRESUPUESTO_INICIAL << endl;
    cout << "|Oro                 : " << oro << endl;
    cout << "|Comida              : " << comida << endl;
    cout << "|Soldados            : " << soldados << endl;
    cout << "|Pasiva              : " << pasiva_probabilidad << endl;
    cout << "---------------------------------------" << endl;
}