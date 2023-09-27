#include "Vector.hpp"
#include <string>
#include <iostream>
using namespace std;


Vector::Vector() {
    this->tamanioMaximo = 2;
    this->cantidadDatos = 0;
    this->datos = new Item*[tamanioMaximo];
}

void Vector::alta(Item *dato) {
    if (cantidadDatos < tamanioMaximo){
        datos[cantidadDatos] = dato;
        cantidadDatos++;
        if (cantidadDatos % 2 == 0){
            tamanioMaximo += 2;
        }
    }
    else{
        throw VectorException();
    }
}

void Vector::alta(Item *dato, size_t indice) {
    if (cantidadDatos < tamanioMaximo && indice <= cantidadDatos){
        Item* dato_final = datos[cantidadDatos - 1];
        for (size_t i = cantidadDatos; i > indice; i --){
            datos[i] = datos[i-1];
        }
        datos[indice] = dato;
        cantidadDatos++;
        if (cantidadDatos % 2 == 0){
            tamanioMaximo += 2;
        }
        datos[cantidadDatos] = dato_final;
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
    }
    else{
        throw VectorException();
    }
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
    }
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
        //datos[i] == nullptr;
    }
    //datos == nullptr;
}