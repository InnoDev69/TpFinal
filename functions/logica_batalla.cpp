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

void gestionarBatallaCompleta(int& oro, int& comida, int& soldados, int& batalla_actual, int& derrotas_totales, float& pasiva_probabilidad, int casa) {
    float probVictoria;
    float probPerdida;
    for (int r=batalla_actual; r<DURACION_GUERRA; r++)
    {   
        if (!chequearRecursos(soldados, comida) || indicarFinBatalla(batalla_actual)) break;

        probVictoria = PROB_INICIAL;
        probPerdida = PROB_PERDIDA;
        int soldadosActuales = soldados;
        int soldadosCombate = obtenerMinimo(soldados, comida); // Solo pueden combatir los que tienen comida
        
        mostrarRecursos(oro, comida, soldados);
        if (!confirmarContinuar(batalla_actual)) break;

        if (indicarUltBatalla(batalla_actual)) break;

        // Calcula la probabilidad de victoria
        float probBase = probPerdida - (batalla_actual * 0.05f);
        float probSoldados = (soldadosCombate / SOLDADOS_PROBABILIDAD) * PROB_POR_SOLDADOS;
        float probTotal = probBase + probSoldados + pasiva_probabilidad;
        
        // Aplica la pasivaa a la casa Targaryen
        if (casa == TARGARYEN) probTotal *= (1.0f + TARGARYEN_EFECTIVIDAD);

        // Determina si es victoria/derrota
        bool victoria = (float)rand() / RAND_MAX < probTotal;
        
        // Calcular pérdidas
        int perdidas = (soldadosCombate * batalla_actual * probPerdida / 100);
        
        // Aplica la pasiva a la casa Stark
        if (casa == STARK) perdidas = perdidas * (1.0f - (STARK_REDUCCION_TROPAS * batalla_actual));
        
        // Consume recursos
        soldados -= perdidas;
        int comidaConsumida = soldadosCombate;
        comida -= comidaConsumida;

        if (victoria) {
            // Recompensas por victoria
            int oroGanado = ORO_BASE_RONDA + (batalla_actual * 5000);
            
            // Pasiva Lannister - recuperar oro basado en soldados
            if (casa == LANNISTER) {
                int oroPromedioSoldado = (DatosCasas[casa][costoPorBatallon] / cantSoldadosPorBatallon);
                oroGanado += (oroPromedioSoldado * soldadosCombate * LANNISTER_ORO_EXTRA);
            }
            
            oro += oroGanado;
            
            // Pasiva Baratheon - recuperar comida
            if (casa == BARATHEON) {
                int comidaRecuperada = comidaConsumida * BARATHEON_RESCATE_COMIDA;
                comida += comidaRecuperada;
                cout << "¡Comida recuperada: " << comidaRecuperada << "!" << endl;
            }
            
            cout << "¡Victoria! Oro ganado: " << oroGanado << endl;
        } else {
            derrotas_totales++;
            cout << "Derrota... Derrotas totales: " << derrotas_totales << endl;
        }

        if (chequearDerrotas(derrotas_totales)) return;

        probVictoria -= 0.05f;
        probPerdida += 0.05f;

        system("pause");}
}