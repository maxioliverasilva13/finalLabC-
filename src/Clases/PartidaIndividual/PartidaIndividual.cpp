#ifndef PARTIDAINDIVIDUAL_HEADER
#define PARTIDAINDIVIDUAL_HEADER

using namespace std;

#include <iostream>

class PartidaIndividual : public Partida
{
private:
  bool nueva;

public:
  PartidaIndividual(bool, int, EEstado, DtFechaHora *, Videojuego *);
  void continuarPartida();
  void setNueva(bool);
  bool getNueva();
  void finalizarPartida();
  DtPartida *getDtPartida();
};

PartidaIndividual::PartidaIndividual(bool nueva, int id, EEstado estado, DtFechaHora *fecha, Videojuego *vj) : Partida(id, estado, vj, fecha)
{
  this->nueva = nueva;
};

void PartidaIndividual::finalizarPartida()
{
  cout << "Finalizar Partida";
}

void PartidaIndividual::continuarPartida()
{
  cout << "continuarPartida";
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