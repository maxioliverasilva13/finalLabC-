#ifndef ESTADOJUGADOR_HEADER
#define ESTADOJUGADOR_HEADER

#include<iostream>
#include "../Jugador/Jugador.h"

using namespace std;

class EstadoJugador: public ICollectible {
    private:
      DtFechaHora * fechaHoraEntrada;
      DtFechaHora * fechaHoraSalida;
      Partida * partida = NULL;
      Jugador * jugador = NULL;
    public:
      EstadoJugador(DtFechaHora *, Partida *, Jugador *);
      void setFechaHoraEntrada(DtFechaHora *);
      void setFechaHoraSalida(DtFechaHora *);
      void setPartida(Partida *);
      DtFechaHora * getFechaHoraEntrada();
      DtFechaHora * getFechaHoraSalida();
      Partida * getPartida();
};

EstadoJugador::EstadoJugador(DtFechaHora * fechaHoraEntrada, Partida * partida, Jugador * Jugador) {
  this->fechaHoraEntrada = fechaHoraEntrada;
  this->fechaHoraSalida = fechaHoraSalida; 
  this->partida = partida;
  this->jugador = jugador;
};

void EstadoJugador::setFechaHoraEntrada(DtFechaHora * fechaHoraEntrada){
    this->fechaHoraEntrada = fechaHoraEntrada;
};

void EstadoJugador::setFechaHoraSalida(DtFechaHora * fechaHoraSalida){
    this->fechaHoraSalida = fechaHoraSalida;
};

void EstadoJugador::setPartida(Partida * partida){
    this->partida = partida;
};

Partida * EstadoJugador::getPartida(){
    return this->partida;
};

DtFechaHora * EstadoJugador::getFechaHoraEntrada(){
    return this->fechaHoraEntrada;
};

DtFechaHora * EstadoJugador::getFechaHoraSalida(){
    return this->fechaHoraSalida;
};

#endif

