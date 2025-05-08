#include <iostream>

using namespace std;

int main()
{
    /// (1) *************************************    INICIO DECLARACIÓN DE VARIABLES Y CONSTANTES  *************************************///
    /// JUGABILIDAD
    const int presupuesto_inicial = 50000;
    int oro = presupuesto_inicial;

    const int soldados_inicial = 0;
    int soldados = soldados_inicial;

    const int comida_inicial = 0;
    int comida = comida_inicial;

    const float pasiva_probabilidad_inicial = 0.5;
    float pasiva_probabilidad = pasiva_probabilidad_inicial;

    /// TIENDA
    const int valor_x_soldado       = 12500;
    const int valor_x_comida        = 5000;
    const int valor_x_mejora_pasiva = 25000;

    // articulo: objeto que se compra en la tienda, el valor refiere a la cantidad.
    const int articulo_soldados        = 1000;
    const int articulo_comida          = 500;
    const float articulo_mejora_pasiva = 0.1;

    /// BATALLA
    const int duracion_guerra = 5;
    int batalla_actual = 0;

    /// ESTADISTICAS
    const int batalla_cantidad_victorias = 0;
    const int batalla_cantidad_derrotas  = 0;
    const int total_gastado_oro          = 0;
    const int total_gastado_comida       = 0;
    const int total_gastado_soldados     = 0;
    const int total_ganado_oro           = 0;
    const int total_ganado_comida        = 0;
    const int total_ganado_soldados      = 0;

    /// Auxiliares
    int cin_opcion_menu;
    int cin_opcion_tienda;
    int cin_batalla_deseas_continuar;
    bool deseas_continuar;

    // Menu principal
    const int idx_opcion_menu_batalla = 1;
    const int idx_opcion_menu_tienda  = 2;
    const int idx_opcion_menu_volver  = 3;

    // Tienda
    const int idx_opcion_tienda_soldados      = 1;
    const int idx_opcion_tienda_comida        = 2;
    const int idx_opcion_tienda_mejora_pasiva = 3;
    const int idx_opcion_tienda_volver        = 4;
    /// (1) *************************************    FIN DECLARACIÓN DE VARIABLES Y CONSTANTES  *************************************///

    /// (2) -----------------------------------    INICIO MENÚ PRINCIPAL  -----------------------------------///
    while(true)
    {
        system("cls");

        cout << "---------------------------------------"               << endl;
        cout << "            Juego de Tronos            "               << endl;
        cout << "---------------------------------------"               << endl;
        cout << "~TARGARYEN "                                           << endl;
        cout << "|batallas realizadas : " << batalla_actual                  << endl;
        cout << "|presupuesto         : " << presupuesto_inicial             << endl;
        cout << "|oro                 : " << oro                             << endl;
        cout << "|comida              : " << comida                          << endl;
        cout << "|soldados            : " << soldados                        << endl;
        cout << "|pasiva              : " << pasiva_probabilidad             << endl;
        cout << "---------------------------------------"               << endl;
        cout << idx_opcion_menu_batalla << ". IR A LA BATALLA"          << endl;
        cout << idx_opcion_menu_tienda  << ". TIENDA"                   << endl;
        cout << idx_opcion_menu_volver  << ". SALIR" << endl;
        cout << "---------------------------------------"               << endl;
        cout << "OPCION: ";
        cin >> cin_opcion_menu;

        system("cls");
    /// (2) -----------------------------------    FIN MENÚ PRINCIPAL  -----------------------------------///

        /// (3) ***********************************  ESTRUCTURA DE SELECCIÓN DEL MENÚ Y LÓGICA DEL JUEGO    ***********************************///
        switch(cin_opcion_menu)
        {
        case idx_opcion_menu_batalla:
        {
            if (batalla_actual > duracion_guerra)
            {
                cout << "No hay mas batallas por luchar, puedes descansar!" << endl;

                cout << endl;

                cout << "Presiona cualquier tecla para volver al menu.";
                system("pause");
                break;
            }

            cout << "Soldados: "                << soldados            << endl;
            cout << "Comida: "                  << comida              << endl;
            cout << "Probabilidad  de pasiva: " << pasiva_probabilidad << endl;

            cout << endl;


            cout << "Deseas continuar? 1(SI) / 2(NO)" << endl;
            cout << "opcion: ";
            cin >> cin_batalla_deseas_continuar;

            if(cin_batalla_deseas_continuar == 2)
            {
                deseas_continuar=false;
            }
            else
            {
                deseas_continuar=true;
            }

            if (!deseas_continuar) //<--- SI ES FALSO EL VALOR DE DESEAS CONTINUAR
            {
                break;
            }

            system("cls");

            batalla_actual++;

            if (batalla_actual == duracion_guerra)
            {
                cout << "~~ ULTIMA BATALLA ~~" << endl;
                cout << endl;
            }

            cout << "Batalla NRO " << batalla_actual;

            cout << endl;

            cout << "Presiona cualquier tecla para volver al menu.";
            system("pause");

            break;
        }
        case idx_opcion_menu_tienda:
        {
            /// (4) -----------------------------------    MENÚ DE LA TIENDA  -----------------------------------///
            while(true)
            {
                if (cin_opcion_tienda == idx_opcion_tienda_volver)
                {
                    break;
                }

                system("cls");

                cout << "---------------------------------------" << endl;
                cout << "~LANNISTER"                              << endl;
                cout << "|presupuesto: " << presupuesto_inicial   << endl;
                cout << "|oro        : " << oro                   << endl;
                cout << "|comida     : " << comida                << endl;
                cout << "|soldados   : " << soldados              << endl;
                cout << "|pasiva     : " << pasiva_probabilidad   << endl;
                cout << "---------------------------------------" << endl;
                cout << "TIENDA" << endl;
                cout << "---------------------------------------" << endl;
                cout << "1. Soldados          $" << valor_x_soldado        << " x " << articulo_soldados        << " unidades." << endl;
                cout << "2. Comida            $" << valor_x_comida         << " x " << articulo_comida          << " unidades." << endl;
                cout << "3. Mejorar pasiva    $" << valor_x_mejora_pasiva  << " x +" << articulo_mejora_pasiva   << "." << endl;
                cout << "4. Volver al menu principal" << endl;
                cout << "---------------------------------------" << endl;
                cout << "Opcion: ";
                cin >> cin_opcion_tienda;

                system("cls");
            /// (4) -----------------------------------   FIN MENÚ DE LA TIENDA  -----------------------------------///

                /// (5) ***********************************  ESTRUCTURA DE SELECCIÓN DE LA TIENDA    ***********************************///
                switch(cin_opcion_tienda)
                {
                case idx_opcion_tienda_soldados:
                {
                    if (oro >= valor_x_soldado)
                    {
                        soldados += articulo_soldados;
                        oro -= valor_x_soldado;
                    }
                    else
                    {
                        cout << "No tienes oro suficiente!" << endl;

                        cout << endl;

                        cout << "Presiona cualquier tecla para volver al menu.";
                        system("pause");
                    }

                    break;
                }
                case idx_opcion_tienda_comida:
                {
                    if (oro >= valor_x_comida)
                    {
                        comida += articulo_comida;
                        oro -= valor_x_comida;
                    }
                    else
                    {
                        cout << "No tienes oro suficiente!" << endl;

                        cout << endl;

                        cout << "Presiona cualquier tecla para volver al menu.";
                        system("pause");
                    }

                    break;
                }
                case idx_opcion_tienda_mejora_pasiva:
                {
                    if (oro >= valor_x_mejora_pasiva)
                    {
                        pasiva_probabilidad += articulo_mejora_pasiva;
                        oro -= valor_x_mejora_pasiva;
                    }
                    else
                    {
                        cout << "No tienes oro suficiente!" << endl;

                        cout << endl;

                        cout << "Presiona cualquier tecla para volver al menu.";
                        system("pause");
                    }

                    break;
                }
                case idx_opcion_tienda_volver:
                default:
                {
                    break;
                }
                }
                /// (5) ***********************************  FIN ESTRUCTURA DE SELECCIÓN DE LA TIENDA    ***********************************///
            }

            break;
        }

        case idx_opcion_menu_volver:
        {
            return 0;                   //<---- SALIR DEL JUEGO
        }
        }
        /// (3) ***********************************  FIN ESTRUCTURA DE SELECCIÓN DEL MENÚ Y LÓGICA DEL JUEGO    ***********************************///
    }
}

