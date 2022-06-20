#ifndef JUGADOR_CPP
#define JUGADOR_CPP
#include "./Jugador.h"

using namespace std;

DtFechaHora * getFechaVencimientoByPeriodo(DtFechaHora * date, EPeriodo periodo){
    DtFechaHora * fechaVenc;
    if(periodo == VITALICIA){
        fechaVenc = NULL;
     }else if(periodo == MENSUAL){
        if(date->getMonth() + 1 > 12){
            fechaVenc = new DtFechaHora(date->getDay(),1,date->getYear() + 1, date->getHour(),date->getMinute());
        }else{
           fechaVenc = new DtFechaHora(date->getDay(),date->getMonth()+ 1,date->getYear() , date->getHour(),date->getMinute()); 
        }
     }else if(periodo == TRIMESTRAL){
        
        if((date->getMonth() + 3) > 12){
            int difMes = (date->getMonth() + 3) - 12;
            fechaVenc = new DtFechaHora(date->getDay(),difMes,date->getYear() + 1, date->getHour(),date->getMinute());
        }else{
           fechaVenc = new DtFechaHora(date->getDay(),date->getMonth()+ 1,date->getYear() , date->getHour(),date->getMinute()); 
        }
     }else if(periodo == ANUAL){
        fechaVenc = new DtFechaHora(date->getDay(),date->getMonth(),date->getYear() + 1 , date->getHour(),date->getMinute()); 
     }
     return fechaVenc;
}

Jugador::Jugador(string nick, string desc, string email, string pass) : Usuario(email, pass)
{
    this->nickname = nick;
    this->descripcion = desc;
    this->partidas = new OrderedDictionary();
    this->contrataciones = new OrderedDictionary();
    this->estadosJugador = new List();
}

void Jugador::iniciarPartidaMultijugador(ICollection * jugadores, bool enVIvo, Videojuego * juego, DtFechaHora * fecha){
    PartidaMultijugador * partida = new PartidaMultijugador(enVIvo, 0, ENCURSO, fecha, juego, this);
    
    IIterator * it = jugadores->getIterator();
    while (it->hasCurrent())
    {
       Jugador * jugador = (Jugador *)it->getCurrent();
       EstadoJugador * est = new EstadoJugador(fecha, NULL, partida, jugador);
       partida->agregarEstadoJugador(est);
       it->next();
    }
}

ICollection *Jugador::listarVideoJuegosActivos(DtFechaHora * ahora)
{
    ICollection *nameJuegos = new List();
    IIterator *it = this->contrataciones->getIterator();
    while (it->hasCurrent())
    {
        Contratacion *c = (Contratacion *)it->getCurrent();

        if (c->getActiva(NULL) == true)
        {
            string nameGame = c->getNombreVideojuego();
            char *charNameVj = const_cast<char *>(nameGame.c_str()); // paso de string a char (para poder implementar la key)
            String *nombre = new String(charNameVj);
            nameJuegos->add(nombre);
        }
        it->next();
    }
    return nameJuegos;
}

void Jugador::iniciarPartidaIndividual(bool esNueva, Videojuego * vj) {
    DtFechaHora * ahora;
    PartidaIndividual * p = new PartidaIndividual(esNueva, ENCURSO, ahora->getAhora(), vj, this);
    Integer * partidaKey = new Integer(p->getId());
    this->partidas->add(partidaKey, p);
    delete ahora;
}

ICollection *Jugador::listarHistorialPartidasFinalizadas(string nombrevj)
{
    ICollection *partidasFinalizadas = new List();
    IIterator *it = this->partidas->getIterator();

    while (it->hasCurrent())
    {
        Partida *c = (Partida *)it->getCurrent();
        if (c->darTipo() == "PartidaIndividual")
        {
            PartidaIndividual *part = (PartidaIndividual *)it->getCurrent();
            if (part->esFinalizada() && part->darNombreJuego() == nombrevj)
            {
                DtPartidaIndividual *part = new DtPartidaIndividual(part->getId(), part->getContinuar(), part->getEstado(), part->getDuracion(), part->getFecha(), part->getNombreV(), part->getNombreJ());
                partidasFinalizadas->add(part);
            }
        }
        it->next();
    }
    delete it;
}

void Jugador::continuarPartida(int idPart)
{
    Integer *partKey = new Integer(idPart);
    PartidaIndividual *part = (PartidaIndividual *)this->partidas->find(partKey);
    if (part)
    {
        part->continuarPartida();
    }
} 

Jugador::~Jugador()
{
    cout << "Me borro";
}

void Jugador::eliminarSuscripcion(ICollectible *contratacion)
{
    Contratacion *contr = (Contratacion *)contratacion;
    Integer *contrKey = new Integer(contr->getId());
    this->contrataciones->remove(contrKey);
    delete contrKey;
}

void Jugador::setNickname(string nick)
{
    this->nickname = nick;
}

void Jugador::setDescripcion(string des)
{
    this->descripcion = des;
}

string Jugador::getNickname()
{
    return this->nickname;
}

string Jugador::getDescripcion()
{
    return this->descripcion;
}

DtContratacion *Jugador::getContratacionByUser(string nomV, DtFechaHora * fecha_sistema)
{
    IIterator * it = this->contrataciones->getIterator();
    Contratacion * current;

    DtContratacion * res = NULL;
    while (it->hasCurrent())
    {
        current = (Contratacion*)it->getCurrent();
        if(current->getActiva(fecha_sistema)){
            if(nomV == current->getNombreVideojuego()){
                res = new DtContratacion(
                    current->getId(),
                    current->getMonto(), 
                    current->getTipoPago(), 
                    current->getFechaHora(),
                    current->getFechaVencimiento(), 
                    current->getCancelada()
                );
                break;
            }
        }
    }
    delete it;
    return res;
}

