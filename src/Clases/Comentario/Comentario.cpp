



#ifndef COMENTARIO_HEADER
#define COMENTARIO_HEADER


#include<iostream>

using namespace std;

class Comentario : public ICollectible{
    private:
        string texto;
        DtFechaHora* fechaHoraEnvio;
        Jugador* creador;
        PartidaMultijugador* partida;
        IDictionary* comentarios;
        //tambien puede tener una coleccion de comentarios (respuestas)
    public:
        Comentario(string, DtFechaHora*, Jugador*, PartidaMultijugador*);
        void setTexto(string);
        void setFechaHoraEnvio(DtFechaHora*);
        void setCreador(Jugador*);
        string getTexto();
        DtFechaHora* getFechaHoraEnvio();
        Jugador* getJugador();
};


Comentario::Comentario(string texto, DtFechaHora* FechaHoraEnvio, Jugador* creador, PartidaMultijugador* partida) {
        this->texto = texto;
        this->fechaHoraEnvio = FechaHoraEnvio;
        this->partida = partida;
        this->creador = creador;
        this->comentarios = new OrderedDictionary();
}

void Comentario::setTexto(string texto) {
        this->texto = texto;
}

void Comentario::setFechaHoraEnvio(DtFechaHora* fechaHoraEnvio) {
        this->fechaHoraEnvio = fechaHoraEnvio;
}

void Comentario::setCreador(Jugador * creador) {
        this->creador = creador ;
}

string Comentario::getTexto(){
    return this->getTexto();
}

DtFechaHora* Comentario::getFechaHoraEnvio(){
    return this->fechaHoraEnvio;
}

Jugador* Comentario::getJugador(){
    return this->creador;
}

#endif