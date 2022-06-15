#ifndef VIDEOJUEGO_CPP
#define VIDEOJUEGO_CPP

#include <iostream>

#include "Videjuego.h"
using namespace std;


Videojuego::Videojuego(string nombre, string descripcion, int prom_punt)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->promedio_puntuacion = prom_punt;
    this->puntuaciones = new List();
    this->categorias = new OrderedDictionary();
    this->suscripciones = new OrderedDictionary();
}

Videojuego::~Videojuego()
{
    cout << "Me destruyo";
    IIterator *iteratorPuntuaciones = this->puntuaciones->getIterator();
    while (iteratorPuntuaciones->hasCurrent())
    {
        Puntuacion *pun = (Puntuacion *)iteratorPuntuaciones->getCurrent();
        // TODO : ADD DESTRUCTORS TO ALL CLASES OF IMPLEMENT  "REMOVE"
        // this->puntuaciones->remove(pun);
        // delete pun;
        iteratorPuntuaciones->next();
    }

    IIterator *iteratorCategorias = this->categorias->getIterator();
    while (iteratorCategorias->hasCurrent())
    {
        cout << endl
             << "+1 categoria borrada";
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
        cout << endl
             << "+1 suscripcion borrada";
        Suscripcion *sucr = (Suscripcion *)iteratorSuscripciones->getCurrent();
        Integer *suscrId = new Integer(sucr->getId());
        this->categorias->remove(suscrId);
        delete sucr;
        delete suscrId;
        iteratorSuscripciones->next();
    }

    this->suscripciones = NULL;
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
    delete it;
    return res;
}

#endif