int Jugador::getSizeContrataciones() {
    return this->contrataciones->getSize();
}

void Jugador::agregarPartida(Partida *part)
{
    Integer *idKey = new Integer(part->getId());
    this->partidas->add(idKey, part);
};
//int id, ETipoPago tipoPago, float monto, DtFechaHora *FechaHora,
  //         DtFechaHora *FechaVencimiento, bool cancelada, Suscripcion *suscripcion, Jugador *duenio)
void Jugador::suscribirseAVideojuego( Suscripcion * sus, ETipoPago tipoPago,DtFechaHora * fecha_sistema){
     float monto = sus->getPrecio();
     EPeriodo periodo = sus->getPeriodo();

     DtFechaHora *fechaVenc = getFechaVencimientoByPeriodo(fecha_sistema,periodo);

     Contratacion * newContratacion = new Contratacion(tipoPago,monto,fecha_sistema,fechaVenc,false,sus,this);
     
     IKey * keyId = new Integer(newContratacion->getId());
     ICollectible * newItem = (ICollectible*)newContratacion;

     this->contrataciones->add(keyId,newItem);
}

void Jugador::cancelarContratacion(int idContratacion){
       IKey * key = new Integer(idContratacion);
       ICollectible * item = this->contrataciones->find(key);
       if(item == NULL){
         throw invalid_argument("La contratacion no esta asociada a este usuario");
       }
       Contratacion * con = (Contratacion*)item; 
       con->setCancelada(true); 
}

string Jugador::getTipo()
{
    return "Jugador";
}

void Jugador::finalizarPartida(int idPartida, DtFechaHora * fechaSistema) {
    IIterator * it = this->partidas->getIterator();
    while (it->hasCurrent())
    {
        Partida * p = (Partida *)it->getCurrent();
        if (p->getId() == idPartida) {
            p->finalizarPartida(fechaSistema);
            break;
        }
        it->next();
    }
    delete it;
    
}

void Jugador::eliminarPartida(ICollectible *partida)
{
    Partida *p = (Partida *)partida;
    Integer *pKey = new Integer(p->getId());
    this->partidas->remove(pKey);
    delete pKey;
}

void Jugador::eliminarEstadosJugador(ICollectible *estadojugador)
{
    this->estadosJugador->remove(estadojugador);
}

ICollection * Jugador::listarPartidasUnido(){
     
     
     IIterator * it = this->estadosJugador->getIterator();
    
    ICollection * res = new List();   //DtPartidaMultijador;
 
    EstadoJugador * current;
    PartidaMultijugador * current_partida;
    while (it->hasCurrent()){
        current = (EstadoJugador*)it->getCurrent();
        current_partida = (PartidaMultijugador*)current->getPartida();
        bool isOwner = false;
        if(current_partida->getEstado() == ENCURSO){
            if(current_partida->getCreador()->getNickname() == this->nickname){
                isOwner = true;
            }
            //int id, DtFechaHora * fecha, string nombreVideojuego, bool transmitidaEnVivo, ICollection * jugadores_unidos,bool isOwner
            ICollectible * newItem = new DtPartidaMultijugador(current_partida->getId(),current_partida->getFecha(), current_partida->darNombreJuego(),current_partida->getEnVivo(),current_partida->getJugadoresUnidos(),isOwner,current_partida->getCreador()->getNickname());
            res->add(newItem);
        }
        it->next();
    }
    delete it;
    return res;
    
}


void Jugador::abandonarPartida(int idPartida,DtFechaHora * fechaSistema){
   IIterator * it = this->estadosJugador->getIterator();
   EstadoJugador * current ;
   Partida * current_partida;
   
   int current_id_partida = 0;
   while (it->hasCurrent())
   {
    current = (EstadoJugador*)it;
    current_partida = current->getPartida();
    current_id_partida = current_partida->getId();

    if(current_partida->getCreador()->getNickname() == this->nickname && 
    current_id_partida == idPartida){
        throw invalid_argument("No puedes abandonar una partida donde eres el duenio,en todo caso debes finalizarla");
    }
  
    if(current->getFechaHoraSalida() == NULL && current_id_partida == idPartida){
        current->setFechaHoraSalida(fechaSistema);
        break;
    }
    it->next();
   }
   delete it;
}



PartidaMultijugador * Jugador::partidaMasLarga() {
    IIterator * itPartidas = this->partidas->getIterator();
    PartidaMultijugador * partidaMasLarga = NULL;
    
    while (itPartidas->hasCurrent())
    {
      Partida * part = (Partida *)itPartidas->getCurrent();
      if (part->darTipo() == "PartidaMultijugador"){
        PartidaMultijugador * partM = (PartidaMultijugador *)part;
        if (partidaMasLarga == NULL) {
            partidaMasLarga = partM;
        }
        if (partM->getDuracion() > partidaMasLarga->getDuracion()){
            partidaMasLarga = partM;
        }
      }
      itPartidas->next();
    }

    return partidaMasLarga;
  }

  DtJugador * Jugador::getDtJugador() {
    DtJugador * dt = new DtJugador(this->getEmail(), this->getPassword(),this->getNickname(), this->getDescripcion(), this->getSizeContrataciones());
    return dt;
  }

#endif
