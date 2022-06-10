#ifndef ESTADOJUGADOR_HEADER
#define ESTADOJUGADOR_HEADER

#include<iostream>
#include "../Partida/Partida.h"
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

#endif