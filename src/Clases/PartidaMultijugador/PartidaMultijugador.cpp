#ifndef PARTIDAMULTIJUGADOR_HEADER
#define PARTIDAMULTIJUGADOR_HEADER

using namespace std;

#include <iostream>

using namespace std;

class PartidaMultijugador : public Partida
{
private:
    bool enVivo;
    float duracion;
    IDictionary *comentarios;
    ICollection *estadosJugador;

public:
    PartidaMultijugador(bool, float, int, EEstado, DtFechaHora *, Videojuego *);
    void finalizarPartida();
    DtPartida *getDtPartida();
    void setEnVivo(bool);
    void setDuracion(float);
    bool getEnVivo();
    float getDuracion();
    void agregarEstadoJugador(EstadoJugador *);
};

PartidaMultijugador::PartidaMultijugador(bool enVivo, float duracion, int id, EEstado estado, DtFechaHora *fecha, Videojuego *vj) : Partida(id, estado, vj, fecha)
{
    this->enVivo = enVivo;
    this->duracion = duracion;
    this->estadosJugador = new List();
    this->comentarios = new OrderedDictionary();
};

void PartidaMultijugador::finalizarPartida()
{
    cout << "Finalizar Partida";
}

DtPartida *PartidaMultijugador::getDtPartida()
{
    DtPartida *dtpart = new DtPartida(this->getId(), this->getFecha(), 0);
    return dtpart;
};

void PartidaMultijugador::setEnVivo(bool enVivo)
{
    this->enVivo = enVivo;
};

void PartidaMultijugador::setDuracion(float duracion)
{
    this->duracion = duracion;
};

bool PartidaMultijugador::getEnVivo()
{
    return this->enVivo;
};

float PartidaMultijugador::getDuracion()
{
    return this->duracion;
};

void PartidaMultijugador::agregarEstadoJugador(EstadoJugador *status)
{
    this->estadosJugador->add(status);
}

#endif