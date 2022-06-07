#ifndef DTSUCRIPCION_HEADER
#define DTSUSCRIPCION_HEADER

#include "../DtInfoSuscripcion/DtInfoSuscripcion.h"

#include<iostream>
#include<string>

class DtSuscripcion{
    private:
       string nombreVideoJuego;
       DtInfoSuscripcion ** suscripciones;
    public:
      DtSuscripcion(string nombreVideojuego,DtInfoSuscripcion ** suscripciones);
      string getNombreVideojuego();
      DtInfoSuscripcion ** getSuscripcion(); 
};

#endif