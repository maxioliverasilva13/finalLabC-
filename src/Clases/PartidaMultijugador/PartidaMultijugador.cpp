#ifndef PARTIDAMULTIJUGADOR_FUNCTIONS
#define PARTIDAMULTIJUGADOR_FUNCTIONS
#include "PartidaMultijugador.h"

using namespace std;

#include <iostream>

PartidaMultijugador::PartidaMultijugador(bool enVivo, float duracion, int id, EEstado estado, DtFechaHora *fecha, Videojuego *vj, Jugador *j) : Partida(id, estado, vj, fecha, j)
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

void PartidaMultijugador::finalizarPartida()
{
    IIterator* It = this->estadosJugador->getIterator();
    while (It->hasCurrent()) {
        EstadoJugador* Es = (EstadoJugador*)It->getCurrent();
        
        time_t t = time(0);
        tm *now = localtime(&t);
        int dia = now->tm_mday;
        int mes = 1 + now->tm_mon;
        int anio = 1900 + now->tm_year;
        int hora = now->tm_hour;
        int minuto = now->tm_min;
        DtFechaHora *ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
        
        Es->setFechaHoraSalida(ahora);
        It->next();
        delete Es;
    }
    this->setEstado(FINALIZADA);
    cout << "Finalizar Partida";
    delete It;

}
DtVideojuego* PartidaIndividual::getVideojuego() {
  DtVideojuego* Juego = new DtVideojuego(videojuego->getNombre(), videojuego->getDescripcion(), videojuego->getPromedio_puntuacion(), videojuego->getPuntuaciones(), videojuego->getCategorias(), videojuego->getSuscripciones());
  return Juego;
}

DtPartida *PartidaMultijugador::getDtPartida()
{
    DtPartida *dtpart = new DtPartida(this->getId(), this->getFecha(), 0, getVideojuego());
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