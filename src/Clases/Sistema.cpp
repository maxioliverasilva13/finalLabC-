#include "Sistema.h"
#include "../ICollection/interfaces/IDictionary.cpp"
#include "../ICollection/collections/OrderedDictionary.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema(){
  this->categorias = new OrderedDictionary();
  this->videojuegos = new OrderedDictionary();
  this->usuarios = new OrderedDictionary();
}

Sistema * Sistema::getInstance(){
  if (Sistema::instance == NULL){
    Sistema::instance = new Sistema();
  }
  return Sistema::instance;
}
