#ifndef PARTIDAMULTIJUGADOR_HEADER
#define PARTIDAMULTIJUGADOR_HEADER

#include<iostream>
#include "../Partida/Partida.h"
#include "../EstadoJugador/EstadoJugador.h"
#include "../../ICollection/interfaces/ICollection.h"

using namespace std;

class PartidaMultijugador: public Partida {
    private:
      bool enVivo;
      float duracion;
    public:
      ICollection * estadosJugador;
      PartidaMultijugador(bool, float, int, EEstado, DtFechaHora *);
      void finalizarPartida();
      DtPartida * getDtPartida();
      void setEnVivo(bool);
      void setDuracion(float);
      bool getEnVivo();
      float getDuracion();
      void agregarEstadoJugador(EstadoJugador *);
};

#endif