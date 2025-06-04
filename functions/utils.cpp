#include <iostream>
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

bool iniciar_ronda(int ronda, float prob_base, int& soldados_combate, int& soldados_totales) {
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
