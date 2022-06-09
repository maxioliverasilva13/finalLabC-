#ifndef COMENTARIO_HEADER
#define COMENTARIO_HEADER
#include "../../DataType/DtFechaHora/DtFechaHora.cpp"
#include "../Jugador/Jugador.cpp"

#include<iostream>

using namespace std;

class Comentario {
    private:
        string texto;
        DtFechaHora fechaHoraEnvio;
        Jugador* creador;
        //tambien puede tener una coleccion de comentarios (respuestas)
    public:
        Comentario(string, DtFechaHora);
        void setTexto(string);
        void setFechaHoraEnvio(DtFechaHora);
        void setCreador(Jugador*);
        string getTexto();
        DtFechaHora getFechaHoraEnvio();
        Jugador* getJugador();
};

#endif