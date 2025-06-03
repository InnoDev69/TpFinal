#include "../data/game_display.h"
#include <iostream>

void mostrar_estado(int batalla_actual, int oro, int comida, int soldados, float pasiva_probabilidad) {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Batalla actual: " << batalla_actual << std::endl;
    std::cout << "Oro: " << oro << std::endl;
    std::cout << "Comida: " << comida << std::endl;
    std::cout << "Soldados: " << soldados << std::endl;
    std::cout << "Probabilidad base: " << pasiva_probabilidad << std::endl;
    std::cout << "---------------------------------------" << std::endl;
}