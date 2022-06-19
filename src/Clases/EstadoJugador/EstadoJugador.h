#ifndef ESTADOJUGADOR_HEADER
#define ESTADOJUGADOR_HEADER

#include <iostream>

using namespace std;

class EstadoJugador : public ICollectible
{
private:
    DtFechaHora *fechaHoraEntrada;
    DtFechaHora *fechaHoraSalida;
    Partida *partida;
    Jugador *jugador;

public:
    EstadoJugador(DtFechaHora *, DtFechaHora *, Partida *, Jugador *);
    ~EstadoJugador();
    void setFechaHoraEntrada(DtFechaHora *);
    void setFechaHoraSalida(DtFechaHora *);
    void setPartida(Partida *);
    DtFechaHora *getFechaHoraEntrada();
    DtFechaHora *getFechaHoraSalida();
    Jugador * getJugador();
    Partida *getPartida();
};


#endif