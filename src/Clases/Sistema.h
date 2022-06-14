#ifndef SISTEMA
#define SISTEMA

#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../DataType/DtContratacion/DtContratacion.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/OrderedDictionaryEntry.h"
#include "../Enum/index.cpp"
#include "../Clases/Usuario/Usuario.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"

#include <string>

class Sistema
{
private:
    IDictionary *categorias;
    IDictionary *videojuegos;
    IDictionary *usuarios;
    Usuario *loggUser = NULL;

    static Sistema *instance;

public:
    Sistema();
    static Sistema *getInstance();
    void agregarCategoria(ICollectible *);
    void iniciarPartidaMultijugador(ICollection *jugadores, bool enVIvo);            // jugadores es set<string>
    ICollection *listarJugadoresConSuscripcionActivaAJuego(string nombreVideojuego); // strings
    void iniciarPartidaIndividual(bool nueva);
    void continuar(int idpartida);
    ICollection *listarHistorialPartidasFinalizadas(string nombreVJ); // DtPartida
    ICollection *listarVideoJuegosActivos();         // a el usuario logueado retorna strings
    ICollection *listarSuscripcionesPorVideojuego(); // DtSuscripcion
    DtContratacion *getContratacion(string nombreVideojuego);
    void cancelarSuscripcion(int idContratacion);
    void confirmarSuscripcion(string nombreVideojuego, int idSuscripcion, ETipoPago metodoPago);
    void altaUsuario(Usuario *user); // TODO : dataType usuario
    void agregarVideojuego(string nombre, string descricpcion, ICollection *costo_suscripcion, ICollection *dtsCategorias);
    ICollection *listarCategorias(); // dtCategoria
    void finalizarPartida(int idPartida);
    void eliminarVideoJuego(string nombreVideojuego);
    void listarVJ();
    void altaUsuario(DtUsuario * user);
    bool iniciarSesion(string email, string password);
    void modificarFechaSistema(DtFechaHora * fechahora);
    DtFechaHora * getFechaSistema();
    void recorrerUsuarios();
};

#endif