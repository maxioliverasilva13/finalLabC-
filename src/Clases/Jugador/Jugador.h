#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
using namespace std;

class jugador : public usuario {
    private:
        string nickname;
        string descripcion;
        partida ** partidas;            //JUGADOR VE (tiene) PARTIDAS.
        contratacion ** contrataciones; //JUGADOR VE (tiene) CONTRATACIONES.
        
    public:
        jugador(string, string, string, string);
        void setNickname(string);
        void setDescripcion(string);
        string getNickname();
        string getDescripcion();
        void iniciarPartidaMultijugador(jugador **, bool);
        string * listarVideojuegosActivos(string);              // cambiar a collection
        DtPartida * listarHistorialPartidasFinalizadas(string); // cambiar a collection
        void continuar(int);
        void iniciarPartidaIndividual(bool);
        void iniciarPartidaMultijugador(jugador **, bool);      // el parámetro recibiría colección de jugadores.
        void suscribirseAVideojuego(int, string, ETipoPago);
        void cancelarContratacion(int);
        void finalizarPartida(int);
        void getContratacionByUser(int);        
};

#endif