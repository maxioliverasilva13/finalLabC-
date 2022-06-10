#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"

using namespace std;

class Jugador : public Usuario, ICollectible {
    private:
        string nickname;
        string descripcion;
        IDictionary * partidas;          //JUGADOR VE (tiene) PARTIDAS.
        IDictionary * contrataciones;    //JUGADOR VE (tiene) CONTRATACIONES.
    public:
        Jugador(string, string, string, string);
        void setNickname(string);
        void setDescripcion(string);
        string getNickname();
        string getDescripcion();
        void iniciarPartidaMultijugador(ICollection *, bool);      // recibe coleccion de Jugadores.
        ICollection * listarVideojuegosActivos(string);            // retorna coleccion de Strings (nombres de videojuegos)
        ICollection * listarHistorialPartidasFinalizadas(string);  // retorna coleccion de DtPartida (partidas finalizadas)
        void continuar(int);
        void iniciarPartidaIndividual(bool);
        void iniciarPartidaMultijugador(ICollection *, bool);      // recibiría colección de jugadores por parámetro.
        void suscribirseAVideojuego(int, string, ETipoPago);
        void cancelarContratacion(int);
        void finalizarPartida(int);
        void getContratacionByUser(int);        
};

#endif