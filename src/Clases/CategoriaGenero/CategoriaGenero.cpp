#include "CategoriaGenero.h"

using namespace std;


CategoriaGenero::CategoriaGenero(EGeneroJuego tipo, string nombre, string descripcion) : Categoria(nombre, descripcion) {
    this->tipo = tipo;
}

void CategoriaGenero::setTipo(EGeneroJuego tipo) {
    this->tipo = tipo;
}

EGeneroJuego CategoriaGenero::getTipo() {
    return this->tipo;
}
