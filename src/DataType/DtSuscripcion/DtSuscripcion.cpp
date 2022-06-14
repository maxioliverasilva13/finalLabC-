#ifndef DTSUCRIPCION_HEADER
#define DTSUSCRIPCION_HEADER

#include <iostream>
#include <string>

using namespace std;

class DtSuscripcion
{
private:
    string nombreVideoJuego;
    ICollection *suscripciones;

public:
    DtSuscripcion(string nombreVideojuego, ICollection *suscripciones);
    string getNombreVideojuego();
    ICollection *getSuscripcion();
};

DtSuscripcion::DtSuscripcion(string nombreVideoJuego, ICollection *suscripciones)
{
    this->nombreVideoJuego = nombreVideoJuego;
    this->suscripciones = suscripciones;
};

string DtSuscripcion::getNombreVideojuego()
{
    return this->nombreVideoJuego;
}

ICollection *DtSuscripcion::getSuscripcion()
{
    return this->suscripciones;
}

#endif
