#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include <iostream>

using namespace std;

class Partida : public ICollectible
{
protected:
  int id;
  EEstado estado;
  DtFechaHora *fecha;
  Videojuego *videojuego = NULL;
  Jugador *creador;

public:
  Partida(int, EEstado, Videojuego *, DtFechaHora *, Jugador *);
  ~Partida();
  string darNombreJuego();
  void setEstado(EEstado);
  void setId(int);
  void setFecha(DtFechaHora *);
  int getEstado();
  int getId();
  bool esFinalizada();
  DtFechaHora *getFecha();
  virtual DtPartida *getDtPartida() = 0;
  virtual void finalizarPartida() = 0;
  virtual string darTipo() = 0;
};

using namespace std;

Partida::Partida(int id, EEstado estado, Videojuego *vj, DtFechaHora *fecha, Jugador *j)
{
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
