#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include <iostream>

using namespace std;

class Partida : public ICollectible
{
private:
  int id;
  EEstado estado;
  DtFechaHora *fecha;
  Videojuego *videojuego = NULL;
  Jugador * creador;

public:
  Partida(int, EEstado, Videojuego *, DtFechaHora *,Jugador*);
  ~Partida();
  string darNombreJuego();
  void setEstado(EEstado);
  void setId(int);
  void setFecha(DtFechaHora *);
  EEstado getEstado();
  int getId();
  bool isOwner(Jugador *);
  string darNombreJuego();
  DtFechaHora *getFecha();
  virtual DtPartida *getDtPartida() = 0;
  virtual void finalizarPartida() = 0;
  virtual string getNicknameJugador() = 0;
};



#endif
