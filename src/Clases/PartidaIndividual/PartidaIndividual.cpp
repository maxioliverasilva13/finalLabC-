#ifndef PARTIDAINDIVIDUAL_HEADER
#define PARTIDAINDIVIDUAL_HEADER

using namespace std;

#include <iostream>

class PartidaIndividual : public Partida
{
private:
  bool nueva;

public:
  PartidaIndividual(bool, int, EEstado, DtFechaHora *, Videojuego *, Jugador *j);
  ~PartidaIndividual();
  void continuarPartida();
  void setNueva(bool);
  bool getNueva();
  void finalizarPartida();
  DtPartida *getDtPartida();
  string darTipo();
};

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