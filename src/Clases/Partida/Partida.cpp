#ifndef PARTIDA_CPP
#define PARTIDA_CPP

#include <iostream>

using namespace std;

#include "./Partida.h"

Partida::Partida(int id, EEstado estado, Videojuego *vj, DtFechaHora *fecha,Jugador * creador)
{
  this->id = id;
  this->estado = estado;
  this->videojuego = vj;
  this->fecha = fecha;
  this->creador = creador;
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

EEstado Partida::getEstado()
{
  return this->estado;
}

int Partida::getId()
{
  return this->id;
}

bool Partida::isOwner(Jugador * jugador){
  if(this->creador->getNickname() == jugador->getNickname()){
    return true;
  }
  return false;
}

DtFechaHora *Partida::getFecha()
{
  return this->fecha;
}

string Partida::darNombreJuego(){
  return this->videojuego->getNombre();
}

Partida::~Partida()
{
  cout << "Me borro";
}


#endif
