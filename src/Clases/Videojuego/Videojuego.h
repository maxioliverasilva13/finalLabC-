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
    Desarrollador * creador;

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
    ICollection * getJugadoresActivos(DtFechaHora *,string nickameUserLogg);
    ICollection *getPuntuaciones();
    IDictionary *getCategorias();
    IDictionary *getSuscripciones();
    ICollection * getInfoSuscripciones(string,DtFechaHora * );
    Suscripcion * getSuscripcion(int);
    void agregarPuntuacion(int ,Jugador *);
    DtVideojuego * getDtVideojuego();
    void setDesarrollador(Desarrollador *);
    Desarrollador * getDesarrollador();
    float getTotalHorasJugadas(); 
    void agregarPartida(ICollectible *);
};

#endif