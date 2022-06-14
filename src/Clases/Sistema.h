#ifndef SISTEMA
#define SISTEMA

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../DataType/DtContratacion/DtContratacion.h"
#include "../DataType/DtUsuario/DtUsuario.cpp"
#include "../DataType/DtJugador/DtJugador.cpp"
#include "../DataType/DtDesarrollador/DtDesarrollador.cpp"
#include "../Enum/index.cpp"
#include "../Clases/Usuario/Usuario.h"
#include<string>


class Sistema {
    private:
        IDictionary * categorias;
        IDictionary * videojuegos;
        IDictionary * usuarios;
        Usuario * loggUser = NULL;
        DtFechaHora * fechaHora = NULL;
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
        void agregarVideojuego(string nombre, string descricpcion, ICollection * costo_suscripcion, ICollection * categorias);
        ICollection * listarCategorias(); //dtCategoria
        void finalizarPartida(int idPartida);
        void eliminarVideoJuego(string nombreVideojuego);
        void altaUsuario(DtUsuario * user);
        bool iniciarSesion(string email, string password);
        void modificarFechaSistema(DtFechaHora * fechahora);
        DtFechaHora * getFechaSistema();
        void recorrerUsuarios();
};

#endif