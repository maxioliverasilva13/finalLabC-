#ifndef ESTADOJUGADOR_HEADER
#define ESTADOJUGADOR_HEADER

#include <iostream>

using namespace std;

class EstadoJugador : public ICollectible
{
private:
    DtFechaHora *fechaHoraEntrada;
    DtFechaHora *fechaHoraSalida;
    PartidaMultijugador *partida;
    Jugador *jugador;

public:
    EstadoJugador(DtFechaHora *, DtFechaHora *, PartidaMultijugador *, Jugador *);
    void setFechaHoraEntrada(DtFechaHora *);
    void setFechaHoraSalida(DtFechaHora *);
    void setPartida(PartidaMultijugador *);
    DtFechaHora *getFechaHoraEntrada();
    DtFechaHora *getFechaHoraSalida();
    PartidaMultijugador *getPartida();
    Jugador * getJugador();
};

EstadoJugador::EstadoJugador(DtFechaHora *fechaHoraEntrada, DtFechaHora *fechaHoraSalida, PartidaMultijugador *partida, Jugador *jugador)
{
    this->fechaHoraEntrada = fechaHoraEntrada;
    this->fechaHoraSalida = fechaHoraSalida;
    this->partida = partida;
    this->jugador = jugador;
};

void EstadoJugador::setFechaHoraEntrada(DtFechaHora *fechaHoraEntrada)
{
    this->fechaHoraEntrada = fechaHoraEntrada;
};

void EstadoJugador::setFechaHoraSalida(DtFechaHora *fechaHoraSalida)
{
    this->fechaHoraSalida = fechaHoraSalida;
};

void EstadoJugador::setPartida(PartidaMultijugador *partida)
{
    this->partida = partida;
};

PartidaMultijugador *EstadoJugador::getPartida()
{
    return this->partida;
};

Jugador * EstadoJugador::getJugador(){
    return this->jugador;
}

DtFechaHora *EstadoJugador::getFechaHoraEntrada()
{
    return this->fechaHoraEntrada;
};

DtFechaHora *EstadoJugador::getFechaHoraSalida()
{
    return this->fechaHoraSalida;
};

#endif
