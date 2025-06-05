#include <iostream>
#include "../headers/utils.h"
#include "../headers/constants.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool chequearRecursos(int soldados, int comida){
    if (soldados <= 0 || comida <= 0) {
        cout << "¡No tienes suficientes recursos para continuar la batalla!" << endl;
        cout << "Soldados: " << soldados << ", Comida: " << comida << endl;
        system("pause");
        return false;
    }else return true;  
}

bool indicarFinBatalla(int batalla_actual){
    if (batalla_actual >= DURACION_GUERRA) {
        cout << "¡Has alcanzado el final de la guerra!" << endl;
        cout << "Preciona cualquier tecla para volver" << endl;
        system("pause");
        return true;
    }
    return false;
}

bool confirmarContinuar(int &batalla_actual){
    char respuesta;
    cout << "¿Deseas continuar con la batalla? (s/n): ";
    cin >> respuesta;
    if (respuesta == 'n' || respuesta == 'N') {
        cout << "Batalla cancelada." << endl;
        return false;
    }
    batalla_actual++;
    return true;
}

void mostrarRecursos(int oro, int comida, int soldados) {
    cout << "Recursos actuales:" << endl;
    cout << "Oro: " << oro << endl;
    cout << "Comida: " << comida << endl;
    cout << "Soldados: " << soldados << endl;
}

bool indicarUltBatalla(int batalla_actual) {
    if (batalla_actual == DURACION_GUERRA) {
        cout << "¡Esta es tu última batalla!" << endl;
        cout << "Preciona cualquier tecla para continuar" << endl;
        system("pause");
        return true;
    }
    return false;
}

bool chequearDerrotas(int batallas_perdidas) {
    if (batallas_perdidas >= MAX_DERROTAS) {
        cout << "¡Has alcanzado el máximo de derrotas permitidas!" << endl;
        cout << "Preciona cualquier tecla para salir" << endl;
        system("pause");
        return true;
    }
    return false;
}

void mostrarSoldadosEnviados(int soldados_actuales) {
    cout << "Soldados enviados a la batalla: " << soldados_actuales << endl;
}

void enviarSoldados(int& soldados_totales, int& soldados_actuales, int& comida) {
    if (comida <= soldados_totales){
        soldados_actuales = comida;
        soldados_totales -= soldados_actuales;
        comida = 0;
    }else comida -= soldados_actuales;
    mostrarSoldadosEnviados(soldados_actuales);
}

