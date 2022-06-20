
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
    DtVideojuego* getVideojuego();
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

DtVideojuego* DtPartida::getVideojuego() {
    DtVideojuego* juego = new DtVideojuego(this->juego->getNombreVideojuego(), this->juego->getDescripcionVideojuego(), this->juego->getPromedioPuntuaciones(), this->juego->getPuntuaciones(), this->juego->getCategorias(), this->juego->getSuscripciones());
    return juego;
}

#endif
