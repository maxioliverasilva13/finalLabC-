#ifndef PARTIDAINDIVIDUAL_HEADER
#define PARTIDAINDIVIDUAL_HEADER

#include<iostream>
#include "../Partida/Partida.h"

using namespace std;

class PartidaIndividual: public Partida {
    private:
      bool nueva;
    public:
      PartidaIndividual(bool, int, int);
      void continuarPartida();
      void setNueva(bool);
      bool getNueva();
      void finalizarPartida();
      string getDtPartida();
};

#endif