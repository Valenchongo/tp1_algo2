#include "../include/Vector.hpp"
#include <string>
#include <iostream>
using namespace std;


Vector::Vector() {
    this->tamanioMaximo = 5;
    this->cantidadDatos = 0;
    this->datos = new Item*[tamanioMaximo];
}

void Vector::redimensionar_agrandar(Item *dato) {
    tamanioMaximo += 5;
    Item** aux = new Item*[tamanioMaximo];
    for (size_t i = 0; i < cantidadDatos; i++){
        aux[i] = datos[i];
    }
    delete[] datos;
    aux[cantidadDatos] = dato;
    datos = aux;
}

void Vector::redimensionar_achicar() {
    tamanioMaximo -= 5;
    Item** aux = new Item*[tamanioMaximo];
    for (size_t i = 0; i < cantidadDatos; i++){
        aux[i] = datos[i];
    }
    delete[] datos;
    datos = aux;
}
void Vector::alta(Item *dato) {
    if (cantidadDatos % 5 == 0 && cantidadDatos != 0){
        redimensionar_agrandar(dato);
    }
    else{
        datos[cantidadDatos] = dato;
    }
    cantidadDatos++;
    cout<<"elm tamaño maximo es:"<<tamanioMaximo<<endl;
    }


void Vector::alta(Item *dato, size_t indice) {
    if(indice == cantidadDatos){
        alta(dato);
    }
    else if (indice < cantidadDatos){
        Item* dato_final = datos[cantidadDatos - 1];
        for (size_t i = cantidadDatos; i > indice; i --){
            datos[i] = datos[i-1];
        }
        datos[indice] = dato;
        if (cantidadDatos % 5 == 0 && cantidadDatos != 0){
            tamanioMaximo += 5;
            redimensionar_agrandar(dato_final);
        }else{
            datos[cantidadDatos] = dato_final;
        }
        cantidadDatos++;
    }
    else{
        throw VectorException();
    }
}

Item* Vector::baja() {
    Item* dato_a_devolver;
    if (cantidadDatos != 0){
        dato_a_devolver = datos[cantidadDatos - 1];
        datos[cantidadDatos - 1] = nullptr;
        cantidadDatos --;
        if (tamanioMaximo != 5 && cantidadDatos % 5 == 0){
            redimensionar_achicar();
        }
    }
    else{
        throw VectorException();
    }
    cout<<"el tamaño maximo es: "<<tamanioMaximo <<endl;
    return dato_a_devolver;

}

Item* Vector::baja(size_t indice) {
    Item* dato_a_devolver;
    if (indice >= cantidadDatos || vacio()){
        throw VectorException();
    }
    else if (indice == cantidadDatos - 1){
        dato_a_devolver = baja();
    }
    else{
        dato_a_devolver = datos[indice];
        datos[indice] = nullptr;
        for (size_t i = indice; i < cantidadDatos; i++){
            datos[i] = datos[i+1];
        }
        cantidadDatos--;
        if (tamanioMaximo != 5 && cantidadDatos % 5 == 0){
            redimensionar_achicar();
        }
    }
    cout<<"el tamaño maximo es: "<<tamanioMaximo <<endl;
    return dato_a_devolver;
}

bool Vector::vacio() {
    return (cantidadDatos == 0);
}

size_t Vector::tamanio() {
    return cantidadDatos;
}

Item *&Vector::operator[](size_t indice) {
    if (indice < cantidadDatos){
        return *&datos[indice];
    }
    else{
        throw VectorException();
    }
}

Vector::~Vector(){
    for (size_t i = 0; i < cantidadDatos; i++){
        datos[i] = nullptr;
    }
    datos = nullptr;
}