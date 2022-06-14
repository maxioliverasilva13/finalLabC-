#include "PartidaIndividual.h"
#include "../../DataType/DtPartida/DtPartida.h"

using namespace std;


PartidaIndividual::PartidaIndividual(bool nueva, int id, EEstado estado, DtFechaHora * fecha):Partida(id,estado, fecha) {
  this->nueva = nueva;
};


void PartidaIndividual::finalizarPartida() {
    cout << "Finalizar Partida";
}

void PartidaIndividual::continuarPartida(){
  cout << "continuarPartida";
};

DtPartida * PartidaIndividual::getDtPartida(){
  DtPartida * dtpart = new DtPartida(this->getId(),this->getFecha(),0);
  return dtpart;
};

void PartidaIndividual::setNueva(bool nueva){
  this->nueva=nueva;
};

bool PartidaIndividual::getNueva(){
  return this->nueva;
};

void PartidaIndividual::finalizarPartida(EEstado estado) { //Debe recibir parametro para modificar el estado
  this->setEstado(estado);
}