#ifndef DTCOSTOSUSCRIPCION_HEADER
#define DTCOSTOSUSCRIPCION_HEADER

#include <iostream>
#include <string>

using namepsace std;
class DtCostoSuscripcion : public ICollectible
{
private:
    EPeriodo tipo; // No existe
    float costo;

public:
    DtCostoSuscripcion(EPeriodo tipo, float costo);
    float getCosto();
    EPeriodo getTipo();
};

DtCostoSuscripcion::DtCostoSuscripcion(EPeriodo tipo, float costo)
{
    this->tipo = tipo;
    this->costo = costo;
}

EPeriodo DtCostoSuscripcion::getTipo()
{
    return this->tipo;
}

float DtCostoSuscripcion::getCosto()
{
    return this->costo;
}

#endif