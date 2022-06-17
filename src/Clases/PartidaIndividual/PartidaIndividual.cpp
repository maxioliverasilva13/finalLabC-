#ifndef PARTIDAINDIVIDUAL_FUNCTIONS
#define PARTIDAINDIVIDUAL_FUNCTIONS


#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(bool nueva, int id, EEstado estado, DtFechaHora *fecha, Videojuego *vj, Jugador *j) : Partida(id, estado, vj, fecha, j)
{
  this->nueva = nueva;
};

string PartidaIndividual::darTipo()
{
  return "PartidaIndividual";
};

PartidaIndividual::~PartidaIndividual()
{
  this->creador->eliminarPartida(this);
}

void PartidaIndividual::finalizarPartida()
{
  // NEcesitamos asignar el parametro de "duracion"
  cout << "Finalizar Partida";
}

void PartidaIndividual::continuarPartida()
{
  this->estado = ENCURSO;
};

DtPartida *PartidaIndividual::getDtPartida()
{
  DtPartida *dtpart = new DtPartida(this->getId(), this->getFecha(), 0);
  return dtpart;
};

void PartidaIndividual::setNueva(bool nueva)
{
  this->nueva = nueva;
};

bool PartidaIndividual::getNueva()
{
  return this->nueva;
};


#endif
