#ifndef DTCOSTOSUSCRIPCION_HEADER
#define DTCOSTOSUSCRIPCION_HEADER


#include "../../Enum/index.cpp"
#include "../../ICollection/interfaces/ICollectible.h"

using std::string;

class DtCostoSuscripcion : public ICollectible  {
    private:
      EPeriodo tipo;   //No existe
      float costo;
    public:
      DtCostoSuscripcion(EPeriodo tipo, float costo);
      float getCosto();
      EPeriodo getTipo();
};

#endif