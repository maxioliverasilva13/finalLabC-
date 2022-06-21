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
    void iniciarPartidaMultijugador(ICollection *, bool, Videojuego *, DtFechaHora *);    // recibe coleccion de Jugadores.
    ICollection *listarVideojuegosActivos(string);           // retorna coleccion de Strings (nombres de videojuegos)
    ICollection *listarHistorialPartidasFinalizadas(string); // retorna coleccion de DtPartida (partidas finalizadas)
    void continuarPartida(int);
    void suscribirseAVideojuego(Suscripcion *, ETipoPago,DtFechaHora *);
    void cancelarContratacion(int);
    void finalizarPartida(int, DtFechaHora *);
    DtContratacion *getContratacionByUser(string,DtFechaHora*);
    void agregarPartida(Partida *);
    void eliminarSuscripcion(ICollectible *);
    void eliminarPartida(ICollectible *);
    void eliminarEstadosJugador(ICollectible *);
    string getTipo();
    ICollection *listarVideoJuegosActivos(DtFechaHora *);
    void iniciarPartidaIndividual(bool, Videojuego *, DtFechaHora *);
    IDictionary* getPartidas();
    ICollection * listarPartidasUnido();
    void  abandonarPartida(int idPartida,DtFechaHora * fechaSistema);
    Partida * partidaMasLarga();
    int getSizeContrataciones();
    DtJugador * getDtJugador();

};

#endif
