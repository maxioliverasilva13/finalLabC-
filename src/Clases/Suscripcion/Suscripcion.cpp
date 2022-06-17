#ifndef SUSCRIPCION_FUNC
#define SUSCRIPCION_FUNC

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
    IIterator *it = this->contrataciones->getIterator();
    while (it->hasCurrent())
    {
        Contratacion *contr = (Contratacion *)it->getCurrent();
        Integer *contrKey = new Integer(contr->getId());
        this->contrataciones->remove(contrKey);
        delete contr;
        delete contrKey;
        it->next();
    }
    delete it;
    this->videojuego = NULL;
    this->contrataciones = NULL;
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
    return this->videojuego->getNombre();
}

bool jugadorTieneContratacion(string nickname){
    /*POR IMPLEMENTAR*/
};

DtInfoSuscripcion *getDatosSuscripcion(){
    /*POR IMPLEMENTAR*/
};

void Suscripcion::agregarContratacion(ICollectible *contratacion)
{
    Contratacion *contr = (Contratacion *)contratacion;
    Integer *contrKey = new Integer(contr->getId());
    this->contrataciones->add(contrKey, contr);
}

ICollection * Suscripcion::getJugadoresActivos() {
    ICollection * nombreJugadoresConSuscrAEsteJuego = new List();
    IIterator * it = this->contrataciones->getIterator();
    while (it->hasCurrent())
    {
        Contratacion * contr = (Contratacion *)it->getCurrent();
        if (contr->getActiva()) {
            string nameDuenio = contr->getNickNameDuenio();
            char *charName = const_cast<char *>(nameDuenio.c_str()); // paso de string a char (para poder implementar la key)
            String *nameKey = new String(charName);
            nombreJugadoresConSuscrAEsteJuego->add(nameKey);
        }
        it->next();
    }
    return nombreJugadoresConSuscrAEsteJuego;
}

#endif