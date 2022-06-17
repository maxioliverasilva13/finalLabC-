#ifndef VIDEOJUEGO_FUNC
#define VIDEOJUEGO_FUNC

#include <iostream>
#include "Videojuego.h"

using namespace std;

Videojuego::Videojuego(string nombre, string descripcion, int prom_punt)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
    this->puntuaciones = new List();
    this->categorias = new OrderedDictionary();
    this->suscripciones = new OrderedDictionary();
    this->partidas = new OrderedDictionary();
}

Videojuego::~Videojuego()
{
    IIterator *iteratorPartidas = this->partidas->getIterator();
    while (iteratorPartidas->hasCurrent())
    {
        Partida *part = (Partida *)iteratorPartidas->getCurrent();
        Integer *partKey = new Integer(part->getId());
        this->puntuaciones->remove(partKey);
        delete part;
        delete partKey;
        iteratorPartidas->next();
    }

    IIterator *iteratorPuntuaciones = this->puntuaciones->getIterator();
    while (iteratorPuntuaciones->hasCurrent())
    {
        Puntuacion *pun = (Puntuacion *)iteratorPuntuaciones->getCurrent();
        this->puntuaciones->remove(pun);
        delete pun;
        iteratorPuntuaciones->next();
    }

    IIterator *iteratorCategorias = this->categorias->getIterator();
    while (iteratorCategorias->hasCurrent())
    {
        Categoria *categoria = (Categoria *)iteratorCategorias->getCurrent();
        Integer *categoriaKey = new Integer(categoria->getId());
        this->categorias->remove(categoriaKey);
        delete categoria;
        delete categoriaKey;
        iteratorCategorias->next();
    }

    IIterator *iteratorSuscripciones = this->suscripciones->getIterator();
    while (iteratorSuscripciones->hasCurrent())
    {
        Suscripcion *sucr = (Suscripcion *)iteratorSuscripciones->getCurrent();
        Integer *suscrId = new Integer(sucr->getId());
        this->suscripciones->remove(suscrId);
        delete sucr;
        delete suscrId;
        iteratorSuscripciones->next();
    }

    delete iteratorCategorias;
    delete iteratorSuscripciones;
    delete iteratorPuntuaciones;
    this->suscripciones = NULL;
    this->puntuaciones = NULL;
    this->categorias = NULL;
}

string Videojuego::getNombre()
{
    return this->nombre;
}

void Videojuego::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Videojuego::getDescripcion()
{
    return this->descripcion;
}

void Videojuego::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

int Videojuego::getPromedio_puntuacion()
{
    return this->promedio_puntuacion;
}

void Videojuego::setPromedio_puntuacion(int promedio_puntuacion)
{
    this->promedio_puntuacion = promedio_puntuacion;
}

bool Videojuego::hasSuscripcion(EPeriodo periodo)
{
    IIterator *it = suscripciones->getIterator();
    bool hasMatch = false;
    while (it->hasCurrent())
    {
        Suscripcion *suscripcion = (Suscripcion *)it->getCurrent();
        if (suscripcion->getPeriodo() == periodo)
        {
            hasMatch = true;
            break;
        };
        it->next();
    }

    return hasMatch;
}

void Videojuego::agregarSuscripcion(ICollectible *suscripcion)
{
    if (this->suscripciones->getSize() >= 4)
    {
        throw invalid_argument("Este videojuego ya tiene sus 4 suscripciones");
    }
    else
    {
        Suscripcion *suscr = (Suscripcion *)suscripcion;
        if (this->hasSuscripcion(suscr->getPeriodo()))
        {
            throw invalid_argument("Este videojuego ya tiene la suscripcion que intentas agregar");
        }
        else
        {
            Integer *iKey = new Integer(suscr->getId());
            this->suscripciones->add(iKey, suscr);
        };
    };
}

void Videojuego::agregarCategoria(ICollectible *categoria)
{
    Categoria *cat = (Categoria *)categoria;
    Integer *iKey = new Integer(cat->getId());
    this->categorias->add(iKey, categoria);
}

void Videojuego::agregarPuntuacion(ICollectible *puntuacion)
{
    Puntuacion *punt = (Puntuacion *)puntuacion;
    this->puntuaciones->add(punt);
}

ICollection * Videojuego::getJugadoresActivos() {
    ICollection * nombreJugadores = new List(); 
    IIterator * it = this->suscripciones->getIterator();
    while (it->hasCurrent())
    {
        Suscripcion * suscr = (Suscripcion *)it->getCurrent();
        ICollection * nombresJugadoresEnEstaSuscr = suscr->getJugadoresActivos();
        IIterator * iterNombres = nombresJugadoresEnEstaSuscr->getIterator();
        while (iterNombres->hasCurrent())
        {   
            String * nameDuenio = (String *)iterNombres->getCurrent();
            nombreJugadores->add(nameDuenio);
            iterNombres->next();
        }
        delete nombresJugadoresEnEstaSuscr;
        delete iterNombres;
        it->next();
    }
    delete it;
    return nombreJugadores;
}

#endif