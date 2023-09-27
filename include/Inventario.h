
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

    size_t buscar_indice_item(string nombre_item);

    string extraer_nombre(string linea);

    string extraer_tipo(string linea);

public:

    Inventario();
    //pre:
    //post:
    void alta(Item* item);

    void baja(string nombre_item);

    void consulta();

    void escribir_archivo();

    void cargar_archivo();

    void tamaño();
};


#endif //VECTOR_TESTS_INVENTARIO_H
