#include "CategoriaGenero.h"

using namespace std;


CategoriaGenero::CategoriaGenero(EGeneroJuego tipo, string descripcion) : Categoria(descripcion) {
    this->tipo = tipo;
}

void CategoriaGenero::setTipo(EGeneroJuego tipo) {
    this->tipo = tipo;
}

EGeneroJuego CategoriaGenero::getTipo() {
    return this->tipo;
}

string CategoriaGenero::darTipo() {
    // return this->tipo;   // Hacer pasaje de enum a string.
}
