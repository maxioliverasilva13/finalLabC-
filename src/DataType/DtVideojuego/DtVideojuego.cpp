#ifndef DTVIDEOJUEGO_HEADER
#define DTVIDEOJUEGO_HEADER

#include <iostream>
using namespace std;

class DtVideojuego : public ICollectible
{
private:
    string nombre;
    string descripcion;
    int promedio_puntuacion;
    ICollection *puntuaciones;
    IDictionary *categorias;
    IDictionary *suscripciones;
    string empresaDesarrollador;
    float totalHorasJugadas;
public:
    DtVideojuego(string nombre, string descripcion, int prom_puntuacion, ICollection*, IDictionary*, IDictionary*, string, float);
    string getNombreVideojuego();
    string getDescripcionVideojuego();
    int getPromedioPuntuaciones();
    ICollection *getPuntuaciones();
    IDictionary *getCategorias();
    IDictionary * getSuscripciones();
    string getEmpresaDesarrollador();
    int getTotalHorasJugadas();
};

DtVideojuego::DtVideojuego(string nombre, string descripcion, int prom_puntuacion, ICollection * puntuaciones, IDictionary *categorias, IDictionary *suscripciones, string empresaDesarrollador, float totalHorasJugadas) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_puntuacion;
    this->puntuaciones = puntuaciones;
    this->categorias = categorias;
    this->suscripciones = suscripciones;
    this->empresaDesarrollador = empresaDesarrollador;
    this->totalHorasJugadas = totalHorasJugadas;
}

string DtVideojuego::getNombreVideojuego() {
    return this->nombre;
}

string DtVideojuego::getEmpresaDesarrollador() {
    return this->empresaDesarrollador;
}

int DtVideojuego::getTotalHorasJugadas(){
    return this->totalHorasJugadas;
}

string DtVideojuego::getDescripcionVideojuego() {
    return this->descripcion;
}

int DtVideojuego::getPromedioPuntuaciones() {
    return this->promedio_puntuacion;
}


ICollection* DtVideojuego::getPuntuaciones() {
    return this->puntuaciones;
}

IDictionary* DtVideojuego::getCategorias() {
    return this->categorias;
}

IDictionary* DtVideojuego::getSuscripciones() {
    return this->suscripciones;
}


#endif