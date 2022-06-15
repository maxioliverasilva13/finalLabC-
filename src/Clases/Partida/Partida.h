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

public:
  Partida(int, EEstado, Videojuego *, DtFechaHora *);
  ~Partida();
  string darNombreJuego();
  void setEstado(EEstado);
  void setId(int);
  void setFecha(DtFechaHora *);
  int getEstado();
  int getId();
  DtFechaHora *getFecha();
  virtual DtPartida *getDtPartida() = 0;
  virtual void finalizarPartida() = 0;
};



#endif
