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

float calcularDifEnMinutos(DtFechaHora * fechaInicio, DtFechaHora * fechaFin) {
    // asumo que la fechaInicio es menor a la de fin

    //todo en minutos
    float difDias = (fechaFin->getDay() - fechaInicio->getDay()) * 1440; // 1440 son los minutos de un dia
    float difMeses = (fechaFin->getMonth() - fechaInicio->getMonth()) * 43800; // 43800 son los minutos de un mes
    float difAnios = (fechaFin->getYear() - fechaInicio->getYear()) * 525600; // 525600 son los minutos de un año
    float difMinutos = (fechaFin->getMinute() - fechaInicio->getMinute());
    float difHoras = (fechaFin->getHour() - fechaInicio->getHour()) * 60; // 60 son los minutos de una hora

    return difDias + difMeses + difAnios + difMinutos + difHoras;
}

void PartidaMultijugador::finalizarPartida(DtFechaHora * fechaSistema)
{
    IIterator* It = this->estadosJugador->getIterator();
    while (It->hasCurrent()) {
        EstadoJugador* Es = (EstadoJugador*)It->getCurrent();
        
        Es->setFechaHoraSalida(fechaSistema);

        if (Es->getJugador()->getNickname() == this->creador->getNickname()) {
            PartidaMultijugador * partM = (PartidaMultijugador *)Es->getPartida();

            DtFechaHora * fechaInicio = partM->getFecha();
            DtFechaHora * fechaFin = fechaSistema;

            cout << fechaInicio->getHour() << " : " << fechaInicio->getMinute();
            cout << fechaFin->getHour() << " : " << fechaFin->getMinute();
            system("PAUSE");
            float duracion = calcularDifEnMinutos(fechaInicio, fechaFin);
            this->setDuracion(duracion);
        }

        It->next();
    }
    this->setEstado(FINALIZADA);
    delete It;

}
DtVideojuego* PartidaMultijugador::getVideojuego() {
  DtVideojuego* Juego = new DtVideojuego(videojuego->getNombre(), videojuego->getDescripcion(), videojuego->getPromedio_puntuacion(), videojuego->getPuntuaciones(), videojuego->getCategorias(), videojuego->getSuscripciones(), videojuego->getDesarrollador()->getNomEmpresa(), videojuego->getTotalHorasJugadas());
  return Juego;
}

DtPartida *PartidaMultijugador::getDtPartida()
{
    DtPartidaMultijugador *dtpart = new DtPartidaMultijugador(this->getId(), this->getFecha(),this->videojuego->getNombre(), this->getDuracion(), this->enVivo, this->getJugadoresUnidos(), true, this->creador->getNickname(), this->videojuego->getDtVideojuego());
    return dtpart;
};

DtPartida *PartidaMultijugador::getDtPartida(bool isOwner)
{
    DtPartidaMultijugador *dtpart = new DtPartidaMultijugador(this->getId(), this->getFecha(),this->videojuego->getNombre(), this->getDuracion(), this->enVivo, this->getJugadoresUnidos(), isOwner, this->creador->getNickname(), this->videojuego->getDtVideojuego());
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


 ICollection * PartidaMultijugador::getJugadoresUnidos(){

    ICollection * res = new List();

    IIterator * it = this->estadosJugador->getIterator();
    
    EstadoJugador * current;
    string jugadorNicknameCurrent;
    while (it->hasCurrent()){

        current = (EstadoJugador*)it->getCurrent();
        if(current->getFechaHoraSalida() == NULL || current->getFechaHoraSalida()->getDay() > 31){
            jugadorNicknameCurrent = current->getJugador()->getNickname();
            char *charNickJugador = const_cast<char *>(jugadorNicknameCurrent.c_str()); // paso de string a char (para poder implementar la key)
            ICollectible * item = new String(charNickJugador);
            res->add(item);
        }
        it->next();
    }
    delete it;
    return res;
    
 };

#endif