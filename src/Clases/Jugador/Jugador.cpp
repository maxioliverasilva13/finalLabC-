#ifndef JUGADOR_CPP
#define JUGADOR_CPP
#include "./Jugador.h"

using namespace std;

<<<<<<< HEAD
class Jugador : public Usuario
{
private:
    string nickname;
    string descripcion;
    IDictionary *partidas;       // JUGADOR VE (tiene) PARTIDAS.
    IDictionary *contrataciones; // JUGADOR VE (tiene) CONTRATACIONES.
    ICollection *estadosJugador; // JUGADOR VE (tiene) CONTRATACIONES.
public:
    Jugador(string, string, string, string);
    ~Jugador();
    void setNickname(string);
    void setDescripcion(string);
    string getNickname();
    string getDescripcion();
    void iniciarPartidaMultijugador(ICollection *, bool);    // recibe coleccion de Jugadores.
    ICollection *listarVideojuegosActivos(string);           // retorna coleccion de Strings (nombres de videojuegos)
    ICollection *listarHistorialPartidasFinalizadas(string); // retorna coleccion de DtPartida (partidas finalizadas)
    void continuarPartida(int);
    void iniciarPartidaIndividual(bool, Videojuego *);
    void suscribirseAVideojuego(int, string, ETipoPago);
    void cancelarContratacion(int);
    void finalizarPartida(int);
    DtContratacion *getContratacionByUser(int);
    void agregarPartida(Partida *);
    void eliminarSuscripcion(ICollectible *);
    void eliminarPartida(ICollectible *);
    void eliminarEstadosJugador(ICollectible *);
    ICollection *listarVideoJuegosActivos();
};
=======
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
>>>>>>> 0526c5c6e7fe2fed2054c341c199beb6df9533e7

Jugador::Jugador(string nick, string desc, string email, string pass) : Usuario(email, pass)
{
    this->nickname = nick;
    this->descripcion = desc;
    this->partidas = new OrderedDictionary();
    this->contrataciones = new OrderedDictionary();
}

ICollection *Jugador::listarVideoJuegosActivos()
{
    ICollection *nameJuegos = new List();
    IIterator *it = this->contrataciones->getIterator();
    while (it->hasCurrent())
    {
        Contratacion *c = (Contratacion *)it->getCurrent();

        if (c->getActiva() == true)
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
    PartidaIndividual * p = new PartidaIndividual(esNueva, 1, ENCURSO, ahora->getAhora(), vj, this);
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
                DtPartida *part = new DtPartida(part->getId(), part->getFecha(), part->getDuracion());
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
            if(nomV == current->getVideojuego()){
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

#endif
