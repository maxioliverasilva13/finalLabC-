#ifndef CATEGORIAPLATAFORMA_HEADER
#define CATEGORIAPLATAFORMA_HEADER

#include<iostream>
#include "../Categoria/Categoria.h"
#include "../../Enum/index.cpp"


using namespace std;

class CategoriaPlataforma: public Categoria {
    private:
      ETipoPlataforma tipo;
    public:
      CategoriaPlataforma(ETipoPlataforma, string, int);
      void setTipo(ETipoPlataforma);
      ETipoPlataforma getTipo();
      string darTipo();
};

#endif