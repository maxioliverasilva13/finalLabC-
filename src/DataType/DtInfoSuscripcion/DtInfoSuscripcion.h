#ifndef DTINFOSUSCRIPCION_HEADER
#define DTINFOSUSCRIPCION_HEADER

#include<iostream>
#include "../../Enum/index.cpp"

class DtInfoSuscripcion{
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