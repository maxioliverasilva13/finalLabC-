#ifndef PARTIDAMULTIJUGADOR_FUNCTIONS
#define PARTIDAMULTIJUGADOR_FUNCTIONS
#include "PartidaMultijugador.h"

using namespace std;

#include <iostream>

PartidaMultijugador::PartidaMultijugador(bool enVivo, float duracion, EEstado estado, DtFechaHora *fecha, Videojuego *vj, Jugador *j) : Partida(estado, vj, fecha, j)
{
    this->enVivo = enVivo;
    this->duracion = duracion;
    this->estadosJugador = new List();
    this->comentarios = new OrderedDictionary();
};

string PartidaMultijugador::darTipo()
{
    return "PartidaMultijugador";
};

PartidaMultijugador::~PartidaMultijugador()
{
    this->creador->eliminarPartida(this);
    IIterator *itEstados = this->estadosJugador->getIterator();
    while (itEstados->hasCurrent())
    {
        EstadoJugador *estado = (EstadoJugador *)itEstados->getCurrent();
        this->estadosJugador->remove(estado);
        delete estado;
        itEstados->next();
    }

    delete itEstados;
}

void PartidaMultijugador::finalizarPartida(DtFechaHora * fechaSistema)
{
    IIterator* It = this->estadosJugador->getIterator();
    while (It->hasCurrent()) {
        EstadoJugador* Es = (EstadoJugador*)It->getCurrent();
        
        Es->setFechaHoraSalida(fechaSistema);
        It->next();
    }
    this->setEstado(FINALIZADA);
    delete It;

}

DtPartida *PartidaMultijugador::getDtPartida()
{
    DtPartida *dtpart = new DtPartida(this->getId(), this->getFecha(), 0);
    return dtpart;
};

void PartidaMultijugador::setEnVivo(bool enVivo)
{
    this->enVivo = enVivo;
};

void PartidaMultijugador::setDuracion(float duracion)
{
    this->duracion = duracion;
};

bool PartidaMultijugador::getEnVivo()
{
    return this->enVivo;
};

float PartidaMultijugador::getDuracion()
{
    return this->duracion;
};

void PartidaMultijugador::agregarEstadoJugador(EstadoJugador *status)
{
    this->estadosJugador->add(status);
}

#endif