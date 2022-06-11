#ifndef CATEGORIAOTRO_HEADER
#define CATEGORIAOTRO_HEADER

#include<iostream>
#include "../Categoria/Categoria.h"
#include "../../Enum/index.cpp"


using namespace std;

class CategoriaOtro: public Categoria {
    private:
      string nombre;
    public:
      CategoriaOtro(string, string);
      void setNombre(string);
      string getNombre();
      string darTipo();
};

#endif