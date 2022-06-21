#ifndef CATEGORIAPLATAFORMA_HEADER
#define CATEGORIAPLATAFORMA_HEADER

using namespace std;

#include<iostream>

class CategoriaPlataforma: public Categoria {
    private:
      ETipoPlataforma tipo;
    public:
      CategoriaPlataforma(ETipoPlataforma, string);
      void setTipo(ETipoPlataforma);
      ETipoPlataforma getTipo();
      string darTipo();
      string darNombreInstancia();
};

CategoriaPlataforma::CategoriaPlataforma(ETipoPlataforma tipo, string descripcion) : Categoria(descripcion) {
    this->tipo = tipo;
}

void CategoriaPlataforma::setTipo(ETipoPlataforma tipo) {
    this->tipo = tipo;
}

ETipoPlataforma CategoriaPlataforma::getTipo() {
    return this->tipo;
}

string CategoriaPlataforma::darTipo() {
     if (tipo == OTRAPLATAFORMA) {
        return this->getCustomName();
    } else {
        return getETipoPlataforma(this->tipo);
    }
}

string CategoriaPlataforma::darNombreInstancia() {
    return "CategoriaPlataforma";
}

#endif