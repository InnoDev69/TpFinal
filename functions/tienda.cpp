#include <iostream>
#include "../headers/tienda.h"
#include "../headers/constants.h"
#include "../headers/cuestions.h"
#include "../headers/logica_batalla.h"
#include "../headers/game_display.h"
#include "../headers/utils.h"

using namespace std;

// Función para mostrar la tienda
void mostrar_tienda(int oro, int comida, int soldados, float probabilidad_habilidad, int casa) {
    mostrar_estado(0, oro, comida, soldados, probabilidad_habilidad);
    cout << "TIENDA" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Soldados          $" << DatosCasas[casa][costoPorBatallon] << " x " << cantSoldadosPorBatallon << " unidades" << endl;
    cout << "2. Comida            $" << DatosCasas[casa][costoAlimBatallon]<< " x " << cantAlimentosPorBatallon << " unidades" << endl;
    cout << "3. Mejorar habilidad    $" << DatosCasas[casa][costoMejora] << " x +" << decimalAPorcentaje(DatosCasas[casa][porcentajeMejora]) << endl;
    cout << "4. Volver" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Opcion: ";
}

// Función para procesar compras en la tienda
void procesar_tienda(int& oro, int& soldados, int& comida, float& probabilidad_habilidad, int casa) {
    int opcion;
    do {
        system("cls");
        mostrar_tienda(oro, comida, soldados, probabilidad_habilidad, casa);
        cin >> opcion;
        system("cls");
        
        switch (opcion) {
            case 1: // Soldados
                if (oro >= DatosCasas[casa][costoPorBatallon]) {
                    oro -= DatosCasas[casa][costoPorBatallon];
                    soldados += cantSoldadosPorBatallon;
                    cout << "¡Soldados comprados!" << endl;
                } else {
                    cout << "¡No tienes oro suficiente!" << endl;
                }
                break;
                
            case 2: // Comida
                if (oro >= DatosCasas[casa][costoAlimBatallon]) {
                    oro -= DatosCasas[casa][costoAlimBatallon];
                    comida += cantAlimentosPorBatallon;
                    cout << "¡Comida comprada!" << endl;
                } else {
                    cout << "¡No tienes oro suficiente!" << endl;
                }
                break;
                
            case 3: // Mejora pasiva
                if (oro >= DatosCasas[casa][costoMejora]) {
                    oro -= DatosCasas[casa][costoMejora];
                    probabilidad_habilidad += DatosCasas[casa][porcentajeMejora];
                    cout << "¡Pasiva mejorada!" << endl;
                } else {
                    cout << "¡No tienes oro suficiente!" << endl;
                }
                break;
                
            case 4: // Volver
                return;
                
            default:
                cout << "Opción inválida" << endl;
        }
        
        if (opcion != 4) {
            system("pause");
        }
    } while (opcion != 4);
}