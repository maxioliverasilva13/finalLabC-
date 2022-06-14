#include <iostream>
#include "Suscripcion.h"

using namespace std;

Suscripcion::Suscripcion(int id, float precio, EPeriodo periodo, Videojuego *videojuego)
{
    this->id = id;
    this->precio = precio;
    this->periodo = periodo;
    this->videojuego = videojuego;

    this->contrataciones = new OrderedDictionary();
};

Suscripcion::~Suscripcion()
{
    this->videojuego = NULL;
    IIterator *it = this->contrataciones->getIterator();
    while (it->hasCurrent())
    {
        /* code */
    }
}

int Suscripcion::getId()
{
    return this->id;
}
float Suscripcion::getPrecio()
{
    return this->precio;
}
EPeriodo Suscripcion::getPeriodo()
{
    return this->periodo;
}

void Suscripcion::setId(int newId)
{
    this->id = newId;
}
void Suscripcion::setPeriodo(EPeriodo newPeriodo)
{
    this->periodo = newPeriodo;
}

void Suscripcion::setPrecio(float precio)
{
    this->precio = precio;
}

string Suscripcion::darNombreJuego()
{
    /*POR IMPLEMENTAR*/
}

bool jugadorTieneContratacion(string nickname){
    /*POR IMPLEMENTAR*/
};

DtInfoSuscripcion *getDatosSuscripcion(){
    /*POR IMPLEMENTAR*/
};
