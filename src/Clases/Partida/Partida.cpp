#ifndef PARTIDA_FUNCTIONS
#define PARTIDA_FUNCTIONS

#include <iostream>
#include "Partida.h"

using namespace std;

int Partida::id = 0;

Partida::Partida(EEstado estado, Videojuego *vj, DtFechaHora *fecha, Jugador *j)
{
  Partida::id++;
  this->id = id;
  this->estado = estado;
  this->videojuego = vj;
  this->fecha = fecha;
  this->creador = j;
};

Partida::~Partida()
{
}

string Partida::darNombreJuego()
{
  return this->videojuego->getNombre();
}

void Partida::setEstado(EEstado estado)
{
  this->estado = estado;
}

void Partida::setId(int id)
{
  this->id = id;
}

void Partida::setFecha(DtFechaHora *fecha)
{
  this->fecha = fecha;
}

int Partida::getEstado()
{
  return this->estado;
}

int Partida::getId()
{
  return this->id;
}

DtFechaHora *Partida::getFecha()
{
  return this->fecha;
}

bool Partida::esFinalizada()
{
  return this->estado == FINALIZADA;
};

#endif
