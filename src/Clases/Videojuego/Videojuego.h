//#ifndef VIDEOJUEGO_HEADER
//#define VIDEOJUEGO_HEADER

 //datatype
 #include "../../DataType/DtInfoSuscripcion/DtInfoSuscripcion.cpp"

 //collections
 #include "../../ICollection/interfaces/ICollection.cpp"
 #include "../../ICollection/collections/List.cpp"


//other classes
#include "../Suscripcion/Suscripcion.cpp"

#include<iostream>

using namespace std;
class Videojuego {
    private:
        string nombre;
        string descripcion;
        int promedio_puntuacion;
        ICollection * puntuaciones;
        ICollection * suscripciones;

    public:
        Videojuego(string, string, int);
        string getNombre();
        string getDescripcion();
        int getPromedio_puntuacion();
        void setNombre(string);
        void setDescripcion(string);
        void setPromedio_puntuacion(int);
        ICollection * getInfoSuscripciones(string nickname);
};

//#endif