#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include <iostream>




class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
    IDictionary *partidas;       // JUGADOR VE (tiene) PARTIDAS.
    IDictionary *contrataciones; // JUGADOR VE (tiene) CONTRATACIONES
    ICollection *estadosJugador;

public:
    Jugador(string, string, string, string);
    ~Jugador();
    void setNickname(string);
    void setDescripcion(string);
    string getNickname();
    string getDescripcion();
    void iniciarPartidaMultijugador(ICollection *, bool);    // recibe coleccion de Jugadores.
    ICollection *listarVideojuegosActivos(string);           // retorna coleccion de Strings (nombres de videojuegos)
    ICollection *listarHistorialPartidasFinalizadas(string); // retorna coleccion de DtPartida (partidas finalizadas)
    void continuarPartida(int);
    void iniciarPartidaIndividual(bool);
    void suscribirseAVideojuego(Suscripcion *, ETipoPago,DtFechaHora *);
    void cancelarContratacion(int);
    void finalizarPartida(int);
    DtContratacion *getContratacionByUser(string,DtFechaHora*);
    void agregarPartida(Partida *);
    void eliminarSuscripcion(ICollectible *);
    void eliminarPartida(ICollectible *);
    void eliminarEstadosJugador(ICollectible *);
    string getTipo();
    ICollection *listarVideoJuegosActivos();
    void iniciarPartidaIndividual(bool, Videojuego *);
    ICollection * listarPartidasUnido();
};

#endif
