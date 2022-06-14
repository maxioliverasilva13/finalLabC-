
#ifndef CATEGORIA_CPP
#define CATEGORIA_CPP

#include "Categoria.h"

Categoria::Categoria(string descripcion) {
    this->descripcion = descripcion;
}

void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}

#endif