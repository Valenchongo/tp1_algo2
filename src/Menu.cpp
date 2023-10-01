
#include "../include/Menu.hpp"
#include "../include/Inventario.h"
#include <fstream>
#include <iostream>


void Menu::ejecutar_inventario() {
    Inventario inventario{};
    inventario.cargar_archivo();
    cout<<"si quiere salir del inventario ponga la palabra 'salir'"<<endl;
    string accion;
    do{
        accion = preguntar_accion();
        if(accion == "alta"){
            introducir_item_para_alta(inventario);
        }else if (accion == "baja"){
            string nombre_item = introducir_item_para_baja();
            inventario.baja(nombre_item);
        }else if(accion == "consulta"){
            inventario.consulta();
        }
        else if (accion != "salir"){
            cout<<"la accion '"<<accion<<"' no existe"<<endl;
        }
    }while(accion != "salir");
    inventario.escribir_archivo();
}

void Menu::introducir_item_para_alta(Inventario &inventario) {
    string nombre;
    string tipo;
    cout<<"Nombre del item: ";
    getline(cin,nombre);
    cout<<"Tipo del item: ";
    getline(cin,tipo);
    verificar_item_correcto(inventario,nombre,tipo);
}

void Menu::verificar_item_correcto(Inventario &inventario, string nombre, string tipo) {
    if(tipo == TIPO_MUNICION || tipo == TIPO_CURATIVO || tipo == TIPO_PUZZLE){
        Item* item = new Item(nombre,tipo);
        inventario.alta(item);
    }
    else{
        cout<<"el tipo '"<<tipo<<"' no existe..."<<endl;
    }
}

string Menu::introducir_item_para_baja() {
    string nombre;
    cout<<"indique el item a eliminar: ";
    getline(cin,nombre);
    return nombre;
}
string Menu::preguntar_accion() {
    string accion;
    cout<<"Accion sobre el inventario: ";
    getline(cin,accion);
    return accion;
}
