#ifndef PUNTUACION_HEADER
#define PUNTUACION_HEADER

#include <iostream>

using namespace std;

class Puntuacion : public ICollectible
{
private:
    double puntuacion;
    Videojuego *juego;
    Jugador *creador;

public:
    Puntuacion(int, Videojuego *, Jugador *);
    void setPuntuacion(double);
    void setCreador(Jugador *);
    double getPuntuacion();
    Jugador *getCreador();
};

Puntuacion::Puntuacion(int puntuacion, Videojuego *juego, Jugador *creador)
{
    this->puntuacion = puntuacion;
    this->juego = juego;
    this->creador = creador;
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