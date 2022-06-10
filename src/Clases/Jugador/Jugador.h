#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
#include "../Partida/Partida.h"
using namespace std;

class Jugador : public Usuario  {
    private:
        string nickname;
        string descripcion;
        OrderedDictionary * partidas;
        // contratacion ** contrataciones; //JUGADOR VE (tiene) CONTRATACIONES.
        
    public:
        Jugador(string, string, string, string);
        ~Jugador();
        void setNickname(string);
        void setDescripcion(string);
        string getNickname();
        string getDescripcion();
        string * listarVideojuegosActivos(string);              // cambiar a collection
        DtPartida * listarHistorialPartidasFinalizadas(string); // cambiar a collection
        void continuar(int);
        void iniciarPartidaIndividual(bool);
        void iniciarPartidaMultijugador(OrderedDictionary * , bool);      // el parámetro recibiría colección de jugadores.
        void suscribirseAVideojuego(int, string, ETipoPago);
        void cancelarContratacion(int);
        void finalizarPartida(int);
        void getContratacionByUser(int);   
        void agregarPartida(Partida *);
        
};

#endif