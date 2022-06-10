#include "Partida.h"
#include "../../DataType/DtFechaHora/DtFechaHora.cpp"

using namespace std;

Partida::Partida(int id,EEstado estado, DtFechaHora * fecha) {
  this->id=id;
  this->estado=estado;
  this->fecha = fecha;
};


string Partida::darNombreJuego() {
    return "Juego";
}

void Partida::setEstado(EEstado estado) {
    this->estado = estado;
}

void Partida::setId(int id) {
    this->id = id;
}


void Partida::setFecha(DtFechaHora * fecha) {
  this->fecha = fecha;
}

int Partida::getEstado() {
    return this->estado;
}

int Partida::getId() {
    return this->id;
}

DtFechaHora * Partida::getFecha() {
  return this->fecha;
}

Partida::~Partida() {
  cout << "Me borro";
}