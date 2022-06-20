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
    ICollection *estadosJugador;

public:
    PartidaMultijugador(bool, float, int, EEstado, DtFechaHora *, Videojuego *, Jugador *);
    ~PartidaMultijugador();
    void finalizarPartida();
    DtPartida *getDtPartida();
    void setEnVivo(bool);
    void setDuracion(float);
    bool getEnVivo();
    float getDuracion();
    void agregarEstadoJugador(EstadoJugador *);
    string darTipo();
    DtVideojuego* getVideojuego();
};

#endif