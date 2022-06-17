#ifndef CATEGORIAGENERO_HEADER
#define CATEGORIAGENERO_HEADER

#include<iostream>
using namespace std;

class CategoriaGenero: public Categoria {
    private:
      EGeneroJuego tipo;
    public:
      CategoriaGenero(EGeneroJuego, string, int);
      void setTipo(EGeneroJuego);
      EGeneroJuego getTipo();
      string darTipo();
      string darNombreInstancia();
};

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

string CategoriaGenero::darNombreInstancia() {
    return "CategoriaGenero";
}

#endif
