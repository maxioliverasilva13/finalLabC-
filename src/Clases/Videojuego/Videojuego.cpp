<<<<<<< HEAD
#ifndef VIDEOJUEGO_FUNC
#define VIDEOJUEGO_FUNC

#include <iostream>
#include "Videojuego.h"
=======
#ifndef VIDEOJUEGO_CPP
#define VIDEOJUEGO_CPP

#include <iostream>
#include "Videjuego.h"
>>>>>>> 0526c5c6e7fe2fed2054c341c199beb6df9533e7

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

<<<<<<< HEAD
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

=======
ICollection* Videojuego::getPuntuaciones() {
    return this->puntuaciones;
}

IDictionary* Videojuego::getCategorias() {
    return this->categorias;
}

IDictionary* Videojuego::getSuscripciones() {
    return this->suscripciones;
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

Suscripcion * Videojuego::getSuscripcion(int idSuscripcion){
     IKey * keyId = new Integer(idSuscripcion);
     ICollectible * foundElem = this->suscripciones->find(keyId);
     if(foundElem == NULL){
        return NULL;
     }
     Suscripcion * res = (Suscripcion*)foundElem;
     return res;
};


void Videojuego::agregarPuntuacion(int puntuacion,Jugador * jugador){
       IIterator *it  = this->puntuaciones->getIterator();
       Puntuacion * current;

       double sumPunt = 0;
       int cantPunt = 0;
       bool alreadyPunt = false;

       Jugador * current_jugador; 
       while (it->hasCurrent())
       {
         current = (Puntuacion*)it->getCurrent();
         current_jugador = current->getCreador();

         if(jugador->getNickname() == current_jugador->getNickname()){
                alreadyPunt = true;
                current->setPuntuacion(puntuacion);
         }
         sumPunt+= current->getPuntuacion();
         cantPunt++;
       }
       if(!alreadyPunt){
         Puntuacion * newPuntuacion = new Puntuacion(puntuacion,this,jugador);
         this->puntuaciones->add(newPuntuacion);
         sumPunt+= newPuntuacion->getPuntuacion();
         cantPunt++;
       }
       this->promedio_puntuacion = sumPunt/cantPunt;
}
>>>>>>> 0526c5c6e7fe2fed2054c341c199beb6df9533e7
#endif