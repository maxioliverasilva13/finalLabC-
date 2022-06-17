#ifndef PARTIDA_CPP
#define PARTIDA_CPP

#include <iostream>

using namespace std;

#include "./Partida.h"

Partida::Partida(int id, EEstado estado, Videojuego *vj, DtFechaHora *fecha)
{
  this->id = id;
  this->estado = estado;
  this->videojuego = vj;
  this->fecha = fecha;
};

string Partida::darNombreJuego()
{
  return "Juego";
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

Partida::~Partida()
{
  cout << "Me borro";
}

#endif
