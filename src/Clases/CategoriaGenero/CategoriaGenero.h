#ifndef CATEGORIAGENERO_HEADER
#define CATEGORIAGENERO_HEADER

#include<iostream>
#include "../Categoria/Categoria.h"
#include "../../Enum/index.cpp"


using namespace std;

class CategoriaGenero: public Categoria {
    private:
      EGeneroJuego tipo;
    public:
      CategoriaGenero(EGeneroJuego, string, int);
      void setTipo(EGeneroJuego);
      EGeneroJuego getTipo();
      string darTipo();
};

#endif