#include "Comentario.h"
#include <iostream>

using namespace std;

Comentario::Comentario(string texto, DtFechaHora * FechaHoraEnvio){
        this->texto = texto;
        this->fechaHoraEnvio = FechaHoraEnvio;
}

void Comentario::setTexto(string texto) {
        this->texto = texto;
}

void Comentario::setFechaHoraEnvio(DtFechaHora * fechaHoraEnvio) {
        this->fechaHoraEnvio = fechaHoraEnvio;
}

void Comentario::setCreador(Jugador * creador) {
        this->creador = creador ;
}


string Comentario::getTexto(){
    return this->getTexto();
}

DtFechaHora* Comentario::getFechaHoraEnvio(){
    return this->fechaHoraEnvio;
}

Jugador* Comentario::getJugador(){
    return this->creador;
}