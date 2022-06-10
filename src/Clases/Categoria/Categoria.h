#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include<iostream>
#include "../../ICollection/interfaces/ICollection.h"

using namespace std;

class Categoria : public ICollectible {
    private:
      string nombre;
      string descripcion;
    public:
      Categoria(string, string);
      void setNombre(string);
      void setDescripcion(string);
      string getNombre();
      string getDescripcion();
};

#endif