#include "CategoriaPlataforma.h"

using namespace std;


CategoriaPlataforma::CategoriaPlataforma(ETipoPlataforma tipo, string descripcion, int id) : Categoria(descripcion, id) {
    this->tipo = tipo;
}

void CategoriaPlataforma::setTipo(ETipoPlataforma tipo) {
    this->tipo = tipo;
}

ETipoPlataforma CategoriaPlataforma::getTipo() {
    return this->tipo;
}

string CategoriaPlataforma::darTipo() {
    return getETipoPlataforma(this->tipo);
}