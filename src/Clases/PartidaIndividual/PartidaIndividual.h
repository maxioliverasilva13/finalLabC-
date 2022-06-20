#ifndef PARTIDAINDIVIDUAL_HEADER
#define PARTIDAINDIVIDUAL_HEADER

using namespace std;

#include <iostream>

class PartidaIndividual : public Partida
{
private:
  bool nueva;
  float duracion;
public:
  PartidaIndividual(bool, EEstado, DtFechaHora *, Videojuego *, Jugador *j);
  ~PartidaIndividual();
  void continuarPartida();
  void setNueva(bool);
  bool getNueva();
  void finalizarPartida(DtFechaHora *);
  DtPartida *getDtPartida();
  string darTipo();
  float getDuracion();
  void setDuracion(float);
};
#endif