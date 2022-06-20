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
            DtFechaHora * fechaInicio = Es->getFechaHoraEntrada();
            DtFechaHora * fechaFin = fechaSistema;
            float duracion = calcularDifEnMinutos(fechaInicio, fechaFin);
            this->setDuracion(duracion);
        }

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


 ICollection * PartidaMultijugador::getJugadoresUnidos(){

    ICollection * res = new List();
    IIterator * it = this->estadosJugador->getIterator();
    
    EstadoJugador * current;
    string jugadorNicknameCurrent;
    while (it->hasCurrent()){

        current = (EstadoJugador*)it;

        if(current->getFechaHoraSalida() == NULL){
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