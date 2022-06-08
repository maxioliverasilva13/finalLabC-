#ifndef PARTIDA_HEADER
#define PARTIDA_HEADER

#include<iostream>

using namespace std;

class Partida {
    private:
      int id;
      int estado;
    public:
      Partida(int,int);
      string darNombreJuego();
      void setEstado(int);
      void setId(int);
      int getEstado();
      int getId();
      virtual string getDtPartida() = 0;
      virtual void finalizarPartida() = 0;
};

#endif