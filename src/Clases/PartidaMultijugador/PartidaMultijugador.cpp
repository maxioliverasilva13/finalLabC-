#include "PartidaMultijugador.h"
#include "../../DataType/DtPartida/DtPartida.h"

using namespace std;


PartidaMultijugador::PartidaMultijugador(bool enVivo, float duracion, int id, EEstado estado, DtFechaHora * fecha):Partida(id,estado, fecha) {
    this->enVivo = enVivo;
    this->duracion = duracion;
    this->estadosJugador = new List();
    this->comentarios = new  OrderedDictionary();
};


void PartidaMultijugador::finalizarPartida() {
  cout << "Finalizar Partida";
}

DtPartida * PartidaMultijugador::getDtPartida(){
  DtPartida * dtpart = new DtPartida(this->getId(),this->getFecha(),0);
  return dtpart;
};

void PartidaMultijugador::setEnVivo(bool enVivo){
    this->enVivo = enVivo;
};

void PartidaMultijugador::setDuracion(float duracion){
    this->duracion = duracion;
};

bool PartidaMultijugador::getEnVivo(){
    return this->enVivo;
};

float PartidaMultijugador::getDuracion(){
    return this->duracion;
};

void PartidaMultijugador::agregarEstadoJugador(EstadoJugador * status) {
    this->estadosJugador->add(status);
}