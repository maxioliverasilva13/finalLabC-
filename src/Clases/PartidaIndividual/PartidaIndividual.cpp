#ifndef PARTIDAINDIVIDUAL_FUNCTIONS
#define PARTIDAINDIVIDUAL_FUNCTIONS


#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(bool nueva, EEstado estado, DtFechaHora *fecha, Videojuego *vj, Jugador *j) : Partida(estado, vj, fecha, j)
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

void PartidaIndividual::finalizarPartida(DtFechaHora * fechaSistema)
{
  this->setEstado(FINALIZADA);
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
