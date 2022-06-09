#ifndef PUNTUACION_HEADER
#define PUNTUACION_HEADER
#include "../Jugador/Jugador.cpp"

#include<iostream>

using namespace std;

class Puntuacion {
    private:
        int puntuacion;
        Jugador* creador;
    public:
        Puntuacion(int, Jugador*);
        void setPuntuacion(int);
        void setCreador(Jugador*);
        int getPuntuacion();
        Jugador* getJugador();
};

#endif