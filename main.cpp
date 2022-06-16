#include <iostream>

#include "src/Clases/Sistema.cpp"

#include <typeinfo>

using namespace std;

int main()
{
    Sistema *s = s->getInstance();

    try
    {
        DtCostoSuscripcion *costo1 = new DtCostoSuscripcion(ANUAL, 12.5);
        DtCostoSuscripcion *costo2 = new DtCostoSuscripcion(TRIMESTRAL, 112.5);

        ICollection *costos_suscripcion = new List();

        costos_suscripcion->add(costo1);
        costos_suscripcion->add(costo2);

        DtCategoria *cat1 = new DtCategoria("PS5", "UNA CATEGORIA", "PS5");
        DtCategoria *cat2 = new DtCategoria("DEPORTE", "OTRA CATEGORIA", "DEPORTE");
        DtCategoria *cat3 = new DtCategoria("OTRO", "OTRA CATEGORIA", "OTRO");

        s->agregarCategoria(cat1);

        ICollection *categorias = new List();

        categorias->add(cat1);
        categorias->add(cat2);
        categorias->add(cat3);

        s->agregarVideojuego("God Of War", "Es un buen juego", costos_suscripcion, categorias);

        s->agregarVideojuego("God Of War 3", "Es un buen juego2", costos_suscripcion, categorias);
        s->eliminarVideoJuego("God Of War");

        // Jugador *j = new Jugador("maxi", "asd", "asd@asd.com", "pass123");
        // PartidaIndividual *p = new PartidaIndividual(true, 1, FINALIZADA, NULL, NULL, NULL);
        // ICollection *partidas = new List();
        // partidas->add(p);

        // IIterator *it = partidas->getIterator();
        // while (it->hasCurrent())
        // {
        //     Partida *c = (Partida *)it->getCurrent();
        //     cout << "Es igual: " << c->darTipo();
        //     cout << "jeje" << endl;
        //     it->next();
        // }

        // cout << "si " << endl;
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}