#ifndef VIDEOJUEGO_HEADER
#define VIDEOJUEGO_HEADER

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
    IDictionary *partidas;

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
    bool hasSuscripcion(EPeriodo);
    void agregarCategoria(ICollectible *);
    void agregarPuntuacion(ICollectible *puntuacion);
    ICollection * getJugadoresActivos();
};
#endif