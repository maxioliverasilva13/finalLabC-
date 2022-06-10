#include <iostream>
#include "Videojuego.h"
#include "../../ICollection/collections/List.cpp"

using namespace std;

Videojuego::Videojuego(string nombre, string descripcion, int prom_punt){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
    this->puntuaciones = new List();
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