#include<iostream>
#include "DtPartida.h"

using namespace std;

DtPartida::DtPartida(int id, DtFechaHora * fecha, int duracion) {
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
};

int DtPartida::getId(){
    return this->id;
}

DtFechaHora * DtPartida::getFecha(){
    return this->fecha;
}

int DtPartida::getDuracion(){
    return this->duracion;
}