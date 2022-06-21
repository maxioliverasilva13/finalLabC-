#ifndef DTPARTIDAINDIVIDUAL_HEADER
#define DTPARTIDAINDIVIDUAL_HEADER

#include <string>
#include <iostream>

using namespace std;
class DtPartidaIndividual: public DtPartida
{
private:
    bool continuar;
    EEstado estado;
    string nombreVideojuego;
    string nombreJugador;
public:
    DtPartidaIndividual(int, bool, EEstado, float, DtFechaHora*, string, string, DtVideojuego *);
    string getNombreV();
    string getNombreJ();
    bool getContinuar();
    string getTipo();
};

DtPartidaIndividual::DtPartidaIndividual(int id, bool continuar, EEstado estado, float duracion, DtFechaHora * fecha, string nombreVideojuego, string nombreJugador, DtVideojuego * juego) : DtPartida(id, fecha, duracion, juego){
    this->continuar = continuar;
    this->estado = estado;
    this->nombreVideojuego = nombreVideojuego;
    this->nombreJugador = nombreJugador;
}

string DtPartidaIndividual::getTipo(){
    return "DtPartidaIndividual";
}

string DtPartidaIndividual::getNombreV(){
    return this->nombreVideojuego;
}

string DtPartidaIndividual::getNombreJ(){
    return this->nombreJugador;
}

bool DtPartidaIndividual::getContinuar(){
    return this->continuar;
}


#endif