#ifndef CATEGORIAOTRO_HEADER
#define CATEGORIAOTRO_HEADER

#include<iostream>
#include "../Categoria/Categoria.h"
#include "../../Enum/index.cpp"


using namespace std;

class CategoriaOtro: public Categoria {
    public:
      CategoriaOtro(string, string);
};

#endif