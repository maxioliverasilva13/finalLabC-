#ifndef CATEGORIAPLATAFORMA_HEADER
#define CATEGORIAPLATAFORMA_HEADER

using namespace std;

#include<iostream>

class CategoriaPlataforma: public Categoria {
    private:
      ETipoPlataforma tipo;
    public:
      CategoriaPlataforma(ETipoPlataforma, string, int);
      void setTipo(ETipoPlataforma);
      ETipoPlataforma getTipo();
      string darTipo();
};

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

#endif