
#ifndef DTSUSCRIPCION_CPP
#define DTSUSCRIPCION_CPP

#include<iostream>
#include "DtSuscripcion.h"


using namespace std;

DtSuscripcion::DtSuscripcion(string nombreVideoJuego, ICollection * suscripciones){
    this->nombreVideoJuego = nombreVideoJuego;
    this->suscripciones = suscripciones;
};

string DtSuscripcion::getNombreVideojuego(){
    return this->nombreVideoJuego;
}

ICollection *  DtSuscripcion::getSuscripcion(){
    return this->suscripciones;
}

#endif

