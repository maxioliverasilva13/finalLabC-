#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
using namespace std;

class Jugador : public Usuario {
    private:
        string nickname;
        string descripcion;
        partida ** partidas;            //JUGADOR VE (tiene) PARTIDAS.
        contratacion ** contrataciones; //JUGADOR VE (tiene) CONTRATACIONES.
        
    public:
        Jugador(string, string, string, string);
        void setNickname(string);
        void setDescripcion(string);
        string getNickname();
        string getDescripcion();
        void iniciarPartidaMultijugador(Jugador **, bool);
        string * listarVideojuegosActivos(string);              // cambiar a collection
        DtPartida * listarHistorialPartidasFinalizadas(string); // cambiar a collection
        void continuar(int);
        void iniciarPartidaIndividual(bool);
        void iniciarPartidaMultijugador(Jugador **, bool);      // el parámetro recibiría colección de jugadores.
        void suscribirseAVideojuego(int, string, ETipoPago);
        void cancelarContratacion(int);
        void finalizarPartida(int);
        void getContratacionByUser(int);        
};

#endif