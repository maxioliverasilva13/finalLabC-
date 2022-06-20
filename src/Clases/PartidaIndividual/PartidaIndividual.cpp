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
  this->setEstado(FINALIZADA);
}

void PartidaIndividual::continuarPartida()
{
  this->estado = ENCURSO;
};
DtVideojuego* PartidaIndividual::getVideojuego() {
  DtVideojuego* Juego = new DtVideojuego(videojuego->getNombre(), videojuego->getDescripcion(), videojuego->getPromedio_puntuacion(), videojuego->getPuntuaciones(), videojuego->getCategorias(), videojuego->getSuscripciones());
  return Juego;
}

DtPartida *PartidaIndividual::getDtPartida()
{
  DtPartida *dtpart = new DtPartida(this->getId(), this->getFecha(), 0, getVideojuego());
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
