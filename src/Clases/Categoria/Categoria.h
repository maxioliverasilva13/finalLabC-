#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include<iostream>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../Enum/index.cpp"

using namespace std;

class Categoria : public ICollectible {
    private:
      int id;
      string descripcion;
    public:
      Categoria(string, int);
      ~Categoria();
      void setDescripcion(string);
      void setId(int);
      string getDescripcion();
      int getId();
      virtual string darTipo() = 0;
};

#endif