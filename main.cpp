#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL)); // Inicializar semilla para números aleatorios
    
    // Inicializacion de variables generales
    int presupuesto = 50000;
    int precio_soldados_m = 12500; // Precio por mil solados
    int precio_comida_m = 5000;    // Precio para alimentar mil soldados
    
    // Variables para la casa Targaryen
    int cantidad_soldados = 0;     // Cantidad total de soldados
    int comida_disponible = 0;     // Cantidad de comida disponible (en unidades de mil soldados)
    
    // Variables para la pasiva del dragón
    float prob_dragon_ataque = 0.10;         // Probabilidad base de que el dragón ataque (10%)
    float porcentaje_perdida_tropas = 0.15;  // Porcentaje de tropas perdidas por friendly fire (15%)
    int costo_mejora_pasiva = 25000;         // Costo para mejorar la probabilidad de ataque del dragón
    
    // Variables para la batalla
    int victorias = 0;
    int derrotas = 0;
    
    cout << "=== Casa Targaryen ===" << endl;
    cout << "Presupuesto inicial: " << presupuesto << endl;
    cout << "Precio por 1000 soldados: " << precio_soldados_m << endl;
    cout << "Precio para alimentar 1000 soldados: " << precio_comida_m << endl;
    cout << "Probabilidad de ataque de dragón: " << prob_dragon_ataque * 100 << "%" << endl;
    
    return 0;
}