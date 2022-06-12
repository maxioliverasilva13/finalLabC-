#include "Sistema.h"
#include "../ICollection/interfaces/IDictionary.cpp"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/IIterator.h"

#include "./Jugador/Jugador.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema(){
  this->categorias = new OrderedDictionary();
  this->videojuegos = new OrderedDictionary();
  this->usuarios = new OrderedDictionary();
  this->loggUser = new Jugador("maxi123", "soy un player", "maxi@maxi.com", "oliverman12");
}

Sistema * Sistema::getInstance(){
  if (Sistema::instance == NULL){
    Sistema::instance = new Sistema();
  }
  return Sistema::instance;
}


ICollection * Sistema::listarSuscripcionesPorVideojuego(){
    if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
    }
    Jugador * jugador = (Jugador*)this->loggUser;
    cout << jugador->getNickname();

    IIterator * it = this->videojuegos->getIterator();
    Videojuego * current;
    while (it->hasCurrent()){
        current = (Videojuego*)it->getCurrent();
        //Necesito la funcion de videojuego
    }
}