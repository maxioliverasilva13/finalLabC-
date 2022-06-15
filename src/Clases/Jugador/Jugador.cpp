#ifndef JUGADOR_HEADER
#define JUGADOR_HEADER

#include <iostream>
#include "../../DataType/DtContratacion/DtContratacion.cpp"
#include "../../Clases/Usuario/Usuario.cpp"
#include "../../Clases/Partida/Partida.cpp"

using namespace std;

class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
    IDictionary *partidas;       // JUGADOR VE (tiene) PARTIDAS.
    IDictionary *contrataciones; // JUGADOR VE (tiene) CONTRATACIONES.
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
    void continuar(int);
    void iniciarPartidaIndividual(bool);
    void suscribirseAVideojuego(int, string, ETipoPago);
    void cancelarContratacion(int);
    void finalizarPartida(int);
    DtContratacion *getContratacionByUser(string,DtFechaHora*);
    void agregarPartida(Partida *);
};

Jugador::Jugador(string nick, string desc, string email, string pass) : Usuario(email, pass)
{
    this->nickname = nick;
    this->descripcion = desc;
    this->partidas = new OrderedDictionary();
    this->contrataciones = new OrderedDictionary();
}

Jugador::~Jugador()
{
    cout << "Me borro";
}

void Jugador::setNickname(string nick)
{
    this->nickname = nick;
}

void Jugador::setDescripcion(string des)
{
    this->descripcion = des;
}

string Jugador::getNickname()
{
    return this->nickname;
}

string Jugador::getDescripcion()
{
    return this->descripcion;
}

DtContratacion *Jugador::getContratacionByUser(string nomV, DtFechaHora * fecha_sistema)
{
    IIterator * it = this->contrataciones->getIterator();
    Contratacion * current;

    DtContratacion * res = NULL;
    while (it->hasCurrent())
    {
        current = (Contratacion*)it->getCurrent();
        if(current->getActiva(fecha_sistema)){
            if(nomV == current->getVideojuego()){
                res = new DtContratacion(
                    current->getId(),
                    current->getMonto(), 
                    current->getTipoPago(), 
                    current->getFechaHora(),
                    current->getFechaVencimiento(), 
                    current->getCancelada()
                );
                break;
            }
        }
    }
    return res;
}

void Jugador::agregarPartida(Partida *part)
{
    Integer *idKey = new Integer(part->getId());
    this->partidas->add(idKey, part);
};

#endif
