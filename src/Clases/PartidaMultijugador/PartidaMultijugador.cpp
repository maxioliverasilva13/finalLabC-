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
    IIterator* It = this->estadosJugador->getIterator();
    while (It->hasCurrent()) {
        EstadoJugador* Es = (EstadoJugador*)It->getCurrent();
        
        time_t t = time(0);
        tm *now = localtime(&t);
        int dia = now->tm_mday;
        int mes = 1 + now->tm_mon;
        int anio = 1900 + now->tm_year;
        int hora = now->tm_hour;
        int minuto = now->tm_min;
        DtFechaHora *ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
        
        Es->setFechaHoraSalida(ahora);
        It->next();
    }
        this->setEstado(FINALIZADA);
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