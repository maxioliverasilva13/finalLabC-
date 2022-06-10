#include "Categoria.h"

Categoria::Categoria(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

void Categoria::setNombre(string nombre) {
    this->nombre = nombre;
}

void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Categoria::getNombre() {
    return this->nombre;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}
