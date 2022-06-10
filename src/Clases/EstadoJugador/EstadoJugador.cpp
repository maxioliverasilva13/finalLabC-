#include "EstadoJugador.h"

using namespace std;

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