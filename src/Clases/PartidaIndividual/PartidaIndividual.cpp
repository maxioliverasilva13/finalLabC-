#ifndef PARTIDAINDIVIDUAL_FUNCTIONS
#define PARTIDAINDIVIDUAL_FUNCTIONS


#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(bool nueva, EEstado estado, DtFechaHora *fecha, Videojuego *vj, Jugador *j) : Partida(estado, vj, fecha, j)
{
  this->nueva = nueva;
  this->duracion = 0;
};

string PartidaIndividual::darTipo()
{
  return "PartidaIndividual";
};

PartidaIndividual::~PartidaIndividual()
{
  this->creador->eliminarPartida(this);
}

float calcularDifEnMinutosS(DtFechaHora * fechaInicio, DtFechaHora * fechaFin) {
    // asumo que la fechaInicio es menor a la de fin

    //todo en minutos
    float difDias = (fechaFin->getDay() - fechaInicio->getDay()) * 1440; // 1440 son los minutos de un dia
    float difMeses = (fechaFin->getMonth() - fechaInicio->getMonth()) * 43800; // 43800 son los minutos de un mes
    float difAnios = (fechaFin->getYear() - fechaInicio->getYear()) * 525600; // 525600 son los minutos de un año
    float difMinutos = (fechaFin->getMinute() - fechaInicio->getMinute());
    float difHoras = (fechaFin->getHour() - fechaInicio->getHour()) * 60; // 60 son los minutos de una hora

    return difDias + difMeses + difAnios + difMinutos + difHoras;
}

void PartidaIndividual::finalizarPartida(DtFechaHora * fechaSistema)
{
  this->setEstado(FINALIZADA);
  DtFechaHora * fechaInicio = this->getFecha();
  DtFechaHora * fechaFin = fechaSistema;
  float duracionPart = calcularDifEnMinutosS(fechaInicio, fechaFin);
  this->duracion = duracionPart;
}

void PartidaIndividual::continuarPartida()
{
  this->estado = ENCURSO;
};
DtVideojuego* PartidaIndividual::getVideojuego() {
  DtVideojuego* Juego = new DtVideojuego(videojuego->getNombre(), videojuego->getDescripcion(), videojuego->getPromedio_puntuacion(), videojuego->getPuntuaciones(), videojuego->getCategorias(), videojuego->getSuscripciones(), videojuego->getDesarrollador()->getNomEmpresa(), videojuego->getTotalHorasJugadas());
  return Juego;
}

DtPartida *PartidaIndividual::getDtPartida()
{
  DtPartida *dtpart = new DtPartidaIndividual(this->getId(), !this->getNueva(), this->getEstado(), this->getDuracion(), this->getFecha(), this->videojuego->getNombre(), this->creador->getNickname(), this->videojuego->getDtVideojuego() );
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

void PartidaIndividual::setDuracion(float duracion)
{
  this->duracion = duracion;
};

float PartidaIndividual::getDuracion()
{
  return this->duracion;
};

#endif
