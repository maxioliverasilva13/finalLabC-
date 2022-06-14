#ifndef DTINFOSUSCRIPCION_CPP
#define DTINFOSUSCRIPCION_CPP


#include<iostream>
#include "DtInfoSuscripcion.h"


using namespace std;

DtInfoSuscripcion::DtInfoSuscripcion(int id, EPeriodo periodo, float precio, bool suscrito){
    this->id = id;
    this->periodo = periodo;
    this->precio = precio;
    this->suscrito = suscrito;
};

int DtInfoSuscripcion::getId(){
    return this->id;
}

EPeriodo DtInfoSuscripcion::getPeriodo(){
    return this->periodo;
}

float DtInfoSuscripcion::getPrecio(){
    return this->precio;
}

bool DtInfoSuscripcion::getSuscrito(){
    return this->suscrito;
}

#endif