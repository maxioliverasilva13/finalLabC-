#include "Partida.h"

using namespace std;

Partida::Partida(int id,int estado) {
  this->id=id;
  this->estado=estado;
};


string Partida::darNombreJuego() {
    return "Juego";
}

void Partida::setEstado(int estado) {
    this->estado = estado;
}

void Partida::setId(int id) {
    this->id = id;
}

int Partida::getEstado() {
    return this->estado;
}

int Partida::getId() {
    return this->id;
}