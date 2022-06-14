#ifndef SUSCRIPCION_HEADER
#define SUSCRIPCION_HEADER

#include <iostream>

using namespace std;

#include "../../Enum/index.cpp"
#include "../../DataType/DtInfoSuscripcion/DtInfoSuscripcion.h"
#include "../Videojuego/Videojuego.h"

class Suscripcion : public ICollectible
{
private:
    int id;
    float precio;
    EPeriodo periodo;
    Videojuego *videojuego;
    IDictionary *contrataciones;

public:
    Suscripcion(int, float, EPeriodo, Videojuego *);
    ~Suscripcion();
    int getId();
    float getPrecio();
    EPeriodo getPeriodo();
    void setId(int);
    void setPeriodo(EPeriodo);
    void setPrecio(float);
    string darNombreJuego();
    bool jugadorTieneContratacion(string);
    DtInfoSuscripcion *getDatosSuscripcion();
};

#endif