#ifndef DTSUCRIPCION_HEADER
#define DTSUSCRIPCION_HEADER

#include "../DtInfoSuscripcion/DtInfoSuscripcion.h"

#include<iostream>
#include<string>
#include "../../ICollection/interfaces/ICollection.h"


class DtSuscripcion:public ICollectible{
    private:
       string nombreVideoJuego;
       ICollection *   suscripciones;
    public:
      DtSuscripcion(string nombreVideojuego, ICollection * suscripciones);
      string getNombreVideojuego();
      ICollection *  getSuscripcion(); 
};

#endif