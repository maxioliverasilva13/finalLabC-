#ifndef DTINFOSUSCRIPCION_HEADER
#define DTINFOSUSCRIPCION_HEADER

#include<iostream>

enum EPeriodo { MENSUAL = "MENSUAL", TRIMESTRAL = "TRIMESTRAL", ANUAL = "ANUAL", VITALICIA = "VITALICIA" };


class DtInfoSuscripcion{
    private:
       int id;
       EPeriodo periodo;
       precio:float;
       suscrito: bool;
    public:
      DtInfoSuscripcion(int id, EPeriodo periodo, float precio, bool suscrito);
      int getId();
      EPeriodo getPeriodo();
      float getPrecio();
      bool getSuscrito();

};

#endif