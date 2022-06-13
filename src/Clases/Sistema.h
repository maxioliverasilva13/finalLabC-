#ifndef SISTEMA
#define SISTEMA

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../DataType/DtContratacion/DtContratacion.h"
#include "../Enum/index.cpp"
#include "../Clases/Usuario/Usuario.h"
#include "../Clases/Videojuego/Videojuego.h"

//Datatypes
#include "../DataType/DtSuscripcion/DtSuscripcion.h"
#include<string>



class Sistema {
    private:
        IDictionary * categorias;
        IDictionary * videojuegos;
        IDictionary * usuarios;
        Usuario * loggUser = NULL;
        static Sistema * instance;      
        Sistema();

    public:
        static Sistema * getInstance();
        void iniciarPartidaMultijugador(ICollection * jugadores , bool enVIvo); //jugadores es set<string>
        ICollection * listarJugadoresConSuscripcionActivaAJuego(string nombreVideojuego); // strings
        void iniciarPartidaIndividual(bool nueva);
        void continuar(int idpartida);
        ICollection * listarHistorialPartidasFinalizadas(string nombreVJ); //DtPartida
        ICollection * listarVideoJuegosActivos(); // a el usuario logueado retorna strings
        ICollection * listarSuscripcionesPorVideojuego(); // DtSuscripcion
        DtContratacion * getContratacion(string nombreVideojuego);
        void cancelarSuscripcion(int idContratacion);
        void confirmarSuscripcion(string nombreVideojuego, int idSuscripcion, ETipoPago metodoPago);
        void altaUsuario(Usuario * user); //TODO : dataType usuario
        void agregarVideojuego(string nombre, string descricpcion, ICollection * costo_suscripcion, ICollection * categorias);
        ICollection * listarCategorias(); //dtCategoria
        void finalizarPartida(int idPartida);
        void eliminarVideoJuego(string nombreVideojuego);
};

#endif