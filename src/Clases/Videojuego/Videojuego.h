#ifndef VIDEOJUEGO_HEADER
#define VIDEOJUEGO_HEADER

#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/List.h"
#include "../../Clases/Partida/Partida.h"

#include <iostream>

using namespace std;

class Videojuego : public ICollectible
{
private:
    string nombre;
    string descripcion;
    int promedio_puntuacion;
    ICollection *puntuaciones;
    IDictionary *categorias;
    IDictionary *suscripciones;

public:
    Videojuego(string, string, int);
    ~Videojuego();
    string getNombre();
    string getDescripcion();
    int getPromedio_puntuacion();
    void setNombre(string);
    void setDescripcion(string);
    void setPromedio_puntuacion(int);
    void agregarSuscripcion(ICollectible *);
    void agergarCategoria(ICollectible *);
    bool hasSuscripcion(EPeriodo);
    void agregarCategoria(ICollectible *);
};

#endif