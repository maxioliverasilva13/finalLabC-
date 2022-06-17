#ifndef DTINFOSUSCRIPCION_HEADER
#define DTINFOSUSCRIPCION_HEADER

#include <iostream>

using namespace std;
class DtInfoSuscripcion:public ICollectible
{
private:
    int id;
    EPeriodo periodo;
    float precio;
    bool suscrito;

public:
    DtInfoSuscripcion(int id, EPeriodo periodo, float precio, bool suscrito);
    int getId();
    EPeriodo getPeriodo();
    float getPrecio();
    bool getSuscrito();
};

DtInfoSuscripcion::DtInfoSuscripcion(int id, EPeriodo periodo, float precio, bool suscrito)
{
    this->id = id;
    this->periodo = periodo;
    this->precio = precio;
    this->suscrito = suscrito;
};

int DtInfoSuscripcion::getId()
{
    return this->id;
}

EPeriodo DtInfoSuscripcion::getPeriodo()
{
    return this->periodo;
}

float DtInfoSuscripcion::getPrecio()
{
    return this->precio;
}

bool DtInfoSuscripcion::getSuscrito()
{
    return this->suscrito;
}

#endif
