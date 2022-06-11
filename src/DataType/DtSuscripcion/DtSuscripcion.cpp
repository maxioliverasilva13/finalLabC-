#include<iostream>
#include "DtSuscripcion.h"


using namespace std;

DtSuscripcion::DtSuscripcion(string nombreVideoJuego, DtInfoSuscripcion ** suscripciones){
    this->nombreVideoJuego = nombreVideoJuego;
    this->suscripciones = suscripciones;
};

string DtSuscripcion::getNombreVideojuego(){
    return this->nombreVideoJuego;
}

ICollection *  DtSuscripcion::getNombreVideojuego(){
    return this->suscripciones;
}
