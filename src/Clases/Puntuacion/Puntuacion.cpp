#ifndef PUNTUACION_FUNCTIONS
#define PUNTUACION_FUNCTIONS
#include "Puntuacion.h"

#include <iostream>

using namespace std;

Puntuacion::Puntuacion(int puntuacion, Videojuego *juego, Jugador *creador)
{
    this->puntuacion = puntuacion;
    this->juego = juego;
    this->creador = creador;
}

Puntuacion::~Puntuacion()
{
    this->juego = NULL;
    this->creador = NULL;
}

void Puntuacion::setPuntuacion(double puntuacion)
{
    this->puntuacion = puntuacion;
}

void Puntuacion::setCreador(Jugador *creador)
{
    this->creador = creador;
}

double Puntuacion::getPuntuacion()
{
    return this->puntuacion;
}

Jugador *Puntuacion::getCreador()
{
    return this->creador;
}

#endif