#include<iostream>

#include "src/DataType/DtPartida/DtPartida.h"
#include "src/Enum/index.cpp"
#include "src/ICollection/interfaces/ICollectible.h"
#include "src/ICollection/interfaces/ICollectible.cpp"
#include "src/ICollection/interfaces/ICollection.h"
#include "src/ICollection/interfaces/ICollection.cpp"
#include "src/ICollection/interfaces/IDictionary.h"
#include "src/ICollection/interfaces/IIterator.h"
#include "src/ICollection/collections/OrderedDictionary.h"
#include "src/ICollection/collections/OrderedDictionaryEntry.h"
#include "src/ICollection/collections/ListIterator.h"
#include "src/ICollection/collections/ListNode.h"
#include "src/ICollection/collections/List.h"
#include "src/ICollection/collections/List.cpp"
#include "src/ICollection/collections/OrderedDictionary.cpp"
#include "src/ICollection/collections/OrderedDictionaryEntry.cpp"
#include "src/ICollection/collections/ListIterator.cpp"
#include "src/ICollection/collections/ListNode.cpp"
#include "src/ICollection/interfaces/IDictionary.cpp"
#include "src/ICollection/interfaces/IIterator.cpp"
#include "src/ICollection/Integer.cpp"
#include "src/ICollection/interfaces/IKey.cpp"
#include "src/ICollection/interfaces/OrderedKey.cpp"
#include "src/Clases/Partida/Partida.cpp"
#include "src/Clases/PartidaMultijugador/PartidaMultijugador.cpp"
#include "src/Clases/Jugador/Jugador.cpp"
#include "src/Clases/EstadoJugador/EstadoJugador.cpp"
#include "src/DataType/DtPartida/DtPartida.cpp"


using namespace std;


int main() {

    Jugador * player = new Jugador("maxi123", "soy un player", "maxi@maxi.com", "oliverman12");
    Jugador * player2 = new Jugador("ro", "other", "other@other.com", "oliverman12");


    DtFechaHora * fecha = new DtFechaHora(11,12,2020,13,41);
    DtFechaHora * horaEntrada = new DtFechaHora(10,11,2021,13,22);

    PartidaMultijugador * partida = new PartidaMultijugador(true, 12.5 ,123, FINALIZADA, fecha);

    EstadoJugador * e = new EstadoJugador(horaEntrada, partida, player);
    EstadoJugador * e2 = new EstadoJugador(horaEntrada, partida, player2);

    partida->agregarEstadoJugador(e);
    partida->agregarEstadoJugador(e2);

    cout << partida->estadosJugador->getSize();

    player->agregarPartida(partida);

    return 0;
}