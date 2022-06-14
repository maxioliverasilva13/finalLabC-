

#include <iostream>
#include "DtCostoSuscripcion.h"

using namespace std;

DtCostoSuscripcion::DtCostoSuscripcion(EPeriodo tipo,float costo){
   this->tipo = tipo;
   this->costo = costo;
}



EPeriodo DtCostoSuscripcion::getTipo(){
    return this->tipo;
}


float DtCostoSuscripcion::getCosto(){
    return this->costo;
}


