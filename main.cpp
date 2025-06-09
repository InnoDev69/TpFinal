#include <iostream>
#include "./headers/constants.h"
#include "./headers/game_display.h"
#include "./headers/cuestions.h"
#include "./headers/logica_batalla.h"
#include "./headers/tienda.h"

using namespace std;

int main() {
    srand(time(NULL));
    int casa                    = elegir_casa(); // Elegir casa al inicio

    // Variables del estado del juego - locales al main
    int oro                     = DatosCasas[casa][oroInicial];
    int soldados                = 0;
    int comida                  = 0;
    int batalla_actual          = 0;
    int derrotas_totales        = 0;
    float pasiva_probabilidad   = DatosCasas[casa][valorPasiva];
    
    int opcion;
    while (true) {
        system("cls");
        mostrar_menu_principal(batalla_actual, oro, comida, soldados, pasiva_probabilidad);
        cin >> opcion;
        system("cls");
        
        switch (opcion) {
            case 1: // Batalla
                gestionarBatallaCompleta(oro, comida, soldados, batalla_actual, derrotas_totales, pasiva_probabilidad, casa);
                break;
                
            case 2: // Tienda
                procesar_tienda(oro, soldados, comida, pasiva_probabilidad, casa);
                break;
                
            case 3: // Salir
                cout << "¡Gracias por jugar!" << endl;
                return 0;
                
            default:
                cout << "Opción inválida" << endl;
                system("pause");
        }
    }
    
    return 0;
}