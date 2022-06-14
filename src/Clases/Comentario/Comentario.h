//#ifndef COMENTARIO_HEADER
//#define COMENTARIO_HEADER
#include "../../DataType/DtFechaHora/DtFechaHora.cpp"
#include "../Jugador/Jugador.cpp"
#include "../PartidaMultijugador/PartidaMultijugador.cpp"
#include "../../ICollection/interfaces/ICollectible.cpp"
#include "../../ICollection/interfaces/IDictionary.cpp"
#include "../../ICollection/collections/OrderedDictionary.cpp"

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

//#endif