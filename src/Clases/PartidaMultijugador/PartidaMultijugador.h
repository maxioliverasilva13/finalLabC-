#ifndef PARTIDAMULTIJUGADOR_HEADER
#define PARTIDAMULTIJUGADOR_HEADER

using namespace std;

#include <iostream>

class PartidaMultijugador : public Partida
{
private:
    bool enVivo;
    float duracion;
    IDictionary *comentarios;

public:
    ICollection *estadosJugador;
    PartidaMultijugador(bool, float, EEstado, DtFechaHora *, Videojuego *, Jugador *);
    ~PartidaMultijugador();
    void finalizarPartida(DtFechaHora *);
    DtPartida *getDtPartida();
    DtPartida *getDtPartida(bool isOwner);
    void setEnVivo(bool);
    void setDuracion(float);
    bool getEnVivo();
    float getDuracion();
    void agregarEstadoJugador(EstadoJugador *);
    string darTipo();
    DtVideojuego* getVideojuego();
    ICollection * getJugadoresUnidos();  // collecion de string con los nicknames de los jugadores.
};

#endif