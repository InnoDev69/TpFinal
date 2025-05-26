#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Constantes del juego
const int PRESUPUESTO_INICIAL = 50000;
const int DURACION_GUERRA = 5;
const int MAX_DERROTAS = 4;
const int RONDAS_POR_BATALLA = 10;
const float PROB_INICIAL = 0.5f;

// Constantes de tienda
const int PRECIO_SOLDADOS = 12500;
const int PRECIO_COMIDA = 5000;
const int PRECIO_MEJORA = 25000;
const int CANT_SOLDADOS = 1000;
const int CANT_COMIDA = 1000;
const float MEJORA_PASIVA = 0.1f;

// Función para mostrar el estado actual del juego
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

// Función para mostrar el menú principal
void mostrar_menu_principal(int batalla_actual, int oro, int comida, int soldados, float pasiva_probabilidad) {
    mostrar_estado(batalla_actual, oro, comida, soldados, pasiva_probabilidad);
    cout << "1. IR A LA BATALLA" << endl;
    cout << "2. TIENDA" << endl;
    cout << "3. SALIR" << endl;
    cout << "---------------------------------------" << endl;
    cout << "OPCION: ";
}

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

// Función para mostrar la tienda
void mostrar_tienda(int oro, int comida, int soldados, float pasiva_probabilidad) {
    mostrar_estado(0, oro, comida, soldados, pasiva_probabilidad); // batalla_actual no es relevante aquí
    cout << "TIENDA" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Soldados          $" << PRECIO_SOLDADOS << " x " << CANT_SOLDADOS << " unidades" << endl;
    cout << "2. Comida            $" << PRECIO_COMIDA << " x " << CANT_COMIDA << " unidades" << endl;
    cout << "3. Mejorar pasiva    $" << PRECIO_MEJORA << " x +" << MEJORA_PASIVA << endl;
    cout << "4. Volver" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Opcion: ";
}

// Función para procesar compras en la tienda
void procesar_tienda(int& oro, int& soldados, int& comida, float& pasiva_probabilidad) {
    int opcion;
    do {
        system("cls");
        mostrar_tienda(oro, comida, soldados, pasiva_probabilidad);
        cin >> opcion;
        system("cls");
        
        switch (opcion) {
            case 1: // Soldados
                if (oro >= PRECIO_SOLDADOS) {
                    oro -= PRECIO_SOLDADOS;
                    soldados += CANT_SOLDADOS;
                    cout << "¡Soldados comprados!" << endl;
                } else {
                    cout << "¡No tienes oro suficiente!" << endl;
                }
                break;
                
            case 2: // Comida
                if (oro >= PRECIO_COMIDA) {
                    oro -= PRECIO_COMIDA;
                    comida += CANT_COMIDA;
                    cout << "¡Comida comprada!" << endl;
                } else {
                    cout << "¡No tienes oro suficiente!" << endl;
                }
                break;
                
            case 3: // Mejora pasiva
                if (oro >= PRECIO_MEJORA) {
                    oro -= PRECIO_MEJORA;
                    pasiva_probabilidad += MEJORA_PASIVA;
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
    
    // Variables del estado del juego - locales al main
    int oro = PRESUPUESTO_INICIAL;
    int soldados = 0;
    int comida = 0;
    float pasiva_probabilidad = PROB_INICIAL;
    int batalla_actual = 0;
    int derrotas_totales = 0;
    
    int opcion;
    while (true) {
        system("cls");
        mostrar_menu_principal(batalla_actual, oro, comida, soldados, pasiva_probabilidad);
        cin >> opcion;
        system("cls");
        
        switch (opcion) {
            case 1: // Batalla
                if (batalla_actual >= DURACION_GUERRA) {
                    cout << "¡No hay más batallas! Has completado la guerra." << endl;
                    system("pause");
                    break;
                }
                
                if (confirmar_batalla(soldados, comida, pasiva_probabilidad)) {
                    if (ejecutar_batalla(oro, soldados, comida, derrotas_totales, 
                                       pasiva_probabilidad, batalla_actual)) {
                        batalla_actual++; // Solo incrementar si no hubo error
                    }
                    
                    if (derrotas_totales >= MAX_DERROTAS) {
                        cout << "\n¡GAME OVER! Los White Walkers han conquistado Targaryen." << endl;
                        system("pause");
                        return 0;
                    }
                    
                    system("pause");
                }
                break;
                
            case 2: // Tienda
                procesar_tienda(oro, soldados, comida, pasiva_probabilidad);
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