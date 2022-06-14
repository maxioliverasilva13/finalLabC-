

#include "Suscripcion.h"
#include <iostream>


using namespace std;

Suscripcion::Suscripcion(int id,float precio,EPeriodo periodo,Videojuego * juego){
    this->id = id;
    this->precio = precio;
    this->periodo = periodo;
    this->videojuego = juego;
}


int Suscripcion::getId(){
    return this->id;
}
float Suscripcion::getPrecio(){
    return this->precio;
}
EPeriodo Suscripcion::getPeriodo(){
    return this->periodo;
}

void Suscripcion::setId(int newId){
    this->id = newId;
}
void Suscripcion::setPeriodo(EPeriodo newPeriodo){
    this->periodo = newPeriodo;
}

void Suscripcion::setPrecio(float precio){
    this->precio = precio;
}


string Suscripcion::darNombreJuego(){
  /*POR IMPLEMENTAR*/
}


bool Suscripcion::jugadorTieneContratacion(string nickname){
    IIterator * it = this->contrataciones->getIterator();
    Contratacion * current;

    bool es_duenio = false;
    while (it->hasCurrent()){
        current = (Contratacion*)it->getCurrent();
        if(nickname == current->getNickNameDuenio()){
            es_duenio = true;
            break;
        }
        it->next();
    }
    return es_duenio;
};


