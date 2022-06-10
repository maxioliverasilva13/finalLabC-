#include "PartidaMultijugador.h"

using namespace std;


PartidaMultijugador::PartidaMultijugador(bool enVivo, float duracion, int id, int estado):Partida(id,estado) {
    this->enVivo = enVivo;
    this->duracion = duracion;
    this->comentarios = new  OrderedDictionary();
};


void PartidaMultijugador::finalizarPartida() {
  cout << "Finalizar Partida";
}

string PartidaMultijugador::getDtPartida(){
  return "DtPartidaMultijugador";
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

