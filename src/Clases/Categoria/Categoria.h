#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include<iostream>
#include "../../ICollection/interfaces/ICollection.h"
#include "../../Enum/index.cpp"

using namespace std;

class Categoria : public ICollectible {
    private:
      string descripcion;
    public:
      Categoria(string);
      void setDescripcion(string);
      string getDescripcion();
      virtual string darTipo() = 0;
};

#endif