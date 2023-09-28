
#include "Menu.hpp"
#include <fstream>
#include <iostream>
#include "inventario.cpp"

void Menu::ejecutar_inventario() {
    Inventario inventario{};
    inventario.cargar_archivo();
    cout<<"si quiere salir del inventario ponga la palabra 'salir'"<<endl;
    string accion;
    do{
        accion = preguntar_accion();
        if(accion == "alta"){
            Item * item = introducir_item_para_alta();
            inventario.alta(item);
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
    cout<<"aca ESTA EL ERROR";
    inventario.escribir_archivo();
}

Item* Menu::introducir_item_para_alta() {
    string nombre;
    string tipo;
    cout<<"Nombre del item: "<<endl;
    getline(cin,nombre);
    cout<<"Tipo del item: "<<endl;
    getline(cin,tipo);
    Item *item = new Item(nombre,tipo);
    return item;
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
