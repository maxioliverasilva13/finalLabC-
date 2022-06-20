
#ifndef CATEGORIAOTRO_HEADER
#define CATEGORIAOTRO_HEADER

#include<iostream>
using namespace std;

class CategoriaOtro: public Categoria {
    private:
      string nombre;
    public:
      CategoriaOtro(string, string);
      void setNombre(string);
      string getNombre();
      string darTipo();
      string darNombreInstancia();
};

CategoriaOtro::CategoriaOtro(string nombre, string descripcion) : Categoria(descripcion) {
    this->nombre = nombre;
}

void CategoriaOtro::setNombre(string nombre) {
    this->nombre = nombre;
}

string CategoriaOtro::getNombre() {
    return this->nombre;
}

string CategoriaOtro::darTipo() {
    return this->nombre;
}

string CategoriaOtro::darNombreInstancia() {
    return "CategoriaOtro";
}

#endif