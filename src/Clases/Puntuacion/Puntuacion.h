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
    ~Puntuacion();
    void setPuntuacion(double);
    void setCreador(Jugador *);
    double getPuntuacion();
    Jugador *getCreador();
};

#endif