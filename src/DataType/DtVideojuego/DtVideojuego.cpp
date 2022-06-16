#ifndef DTVIDEOJUEGO_HEADER
#define DTVIDEOJUEGO_HEADER

#include <iostream>
using namespace std;

class DtVideojuego {
private:
    string nombre;
    string descripcion;
    int promedio_puntuacion;
public:
    DtVideojuego(string nombre, string descripcion, int prom_puntuacion);
    string getNombreVideojuego();
    string getDescripcionVideojuego();
    int getPromedioPuntuaciones();
};

DtVideojuego::DtVideojuego(string nombre, string password, int prom_puntuacion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_puntuacion;
}

string DtVideojuego::getNombreVideojuego() {
    return this->nombre;
}

string DtVideojuego::getDescripcionVideojuego() {
    return this->descripcion;
}

int DtVideojuego::getPromedioPuntuaciones() {
    return this->promedio_puntuacion;
}

#endif