#include "CategoriaOtro.h"

using namespace std;

CategoriaOtro::CategoriaOtro(string nombre, string descripcion, int id) : Categoria(descripcion, id) {
    this->nombre = nombre;
}

void CategoriaOtro::setNombre(string nombre) {
    this->nombre = nombre;
}

string CategoriaOtro::getNombre() {
    return this->nombre;
}

string CategoriaOtro::darTipo() {
    return this->nombre;
}