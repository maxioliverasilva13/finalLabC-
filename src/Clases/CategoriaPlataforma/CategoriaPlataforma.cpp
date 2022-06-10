#include "CategoriaPlataforma.h"

using namespace std;


CategoriaPlataforma::CategoriaPlataforma(ETipoPlataforma tipo, string nombre, string descripcion) : Categoria(nombre, descripcion) {
    this->tipo = tipo;
}

void CategoriaPlataforma::setTipo(ETipoPlataforma tipo) {
    this->tipo = tipo;
}

ETipoPlataforma CategoriaPlataforma::getTipo() {
    return this->tipo;
}