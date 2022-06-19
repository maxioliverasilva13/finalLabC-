#ifndef DTPARTIDAMULTIJUGADOR_HEADER
#define DTMULTIJADOR_HEADER

#include <string>
#include <iostream>

using namespace std;
class DtPartidaMultijugador: public ICollectible
{
private:
    int id;
    DtFechaHora * fecha;
    string nombreVideojuego;
    bool transmitidaEnVivo;
    ICollection * jugadores_unidos;   //string
    bool isOwner;

public:
    DtPartidaMultijugador(int id, DtFechaHora * fecha, string nombreVideojuego, bool transmitidaEnVivo, ICollection * jugadores_unidos,bool isOwner);
    int  getId();
    DtFechaHora * getFecha();
    string getNombreV();
    bool getTransmitidaEnVivo();
    ICollection * getJugadoresUnidos();
    bool isUserOwner();
};


DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora * fecha,string nombreVideojuego, bool transmitidaEnVivo, ICollection * jugadores_unidos,bool isOwner){
    this->id = id;
    this->nombreVideojuego = nombreVideojuego;
    this->transmitidaEnVivo =  transmitidaEnVivo;
    this->jugadores_unidos = jugadores_unidos;
    this->isOwner = isOwner;
}

int DtPartidaMultijugador::getId(){
    return this->id;
}


DtFechaHora * DtPartidaMultijugador::getFecha(){
    return this->fecha;
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

#endif