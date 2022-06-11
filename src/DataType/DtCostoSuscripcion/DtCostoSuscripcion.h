#ifndef DTCOSTOSUSCRIPCION_HEADER
#define DTCOSTOSUSCRIPCION_HEADER


#include "../../Enum/index.cpp"
using std::string;

class DtCostoSuscripcion  {
    private:
      ETipoSuscripcion tipo;   //No existe
      float costo;
    public:
      DtCostoSuscripcion(ETipoSuscripcion tipo, float costo);
      float getCosto();
      ETipoSuscripcion getTipo();
};

#endif