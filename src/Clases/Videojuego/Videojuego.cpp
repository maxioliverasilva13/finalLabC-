
#ifndef VIDEOJUEGO_CPP
#define VIDEOJUEGO_CPP


#include <iostream>
#include "Videojuego.h"
using namespace std;


Videojuego::Videojuego(string nombre, string descripcion, int prom_punt){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
    this->puntuaciones = new List();
    this->suscripciones = new List();
}

string Videojuego::getNombre(){
    return this->nombre;
}

void Videojuego::setNombre(string nombre){
    this->nombre = nombre;
}

string Videojuego::getDescripcion(){
    return this->descripcion;
}

void Videojuego::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

int Videojuego::getPromedio_puntuacion(){
    return this->promedio_puntuacion;
}

void Videojuego::setPromedio_puntuacion(int promedio_puntuacion){
    this->promedio_puntuacion = promedio_puntuacion;
}

ICollection * Videojuego::getInfoSuscripciones(string nickname){
    IIterator * it = this->suscripciones->getIterator();
    Suscripcion * current;

    ICollection * res = new List();  //DtInfoSuscripcion collection

    bool jugador_tiene_contratacion;
    while (it->hasCurrent()){
        current = (Suscripcion*)it->getCurrent();

        jugador_tiene_contratacion = current->jugadorTieneContratacion(nickname);
        ICollectible * item = new DtInfoSuscripcion(current->getId(), current->getPeriodo(),current->getPrecio(), jugador_tiene_contratacion);
        res->add(item);
    }

    return res;
}


#endif