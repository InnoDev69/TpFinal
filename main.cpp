#include <iostream>
#include "./headers/constants.h"
#include "./headers/game_display.h"
#include "./headers/cuestions.h"
#include "./headers/logica_batalla.h"

using namespace std;

// Función para mostrar la tienda
void mostrar_tienda(int oro, int comida, int soldados, float pasiva_probabilidad, int casa) {
    mostrar_estado(0, oro, comida, soldados, pasiva_probabilidad); // batalla_actual no es relevante aquí
    cout << "TIENDA" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Soldados          $" << DatosCasas[casa][costoPorBatallon] << " x " << cantSoldadosPorBatallon << " unidades" << endl;
    cout << "2. Comida            $" << DatosCasas[casa][costoAlimBatallon]<< " x " << cantAlimentosPorBatallon << " unidades" << endl;
    cout << "3. Mejorar pasiva    $" << DatosCasas[casa][costoMejora] << " x +" << DatosCasas[casa][porcentajeMejora] << endl;
    cout << "4. Volver" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Opcion: ";
}

// Función para procesar compras en la tienda
// Función para procesar compras en la tienda
void procesar_tienda(int& oro, int& soldados, int& comida, float& pasiva_probabilidad, int casa) {
    int opcion;
    do {
        system("cls");
        mostrar_tienda(oro, comida, soldados, pasiva_probabilidad, casa);
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
                    pasiva_probabilidad += DatosCasas[casa][porcentajeMejora];
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
                float probVictoria;
                float probPerdida;
                for (int r=0; r<DURACION_GUERRA; r++)
                {    
                    probVictoria = PROB_INICIAL;
                    probPerdida = PROB_PERDIDA;
                    int soldadosActuales = soldados;
                    int soldadosCombate = min(soldados, comida); // Solo pueden combatir los que tienen comida
                    if (!chequearRecursos(soldados, comida) || !indicarFinBatalla(batalla_actual)) break;
                    
                    mostrarRecursos(oro, comida, soldados);
                    if (!confirmarContinuar(batalla_actual)) break;

                    if (indicarUltBatalla(batalla_actual)) break;

                    // Calcular probabilidad de victoria
                    float probBase = probPerdida - (batalla_actual * 0.05f);
                    float probSoldados = (soldadosCombate / SOLDADOS_PROBABILIDAD) * PROB_POR_SOLDADOS;
                    float probTotal = probBase + probSoldados + pasiva_probabilidad;
                    
                    // Aplicar pasiva Targaryen
                    if (casa == TARGARYEN) {
                        probTotal *= (1.0f + TARGARYEN_EFECTIVIDAD);
                    }

                    // Determinar victoria/derrota
                    bool victoria = (float)rand() / RAND_MAX < probTotal;
                    
                    // Calcular pérdidas
                    int perdidas = (soldadosCombate * batalla_actual * probPerdida / 100);
                    
                    // Aplicar pasiva Stark
                    if (casa == STARK) {
                        perdidas = perdidas * (1.0f - (STARK_REDUCCION_TROPAS * batalla_actual));
                    }
                    
                    // Consumir recursos
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

                    if (chequearDerrotas(derrotas_totales)) return 0;

                    probVictoria -= 0.05f;
                    probPerdida += 0.05f;

                    system("pause");}
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