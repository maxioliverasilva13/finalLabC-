#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include<iostream>


using namespace std;

class Partida : public ICollectible {
    private:
      int id;
      EEstado estado;
      DtFechaHora * fecha;
      Videojuego * videojuego = NULL;
    public:
      Partida(int, EEstado, Videojuego *, DtFechaHora *);
      ~Partida();
      string darNombreJuego();
      void setEstado(EEstado);
      void setId(int);
      void setFecha(DtFechaHora *);
      int getEstado();
      int getId();
      DtFechaHora * getFecha();
      virtual DtPartida * getDtPartida() = 0;
      virtual void finalizarPartida() = 0;
};

using namespace std;

Partida::Partida(int id,EEstado estado, Videojuego * vj, DtFechaHora * fecha) {
  this->id=id;
  this->estado=estado;
  this->videojuego = vj;
  this->fecha = fecha;
};


string Partida::darNombreJuego() {
    return "Juego";
}

void Partida::setEstado(EEstado estado) {
    this->estado = estado;
}

void Partida::setId(int id) {
    this->id = id;
}


void Partida::setFecha(DtFechaHora * fecha) {
  this->fecha = fecha;
}

int Partida::getEstado() {
    return this->estado;
}

int Partida::getId() {
    return this->id;
}

DtFechaHora * Partida::getFecha() {
  return this->fecha;
}

Partida::~Partida() {
  cout << "Me borro";
}

#endif


