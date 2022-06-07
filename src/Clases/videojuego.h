#ifndef VIDEOJUEGO_HEADER
#define VIDEOJUEGO_HEADER

#include<iostream>

using namespace std;

class videojuego {
    private:
        string nombre;
        string descripcion;
        int promedio_puntuacion;
    public:
        videojuego(string, string, int);
        string getNombre();
        string getDescripcion();
        int getPromedio_puntuacion();
        void setNombre(string);
        void setDescripcion(string);
        void setPromedio_puntuacion(int);
};

#endif