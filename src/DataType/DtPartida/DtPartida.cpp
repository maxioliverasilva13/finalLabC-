
#ifndef DTPARTIDA_HEADER
#define DTPARTIDA_HEADER

#include <iostream>
using namespace std;

class DtPartida : public ICollectible
{
private:
    int id;
    DtFechaHora *fecha;
    int duracion;
    DtVideojuego* juego;

public:
    DtPartida(int, DtFechaHora *, int, DtVideojuego*);
    int getId();
    DtFechaHora *getFecha();
    int getDuracion();
    DtVideojuego* getJuego();
    virtual string getTipo() = 0;
};

DtPartida::DtPartida(int id, DtFechaHora *fecha, int duracion, DtVideojuego* juego)
{
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
    this->juego = juego;
};

int DtPartida::getId()
{
    return this->id;
}

DtFechaHora *DtPartida::getFecha()
{
    return this->fecha;
}

int DtPartida::getDuracion()
{
    return this->duracion;
}

DtVideojuego* DtPartida::getJuego() {
    return this->juego;
}

#endif
