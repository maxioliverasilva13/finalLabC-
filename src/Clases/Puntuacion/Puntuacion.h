#ifndef PUNTUACION_HEADER
#define PUNTUACION_HEADER

#include "../Jugador/Jugador.cpp"

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
    void setPuntuacion(int);
    void setCreador(Jugador *);
    int getPuntuacion();
    Jugador *getCreador();
};

#endif