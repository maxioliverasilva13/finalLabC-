#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include <iostream>

using namespace std;

class Partida : public ICollectible
{
protected:
  static int cant;
  int id;
  EEstado estado;
  DtFechaHora *fecha;
  Videojuego *videojuego = NULL;
  Jugador *creador;

public:
  Partida(EEstado, Videojuego *, DtFechaHora *, Jugador *);
  ~Partida();
  string darNombreJuego();
  void setEstado(EEstado);
  void setId(int);
  void setFecha(DtFechaHora *);
  EEstado getEstado();
  int getId();
  bool esFinalizada();
  DtFechaHora *getFecha();
  virtual DtVideojuego* getVideojuego() = 0;
  Jugador * getCreador();
  virtual string darTipo() = 0;
  virtual DtPartida *getDtPartida() = 0;
  virtual void finalizarPartida(DtFechaHora *) = 0;
  virtual float getDuracion() = 0;
};

#endif

