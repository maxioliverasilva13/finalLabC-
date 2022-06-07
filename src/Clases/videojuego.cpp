#include <iostream>
#include "VideoJuego.h"

using namespace std;

VideoJuego::VideoJuego(string nombre, string descripcion, int prom_punt){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
}


string VideoJuego::getNombre(){
    return this->nombre;
}

void VideoJuego::setNombre(string nombre){
    this->nombre = nombre;
}

string VideoJuego::getDescripcion(){
    return this->descripcion;
}

void VideoJuego::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

int VideoJuego::getPromedio_puntuacion(){
    return this->promedio_puntuacion;
}

void VideoJuego::setPromedio_puntuacion(int promedio_puntuacion){
    this->promedio_puntuacion = promedio_puntuacion;
}