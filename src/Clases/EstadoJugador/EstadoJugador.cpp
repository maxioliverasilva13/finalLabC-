#ifndef ESTADOJUGADOR_FUNCTIOS
#define ESTADOJUGADOR_FUNCTIOS
#include "EstadoJugador.h"

#include <iostream>

using namespace std;

EstadoJugador::EstadoJugador(DtFechaHora *fechaHoraEntrada, DtFechaHora *fechaHoraSalida, Partida *partida, Jugador *jugador)
{
    this->fechaHoraEntrada = fechaHoraEntrada;
    this->fechaHoraSalida = fechaHoraSalida;
    this->partida = partida;
    this->jugador = jugador;
};

EstadoJugador::~EstadoJugador()
{
    this->jugador->eliminarEstadosJugador(this);
    delete fechaHoraEntrada;
    delete fechaHoraSalida;
}

Jugador * EstadoJugador::getJugador(){
    return this->jugador;
}

void EstadoJugador::setFechaHoraEntrada(DtFechaHora *fechaHoraEntrada)
{
    this->fechaHoraEntrada = fechaHoraEntrada;
};

void EstadoJugador::setFechaHoraSalida(DtFechaHora *fechaHoraSalida)
{
    this->fechaHoraSalida = fechaHoraSalida;
};

void EstadoJugador::setPartida(Partida *partida)
{
    this->partida = partida;
};

Partida *EstadoJugador::getPartida()
{
    return this->partida;
};

DtFechaHora *EstadoJugador::getFechaHoraEntrada()
{
    return this->fechaHoraEntrada;
};

DtFechaHora *EstadoJugador::getFechaHoraSalida()
{
    return this->fechaHoraSalida;
};

#endif
