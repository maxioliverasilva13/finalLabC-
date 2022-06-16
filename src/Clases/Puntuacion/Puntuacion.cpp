#ifndef PUNTUACION_HEADER
#define PUNTUACION_HEADER

#include <iostream>

using namespace std;

class Puntuacion : public ICollectible
{
private:
    int puntuacion;
    Videojuego *juego;
    Jugador *creador;

public:
    Puntuacion(int, Videojuego *, Jugador *);
    ~Puntuacion();
    void setPuntuacion(int);
    void setCreador(Jugador *);
    int getPuntuacion();
    Jugador *getCreador();
};

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

void Puntuacion::setPuntuacion(int puntuacion)
{
    this->puntuacion = puntuacion;
}

void Puntuacion::setCreador(Jugador *creador)
{
    this->creador = creador;
}

int Puntuacion::getPuntuacion()
{
    return this->puntuacion;
}

Jugador *Puntuacion::getCreador()
{
    return this->creador;
}

#endif