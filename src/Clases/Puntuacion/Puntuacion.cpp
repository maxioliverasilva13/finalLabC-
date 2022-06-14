#ifndef PUNTUACION_CPP
#define PUNTUACION_CPP


#include "Puntuacion.h"
#include <iostream>

using namespace std;

Puntuacion::Puntuacion(int puntuacion, Videojuego* juego, Jugador* creador ) {
    this->puntuacion = puntuacion;
    this->juego = juego;
    this->creador = creador;
}

void Puntuacion::setPuntuacion(int puntuacion) {
    this->puntuacion = puntuacion;
}

void Puntuacion::setCreador(Jugador* creador) {
    this->creador = creador; 
}

int Puntuacion::getPuntuacion() {
    return this->puntuacion;
}

Jugador* Puntuacion::getCreador() {
    return this->creador;
}

#endif