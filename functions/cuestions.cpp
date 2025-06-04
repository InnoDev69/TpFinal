#include <iostream>
#include "../headers/cuestions.h"
#include "../headers/constants.h"
#include "../headers/game_display.h"
#include "../headers/utils.h"
using namespace std;

// Función para elegir la casa del jugador
int elegir_casa(){
    int casa;
    do{
        cout << "Elige tu casa (0-3):" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i << ". " << Casas[i] << endl;
        }
        cout << "Opción: ";
        cin >> casa;}while (siCasaExiste(casa) == -1);
    cout << "Has elegido la casa: " << Casas[casa] << endl;
    return casa; 
}
