
#include "../include/Inventario.h"
using namespace std;
Inventario::Inventario() {

}

void Inventario::tamaño(){
    cout<<vector.tamanio();
}
void Inventario::alta(Item* item) {
    if (vector.tamanio() < CANTIDAD_MAXIMA_DE_ITEMS){
        vector.alta(item);
    }
    else{
        cout<<"el inventario esta lleno..."<<endl;
    }
}

size_t Inventario::buscar_indice_item(string nombre_item) {
    size_t indice = VALOR_FUERA_DEL_INVENTARIO; //le doy el valor de 16 para que en caso que no se encuentre el item retorne este numero que esta fuera del alcance del inventario
    for(size_t i = 0; i < vector.tamanio(); i++){
        if(*vector[i] == nombre_item){
            indice = i;
        }
    }
    return indice;
}

void Inventario::baja(string nombre_item) {

    if (!vector.vacio()){
        size_t indice = buscar_indice_item(nombre_item);
        if (indice != VALOR_FUERA_DEL_INVENTARIO){
            Item* item =vector.baja(indice);
            delete item;
        }
        else{
            cout<<"error de inventario! no se dispone de ese item"<<endl;
        }
    }else{
        cout<<"el vector esta vacio, no se pueden eliminar items..."<<endl;
    }
}

void Inventario::escribir_archivo() {;
    ofstream archivoOutput("items.csv");
    for (size_t i = 0; i < vector.tamanio() ; i++ ){
        cout<<i;
        archivoOutput << *vector[i] <<"\n";
        delete vector[i];
    }
    archivoOutput.close();
}

void Inventario::cargar_archivo() {
    ifstream archivoInput("items.csv");
    string linea;
    string nombre;
    string tipo;
    while(getline(archivoInput,linea)){
        nombre = extraer_nombre(linea);
        tipo = extraer_tipo(linea);
        Item* item = new Item(nombre,tipo);
        vector.alta(item);
    }
    archivoInput.close();
}

string Inventario::extraer_nombre(std::string linea) {
    size_t posicion_de_coma = linea.find(",");
    string nombre = "";
    for(size_t i = 0; i < posicion_de_coma; i++){
        nombre += linea[i];
    }
    return nombre;
}

string Inventario::extraer_tipo(std::string linea) {
    size_t posicion_de_coma = linea.find(",");
    string apellido = "";
    for(size_t i = posicion_de_coma + 1; i < linea.size() ; i++){
        apellido += linea[i];
    }
    return apellido;
}



void Inventario::consulta() {
    string nombre;
    string tipo;
    for(size_t i = 0; i < vector.tamanio(); i++){
        cout<< i+1<<") ";
        vector[i]->listarInformacion();
        cout<<endl;
    }
}


