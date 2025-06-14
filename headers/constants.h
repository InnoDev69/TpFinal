#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
using namespace std;

// Constantes del juego
const int PRESUPUESTO_INICIAL       = 50000;
const int DURACION_GUERRA           = 10;
const int MAX_DERROTAS              = 4;
const float PROB_INICIAL            = 0.5f;
const float PROB_PERDIDA            = 0.05f;
const int cantSoldadosPorBatallon   = 10000;
const int cantAlimentosPorBatallon  = 10000;
const int oroPorRonda               = 15000;

// Índices de la matriz de datos
const int oroInicial        = 0;
const int costoPorBatallon  = 1;
const int costoAlimBatallon = 2;
const int chancHabilidad    = 3;
const int habilidad         = 4;
const int costoMejora       = 5;
const int porcentajeMejora  = 6;
const int valorPasiva       = 7;

// Indices de las casas
const int LANNISTER = 0;
const int STARK     = 1;
const int TARGARYEN = 2;
const int BARATHEON = 3;

// Matriz de casas
const string Casas[4] = {
    "LANNISTER",
    "STARK", 
    "TARGARYEN", 
    "BARATHEON"  
};

// Matriz de datos
const float DatosCasas[4][8] = {
    //oroInicial, costoPorBatallon, costoAlimBatallon, chancHabilidad, habilidad, costoMejora, porcentajeMejora, valorPasiva}
    {75000, 10000, 5000, 0.15f, 0.30f, 10000, 0.5f , 0.30f},   //LANNISTER
    {50000, 8500 , 5000, 0.30f, 0.20f, 8500 , 0.5f , 0.1f},    //STARK
    {60000, 12500, 5000, 0.10f, 0.20f, 25000, 0.10f, 0.35f},   //TARGARYEN
    {50000, 10000, 3000, 0.5f , 2    , 5000 , 0.5f , 0.30f},   //BARATHEON
};

// Constantes específicas para efectos de las casas
const float LANNISTER_ORO_EXTRA = 0.10f;        // 10% del promedio de oro por soldado
const float STARK_REDUCCION_TROPAS = 0.01f;     // 1% menos pérdidas por ronda
const float TARGARYEN_EFECTIVIDAD = 0.35f;      // 35% más efectividad en probabilidad
const float TARGARYEN_PERDIDA_DRAGON = 0.20f;  // 20% pérdida por dragón
const float BARATHEON_RESCATE_COMIDA = 0.30f;   // 30% recuperación de comida
const float BARATHEON_REDUCCION_COMIDA = 0.50f;// 50% menos consumo

// Agregar estas constantes
const float SOLDADOS_PROBABILIDAD = 6500;  // Soldados necesarios para +10% probabilidad
const float PROB_POR_SOLDADOS = 0.10f;     // +10% por cada 6500 soldados
const int ORO_BASE_RONDA = 15000;          // Oro base que aumenta por ronda

#endif