
#ifndef CATEGORIAOTRO_HEADER
#define CATEGORIAOTRO_HEADER

#include<iostream>
using namespace std;

class CategoriaOtro: public Categoria {
    private:
      string nombre;
    public:
      CategoriaOtro(string, string, int);
      void setNombre(string);
      string getNombre();
      string darTipo();
};

CategoriaOtro::CategoriaOtro(string nombre, string descripcion, int id) : Categoria(descripcion, id) {
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

#endif