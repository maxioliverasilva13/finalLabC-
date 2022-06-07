#ifndef PARTIDAMULTIJUGADOR_HEADER
#define PARTIDAMULTIJUGADOR_HEADER

#include<iostream>
#include "../Partida/Partida.h"

using namespace std;

class PartidaMultijugador: public Partida {
    private:
      bool enVivo;
      float duracion;
    public:
      PartidaMultijugador(bool, float, int, int);
      void finalizarPartida();
      string getDtPartida();
      void setEnVivo(bool);
      void setDuracion(float);
      bool getEnVivo();
      float getDuracion();
};

#endif