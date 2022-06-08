#ifndef DTCONTRATACION_HEADER
#define DTCONTRATACION_HEADER

#include<iostream>

#include "../DtFechaHora/DtFechaHora.h"
#include "../../Enum/index.cpp"

class DtContratacion{
    private:
       int id;
       float  monto;
       ETipoPago tipoPago;
       DtFechaHora FechaHora;
       DtFechaHora FechaVencimiento;
       bool cancelada;
    public:
      DtContratacion(int id, float monto, ETipoPago tipoPago,DtFechaHora FechaHora, DtFechaHora FechaVencimiento,bool cancelada);
      int getId();
      ETipoPago getTipoPago();
      float getMonto();
      DtFechaHora getFechaHora();
      DtFechaHora getFechaVencimiento();
      bool getCancelada();
};

#endif