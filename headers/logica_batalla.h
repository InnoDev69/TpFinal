#ifndef LOGICA_BATALLA_H
#define LOGICA_BATALLA_H

bool chequearRecursos(int soldados, int comida);
bool indicarFinBatalla(int batalla_actual);
bool confirmarContinuar(int &batalla_actual);
void mostrarRecursos(int oro, int comida, int soldados);
bool indicarUltBatalla(int batalla_actual);
bool chequearDerrotas(int batallas_perdidas);
void enviarSoldados(int& soldados_totales, int& soldados_actuales, int& comida);
void gestionarBatallaCompleta(int& oro, int& comida, int& soldados, int& batalla_actual, int& derrotas_totales, float& pasiva_probabilidad, int casa);

#endif