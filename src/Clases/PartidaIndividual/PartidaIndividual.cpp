#include "PartidaIndividual.h"

using namespace std;


PartidaIndividual::PartidaIndividual(bool nueva, int id, int estado):Partida(id,estado) {
    this->nueva = nueva;
};


void PartidaIndividual::finalizarPartida() {
  cout << "Finalizar Partida";
}

void PartidaIndividual::continuarPartida(){
  cout << "continuarPartida";
};

string PartidaIndividual::getDtPartida(){
  return "DtPartidaIndividual";
};

void PartidaIndividual::setNueva(bool nueva){
  this->nueva=nueva;
};

bool PartidaIndividual::getNueva(){
  return this->nueva;
};