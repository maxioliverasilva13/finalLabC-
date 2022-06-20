#ifndef DTJUGADOR_HEADER
#define DTJUGADOR_HEADER

#include <string>
#include <iostream>

using namespace std;
class DtJugador : public DtUsuario
{
private:
    string nickname;
    string descripcion;
    int sizeContrataciones;

public:
    DtJugador(string email, string password, string nickname, string descripcion, int);
    string getNickname();
    string getDescripcion();
    string getTipo();
    int getSizeContrataciones();
};

DtJugador::DtJugador(string email, string password, string nickname, string descripcion,  int sizeContrataciones = 0) : DtUsuario(email, password)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
    this->sizeContrataciones = sizeContrataciones;
};

string DtJugador::getNickname()
{
    return this->nickname;
}

string DtJugador::getDescripcion()
{
    return this->descripcion;
}

// es un virtual para hacer comprobaciones con el nombre de la instancia.
string DtJugador::getTipo()
{
    return "DtJugador";
}

int DtJugador::getSizeContrataciones(){
    return this->sizeContrataciones;
}

#endif