#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../DataType/DtContratacion/DtContratacion.h"

using namespace std;

class Jugador : public Usuario, ICollectible {
    private:
        string nickname;
        string descripcion;
        IDictionary * partidas;          //JUGADOR VE (tiene) PARTIDAS.
        IDictionary * contrataciones;    //JUGADOR VE (tiene) CONTRATACIONES.
    public:
        Jugador(string, string, string, string);
        ~Jugador();
        void setNickname(string);
        void setDescripcion(string);
        string getNickname();
        string getDescripcion();
        void iniciarPartidaMultijugador(ICollection *, bool);      // recibe coleccion de Jugadores.
        ICollection * listarVideojuegosActivos(string);            // retorna coleccion de Strings (nombres de videojuegos)
        ICollection * listarHistorialPartidasFinalizadas(string);  // retorna coleccion de DtPartida (partidas finalizadas)
        void continuar(int);
        void iniciarPartidaIndividual(bool);
        void suscribirseAVideojuego(int, string, ETipoPago);
        void cancelarContratacion(int);
        void finalizarPartida(int);
        DtContratacion * getContratacionByUser(int);   
        void agregarPartida(Partida *);
        
};

#endif