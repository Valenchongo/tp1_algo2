
 #ifndef VECTOR_TESTS_INVENTARIO_H
#define VECTOR_TESTS_INVENTARIO_H
#include "Vector.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Inventario {
private:
    const size_t CANTIDAD_MAXIMA_DE_ITEMS = 15;
    const size_t VALOR_FUERA_DEL_INVENTARIO = 16;

    Vector vector;

    // Pre: Se le debe pasar string "nombre-item" por parametro.
    // Post: Mediante el nombre que se le pasa por parametro, busca el primer item con ese nombre dentro del inventario y devuelve la posicion del mismo.
    size_t buscar_indice_item(string nombre_item);

    // Pre: Se le debe pasar un string con formato "nombre,tipo".
    // Post: Retorna el nombre que esta dentro del string que se le paso por parametro.
    string extraer_nombre(string linea);

    // Pre: Se le debe pasar un string con formato "nombre,tipo".
    // Post: Retorna el tipo que esta dentro del string que se le paso por parametro.
    string extraer_tipo(string linea);

public:

    Inventario();

    // Pre: Se le debe pasar por parametro un item valido.
    // Post: Se encarga de agregar al vector el item pasado por parametro solo si la cantidad de items es menor a CANTIDAD_MAXIMA_DE_ITEMS.
    void alta(Item* item);

    // Pre: Se le debe pasar el nombre de un item.
    // Post: si el nombre del item esta dentro del inventario lo elimina del mismo, de no ser asi avisa por consola que el item no esta dentro del inventario.
    void baja(string nombre_item);

    // Pre:
    // Post: Lista la informacion de todos los items dentro del inventario.
    void consulta();

    // Pre:
    // Post: Guarda en un archivo csv todos los items que el jugador guardo en su inventario.
    void escribir_archivo();

    //Pre:
    //Post: Mediante un archivo csv, itera todos los items del mismo guardandolos en un inventario.
    void cargar_archivo();

    void tamaño();
};


#endif //VECTOR_TESTS_INVENTARIO_H
