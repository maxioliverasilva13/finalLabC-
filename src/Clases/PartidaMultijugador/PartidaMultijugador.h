#ifndef PARTIDAMULTIJUGADOR_HEADER
#define PARTIDAMULTIJUGADOR_HEADER

#include<iostream>
#include "../Partida/Partida.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"

using namespace std;

class PartidaMultijugador: public Partida {
    private:
      bool enVivo;
      float duracion;
      IDictionary * comentarios;
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