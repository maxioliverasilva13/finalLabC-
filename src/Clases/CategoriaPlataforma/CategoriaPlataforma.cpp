#ifndef CATEGORIAPLATAFORMA_CPP
#define CATEGORIAPLATAFORMA_CPP

#include "CategoriaPlataforma.h"

using namespace std;


CategoriaPlataforma::CategoriaPlataforma(ETipoPlataforma tipo, string descripcion) : Categoria(descripcion) {
    this->tipo = tipo;
}

ETipoPlataforma CategoriaPlataforma::getTipo() {
    return this->tipo;
}

void CategoriaPlataforma::setTipo(ETipoPlataforma tipo) {
    this->tipo = tipo;
}

ETipoPlataforma CategoriaPlataforma::getTipo() {
    return this->tipo;
}

#endif