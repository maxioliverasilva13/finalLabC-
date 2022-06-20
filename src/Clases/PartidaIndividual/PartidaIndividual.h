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
  DtVideojuego* getVideojuego();
};
#endif