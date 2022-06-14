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

public:
    DtJugador(string email, string password, string nickname, string descripcion);
    string getNickname();
    string getDescripcion();
    string getTipo();
};

DtJugador::DtJugador(string email, string password, string nickname, string descripcion) : DtUsuario(email, password)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
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

#endif