#include <iostream>
#include "Videojuego.h"

using namespace std;

videojuego::videojuego(string nombre, string descripcion, int prom_punt){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
}


string videojuego::getNombre(){
    return this->nombre;
}

void videojuego::setNombre(string nombre){
    this->nombre = nombre;
}

string videojuego::getDescripcion(){
    return this->descripcion;
}

void videojuego::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

int videojuego::getPromedio_puntuacion(){
    return this->promedio_puntuacion;
}

void videojuego::setPromedio_puntuacion(int promedio_puntuacion){
    this->promedio_puntuacion = promedio_puntuacion;
}