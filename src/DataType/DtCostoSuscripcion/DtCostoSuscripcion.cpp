
#ifndef DTCOSTOSUSCRIPCION_CPP
#define DTCOSTOSUSCRIPCION_CPP

#include <iostream>
#include "DtCostoSuscripcion.h"

using namespace std;

DtCostoSuscripcion::DtCostoSuscripcion(ETipoSuscripcion tipo,float costo){
   this->tipo = tipo;
   this->costo = costo;
}



ETipoSuscripcion DtCostoSuscripcion::getTipo(){
    return this->tipo;
}


float DtCostoSuscripcion::getCosto(){
    return this->costo;
}

#endif


