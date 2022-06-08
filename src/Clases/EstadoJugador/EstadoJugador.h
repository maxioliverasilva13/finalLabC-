#ifndef ESTADOJUGADOR_HEADER
#define ESTADOJUGADOR_HEADER

#include<iostream>
#include "../Partida/Partida.h"

using namespace std;

class EstadoJugador {
    private:
      int fechaHoraEntrada;
      int fechaHoraSalida;
      Partida * partida = NULL;
    public:
      EstadoJugador(int, int, Partida *);
      void setFechaHoraEntrada(int);
      void setFechaHoraSalida(int);
      void setPartida(Partida *);
      int getFechaHoraEntrada();
      int getFechaHoraSalida();
      Partida * getPartida();
};

#endif