#ifndef DTINFOSUSCRIPCION_HEADER
#define DTINFOSUSCRIPCION_HEADER

#include<iostream>
#include "../../Enum/index.cpp"
#include "../../DataType/DtInfoSuscripcion/DtInfoSuscripcion.h";

class DtInfoSuscripcion: public ICollectible{
    private:
       int id;
       EPeriodo periodo;
       float precio;
       bool suscrito;
    public:
      DtInfoSuscripcion(int id, EPeriodo periodo, float precio, bool suscrito);
      int getId();
      EPeriodo getPeriodo();
      float getPrecio();
      bool getSuscrito();

};

#endif