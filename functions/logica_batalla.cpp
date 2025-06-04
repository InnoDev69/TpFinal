#include <iostream>
#include "../headers/utils.h"
#include "../headers/constants.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Verifica si hay recursos suficientes para la batalla
// Función para simular una ronda de batalla
bool simular_ronda(int ronda, float prob_base, int& soldados_combate, int& soldados_totales) {
    cout << "\nRonda " << ronda << "..." << endl;
    
    float dificultad = 1.0f + (ronda * 0.05f);
    float prob_victoria = prob_base / dificultad;
    
    bool victoria = (float)rand() / RAND_MAX < prob_victoria;
    cout << (victoria ? "¡Victoria!" : "Derrota...") << endl;
    
    int perdidas = (soldados_combate * ronda * 5) / 100;
    soldados_combate -= perdidas;
    soldados_totales -= perdidas;
    
    cout << "Soldados perdidos: " << perdidas << endl;
    cout << "Soldados restantes: " << soldados_totales << endl;
    
    return victoria;
}

// Función principal de batalla - retorna si ganó y modifica oro, soldados, comida, derrotas
bool ejecutar_batalla(int& oro, int& soldados, int& comida, int& derrotas_totales, 
                     float pasiva_probabilidad, int batalla_actual) {
    
    int soldados_combate = min(soldados, comida);
    if (soldados_combate <= 0) {
        cout << "¡No tienes suficientes soldados o comida!" << endl;
        derrotas_totales++;
        return false;
    }
    
    if (batalla_actual == DURACION_GUERRA) {
        cout << "~~ BATALLA FINAL ~~" << endl;
    }
    cout << "Batalla número: " << batalla_actual + 1 << endl;
    cout << "Soldados en combate: " << soldados_combate << endl;
    
    float prob_total = pasiva_probabilidad + (soldados_combate / 1000.0f) * 0.15f;
    
    int victorias = 0;
    int soldados_temp = soldados;
    for (int ronda = 1; ronda <= RONDAS_POR_BATALLA; ronda++) {
        if (simular_ronda(ronda, prob_total, soldados_combate, soldados_temp)) {
            victorias++;
        }
    }
    
    soldados = soldados_temp; // Aplicar pérdidas
    bool victoria = victorias > RONDAS_POR_BATALLA / 2;
    
    if (victoria) {
        int oro_ganado = 10000 + (batalla_actual + 1) * 5000;
        oro += oro_ganado;
        cout << "\n¡VICTORIA EN LA BATALLA!" << endl;
        cout << "Oro ganado: " << oro_ganado << endl;
    } else {
        cout << "\nDerrota en la batalla..." << endl;
        derrotas_totales++;
    }
    
    // Consumir comida
    comida = max(0, comida - min(soldados_combate, comida));
    return victoria;
}
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