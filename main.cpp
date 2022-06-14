#include <iostream>

#include "src/Clases/Sistema.cpp"

using namespace std;

int main()
{
    Sistema *s = s->getInstance();
    Jugador* j = new Jugador("Leo", "lalala", "lalal2", "123");
    DtFechaHora* f = new DtFechaHora(22, 2, 2022, 3, 12);
    Videojuego* v = new Videojuego("COD", "lae", 0);
    PartidaMultijugador* P = new PartidaMultijugador(true, 1, 2, ENCURSO, f, v);
    EstadoJugador* e = new EstadoJugador(f, NULL, P, j);
    P->agregarEstadoJugador(e);
    cout << e->getFechaHoraSalida() <<endl;
    P->finalizarPartida();
    cout << endl << P->getEstado();
    cout << e->getFechaHoraSalida()->getMinute() <<endl;

    return 0;
}