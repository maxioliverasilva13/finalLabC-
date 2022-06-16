#ifndef DTSUCRIPCION_HEADER
#define DTSUSCRIPCION_HEADER

#include <iostream>
#include <string>

using namespace std;

class DtPartidaMultijugador:  public ICollectible
{
private:
    int id;
    DtFechaHora * fechaHora;
    string nombreV;
    bool transmitidaEnVivo;
    string nicknameCreador;
    ICollection  * jugadores;   //nicknames de jugadores unidos.
    bool isOwner;
public:
    DtPartidaMultijugador(
    int id,
    string nombreVideojuego,
    DtFechaHora * fechaHora, 
    bool transmitidaEnVivo,
    string nicknameCreador,
    ICollection  * jugadores,
    bool isOwner);
    
    int getId();
    DtFechaHora * getFecha();
    string getNombreV();
    bool getTransmitidaEnVivo();
    ICollection * getJugadores();
    bool isOwnerPartida();
    string getNicknameCreador();
};

DtPartidaMultijugador::DtPartidaMultijugador(int id, DtFechaHora * fecha,string nombreV,bool transmitidaEnVivo, ICollection * jugadores, bool isOwner,string nicknameCreador){
    this->id = id;
    this->fechaHora = fecha;
    this->nombreV = nombreV;
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->jugadores = jugadores;
    this->isOwner = isOwner;
    this->nicknameCreador = nicknameCreador;
}


int DtPartidaMultijugador::getId(){
    return this->id;
}

DtFechaHora * DtPartidaMultijugador::getFecha(){
    return this->fechaHora;
}

string * DtPartidaMultijugador::getNombreV(){
    return this->nombreV;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return this->transmitidaEnVivo;
}

string DtPartidaMultijugador::getNicknameCreador(){
    return this->nick
}

bool DtPartidaMultijugador::isOwnerPartida(){
    return this->id;
}


ICollection * DtPartidaMultijugador::getJugadores(){
    return this->jugadores;
}



#endif
