#include "EstadoJugador.h"

using namespace std;

EstadoJugador::EstadoJugador(int fechaHoraEntrada, int fechaHoraSalida, Partida * partida) {
  this->fechaHoraEntrada = fechaHoraEntrada;
  this->fechaHoraSalida = fechaHoraSalida; 
  this->partida = partida;
};

void EstadoJugador::setFechaHoraEntrada(int fechaHoraEntrada){
    this->fechaHoraEntrada = fechaHoraEntrada;
};
void EstadoJugador::setFechaHoraSalida(int fechaHoraSalida){
    this->fechaHoraSalida = fechaHoraSalida;
};

void EstadoJugador::setPartida(Partida * partida){
    this->partida = partida;
};

Partida * EstadoJugador::getPartida(){
    return this->partida;
};

int EstadoJugador::getFechaHoraEntrada(){
    return this->fechaHoraEntrada;
};

int EstadoJugador::getFechaHoraSalida(){
    return this->fechaHoraSalida;
};