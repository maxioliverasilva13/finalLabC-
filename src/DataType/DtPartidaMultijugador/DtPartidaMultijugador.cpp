#ifndef DTPARTIDAMULTIJUGADOR_HEADER
#define DTMULTIJADOR_HEADER

#include <string>
#include <iostream>

using namespace std;
class DtPartidaMultijugador: public DtPartida
{
private:
    string nombreVideojuego;
    bool transmitidaEnVivo;
    ICollection * jugadores_unidos;   //string
    bool isOwner;
    string nicknameCreador;

public:
    DtPartidaMultijugador(int id, DtFechaHora * fecha, string nombreVideojuego,float duracion, bool transmitidaEnVivo, ICollection * jugadores_unidos,bool isOwner,string nicknameCreador, DtVideojuego * juego);
    string getNombreV();
    bool getTransmitidaEnVivo();
    ICollection * getJugadoresUnidos();
    bool isUserOwner();
    string getNicknameCreador();
    string getTipo();
};


DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora * fecha,string nombreVideojuego,float duracion, bool transmitidaEnVivo, ICollection * jugadores_unidos,bool isOwner,string nicknameCreador, DtVideojuego * juego) : DtPartida(id, fecha, duracion, juego) {
    this->nombreVideojuego = nombreVideojuego;
    this->transmitidaEnVivo =  transmitidaEnVivo;
    this->jugadores_unidos = jugadores_unidos;
    this->isOwner = isOwner;
    this->nicknameCreador = nicknameCreador;
}

string DtPartidaMultijugador::getTipo(){
    return "DtPartidaMultijugador";
}

string DtPartidaMultijugador::getNombreV(){
    return this->nombreVideojuego;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return this->transmitidaEnVivo;
}

ICollection * DtPartidaMultijugador::getJugadoresUnidos(){
    
    return this->jugadores_unidos;
}


bool DtPartidaMultijugador::isUserOwner(){
    return this->isOwner;
}

string DtPartidaMultijugador::getNicknameCreador(){
    return this->nicknameCreador;
}

#endif