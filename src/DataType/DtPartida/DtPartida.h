#ifndef DTPARTIDA_HEADER
#define DTPARTIDA_HEADER

#include<iostream>

#include "../DtFechaHora/DtFechaHora.h"

class DtPartida{
    private:
       int id;
       DtFechaHora * fecha;
       int duracion;
    public:
      DtPartida(int, DtFechaHora *, int);
      int getId();
      DtFechaHora * getFecha();
      int getDuracion();
};

#endif