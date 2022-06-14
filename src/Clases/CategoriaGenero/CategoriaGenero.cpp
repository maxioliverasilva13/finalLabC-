#include "CategoriaGenero.h"
#include "../../Clases/Categoria/Categoria.cpp"

using namespace std;


CategoriaGenero::CategoriaGenero(EGeneroJuego tipo, string descripcion, int id) : Categoria(descripcion, id) {
    this->tipo = tipo;
}

void CategoriaGenero::setTipo(EGeneroJuego tipo) {
    this->tipo = tipo;
}

EGeneroJuego CategoriaGenero::getTipo() {
    return this->tipo;
}

string CategoriaGenero::darTipo() {
    return getEGeneroJuego(this->tipo);
}
