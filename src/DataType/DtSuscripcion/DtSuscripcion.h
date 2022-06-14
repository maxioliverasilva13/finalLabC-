#ifndef DTSUCRIPCION_HEADER
#define DTSUSCRIPCION_HEADER

#include<iostream>
#include<string>

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../DtInfoSuscripcion/DtInfoSuscripcion.h"

using namespace std;
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