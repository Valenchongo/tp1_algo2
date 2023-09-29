//
// Created by Valentin Valle on 9/26/2023.
//

#ifndef AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
#define AYP2_PLANTILLA_TP1_2C2023_MENU_HPP

#include <string>
#include <iostream>
#include "Item.hpp"


using namespace std;

class Menu {
private:
    static string preguntar_accion();

public:

    static void ejecutar_inventario();

    static Item* introducir_item_para_alta();

    static string introducir_item_para_baja();

};


#endif //AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
