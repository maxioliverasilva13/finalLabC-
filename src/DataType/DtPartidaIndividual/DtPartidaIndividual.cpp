#ifndef DTPARTIDAINDIVIDUAL_HEADER
#define DTPARTIDAINDIVIDUAL_HEADER

#include <string>
#include <iostream>

using namespace std;
class DtPartidaIndividual: public ICollectible
{
private:
    int id;
    bool continuar;
    float duracion; 
    EEstado estado;
    DtFechaHora * fecha;
    string nombreVideojuego;
    string nombreJugador;
public:
    DtPartidaIndividual(int, bool, EEstado, float, DtFechaHora*, string, string);
    int getId();
    DtFechaHora * getFecha();
    string getNombreV();
    string getNombreJ();
    bool getContinuar();
    EEstado getEstado();
    float getDuracion();
};

DtPartidaIndividual::DtPartidaIndividual(int id, bool continuar, EEstado estado, float duracion, DtFechaHora * fecha, string nombreVideojuego, string nombreJugador){
    this->id = id;
    this->continuar = continuar;
    this->estado = estado;
    this->duracion = duracion;
    this->fecha = fecha;
    this->nombreVideojuego = nombreVideojuego;
    this->nombreJugador = nombreJugador;
}

int DtPartidaIndividual::getId(){
    return this->id;
}

DtFechaHora * DtPartidaIndividual::getFecha(){
    return this->fecha;
}

string DtPartidaIndividual::getNombreV(){
    return this->nombreVideojuego;
}

string DtPartidaIndividual::getNombreJ(){
    return this->nombreJugador;
}

bool DtPartidaIndividual::getContinuar(){
    return this->transmitidaEnVivo;
}

EEstado DtPartidaIndividual::getEstado(){
    return this->estado;
}

float DtPartidaIndividual::getDuracion(){
    return this->duracion;
}

#endif