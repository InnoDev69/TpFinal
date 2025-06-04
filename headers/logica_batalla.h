#ifndef LOGICA_BATALLA_H
#define LOGICA_BATALLA_H

bool simular_ronda(int ronda, float prob_base, int& soldados_combate, int& soldados_totales);
bool ejecutar_batalla(int& oro, int& soldados, int& comida, int& derrotas_totales, 
                      float pasiva_probabilidad, int batalla_actual);

bool confirmar_batalla(int soldados, int comida, float pasiva_probabilidad);

#endif