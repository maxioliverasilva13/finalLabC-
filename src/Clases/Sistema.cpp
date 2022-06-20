#ifndef SISTEMA
#define SISTEMA
#include <string>
#include <iostream>
#include <ctime>
#include <typeinfo>

using namespace std;

class ICollectible;
class ICollection;
class IDictionary;
class OrderedKey;
class IKey;
class IIterator;
class List;
class ListIterator;
class ListNode;
class OrderedDictionary;
class OrderedDictionaryEntry;
class Integer;
class String;

class Partida;
class Puntuacion;
class PartidaIndividual;
class PartidaMultijugador;
class Categoria;
class EstadoJugador;
class CategoriaGenero;
class CategoriaOtro;
class CategoriaPlataforma;
class Comentario;
class Desarrollador;
class Contratacion;
class Jugador;
class Suscripcion;
class Usuario;
class Videojuego;
class DtCategoria;
class DtContratacion;
class DtCostoSuscripcion;
class DtDesarrollador;
class DtFechaHora;
class DtInfoSuscripcion;
class DtJugador;
class DtUsuario;
class DtPartida;
class DtSuscripcion;
class DtVideojuego;
class DtPartidaMultijugador;

// ENUM
#include "../Enum/index.cpp"

// COLLECTIONS  ---------------------------------------------
#include "../ICollection/interfaces/ICollectible.cpp"
#include "../ICollection/interfaces/ICollection.cpp"
#include "../ICollection/interfaces/IDictionary.cpp"
#include "../ICollection/interfaces/OrderedKey.cpp"
#include "../ICollection/interfaces/IKey.cpp"
#include "../ICollection/interfaces/IIterator.cpp"
#include "../ICollection/collections/List.cpp"
#include "../ICollection/collections/ListIterator.cpp"
#include "../ICollection/collections/ListNode.cpp"
#include "../ICollection/collections/OrderedDictionary.cpp"
#include "../ICollection/collections/OrderedDictionaryEntry.cpp"
#include "../ICollection/Integer.cpp"
#include "../ICollection/String.cpp"

// DataTypes -----------------------------------------------
#include "../DataType/DtUsuario/DtUsuario.cpp"
#include "../DataType/DtCategoria/DtCategoria.cpp"
#include "../DataType/DtContratacion/DtContratacion.cpp"
#include "../DataType/DtCostoSuscripcion/DtCostoSuscripcion.cpp"
#include "../DataType/DtDesarrollador/DtDesarrollador.cpp"
#include "../DataType/DtFechaHora/DtFechaHora.cpp"
#include "../DataType/DtInfoSuscripcion/DtInfoSuscripcion.cpp"
#include "../DataType/DtJugador/DtJugador.cpp"
#include "../DataType/DtPartida/DtPartida.cpp"
#include "../DataType/DtSuscripcion/DtSuscripcion.cpp"
#include "../DataType/DtVideojuego/DtVideojuego.cpp"
#include "../DataType/DtPartidaMultijugador/DtPartidaMultijugador.cpp"

// CLASES  --------------------------------------------------

// .h
#include "../Clases/Usuario/Usuario.h"
#include "../Clases/Videojuego/Videojuego.h"
#include "../Clases/Partida/Partida.h"
#include "../Clases/Contratacion/Contratacion.h"
#include "../Clases/Suscripcion/Suscripcion.h"
#include "../Clases/Puntuacion/Puntuacion.h"
#include "../Clases/PartidaIndividual/PartidaIndividual.h"
#include "../Clases/PartidaMultijugador/PartidaMultijugador.h"
#include "../Clases/EstadoJugador/EstadoJugador.h"
#include "../Clases/Desarrollador/Desarrollador.h" 


#include "../Clases/Categoria/Categoria.cpp"
#include "../Clases/CategoriaGenero/CategoriaGenero.cpp"
#include "../Clases/CategoriaOtro/CategoriaOtro.cpp"
#include "../Clases/CategoriaPlataforma/CategoriaPlataforma.cpp"
#include "../Clases/Comentario/Comentario.cpp"
#include "../Clases/Desarrollador/Desarrollador.cpp"
#include "../Clases/Suscripcion/Suscripcion.cpp"
#include "../Clases/Jugador/Jugador.cpp"
#include "../Clases/Contratacion/Contratacion.cpp"
#include "../Clases/EstadoJugador/EstadoJugador.cpp"
#include "../Clases/Partida/Partida.cpp"
#include "../Clases/Puntuacion/Puntuacion.cpp"
#include "../Clases/PartidaIndividual/PartidaIndividual.cpp"
#include "../Clases/PartidaMultijugador/PartidaMultijugador.cpp"
#include "../Clases/Usuario/Usuario.cpp"
#include "../Clases/Videojuego/Videojuego.cpp"

class Sistema
{
private:
  IDictionary *categorias;
  IDictionary *videojuegos;
  IDictionary *usuarios;
  Usuario *loggUser;
  DtFechaHora *fechaHora;
  static Sistema *instance;

public:
  Sistema();
  static Sistema *getInstance();
  void agregarCategoria(string nombre, string descripcion, string tipo);
  void iniciarPartidaMultijugador(ICollection *jugadores, bool enVIvo, string);            // jugadores es set<string>
  void iniciarPartidaIndividual(bool nueva, string);
  void continuarPartida(int idpartida);
  ICollection *listarHistorialPartidasFinalizadas(string nombreVJ); // DtPartida
  ICollection *listarVideoJuegosActivos();                          // a el usuario logueado retorna strings
  ICollection *listarSuscripcionesPorVideojuego();     
  ICollection *listarJugadoresConSuscripcionAJuego(string nombrevj);             // DtSuscripcion
  DtContratacion *getContratacion(string nombreVideojuego);
  void cancelarSuscripcion(int idContratacion);
  void confirmarSuscripcion(string nombreVideojuego, int idSuscripcion, ETipoPago metodoPago);
  void agregarVideojuego(string nombre, string descricpcion, ICollection *costo_suscripcion, ICollection *dtsCategorias);
  ICollection *listarCategorias(); // dtCategoria
  void finalizarPartida(int idPartida);
  void eliminarVideoJuego(string nombreVideojuego);
  IDictionary * listarVJ(); // dtVideojuego
  void altaUsuario(DtUsuario *user);
  bool iniciarSesion(string email, string password);
  void modificarFechaSistema(DtFechaHora *fechahora);
  DtFechaHora *getFechaSistema();
  void recorrerUsuarios();
  DtVideojuego *verInfoVideojuego(string);
  string getTipoLoggUser();
  void asignarPuntajeVideojuego(double puntaje,string nombreV);
  ICollection * listarPartidasUnido();  //DtPartidaMultijugador
  void abandonarPartida(int idPartida);
  ICollectible * findUserByNickname(string);
  PartidaMultijugador * partidaMasLarga();
  DtJugador * jugadorConMasContrataciones();
  ICollection * juegosMejoresPuntuados(int); // coleccion de DtVideojuego
};

Sistema *Sistema::instance = NULL;

Sistema::Sistema()
{
  this->categorias = new OrderedDictionary();
  this->videojuegos = new OrderedDictionary();
  this->usuarios = new OrderedDictionary();

  time_t t = time(0);
  tm *now = localtime(&t);
  int dia = now->tm_mday;
  int mes = 1 + now->tm_mon;
  int anio = 1900 + now->tm_year;
  int hora = now->tm_hour;
  int minuto = now->tm_min;
  DtFechaHora *ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
  this->fechaHora = ahora;

  this->loggUser = new Jugador("rodrigo","ddsada","rodrigo@gmail.com","rodrigo123");
}

ICollection *Sistema::listarVideoJuegosActivos()
{
  // Validar si es un jugador
  Jugador *jugadorLogueado = (Jugador *)this->loggUser;
  return jugadorLogueado->listarVideoJuegosActivos(this->fechaHora);
}

ICollection *Sistema::listarHistorialPartidasFinalizadas(string nombrevj)
{
  // Validar si es un jugador
  Jugador *jugadorLogueado = (Jugador *)this->loggUser;
  return jugadorLogueado->listarHistorialPartidasFinalizadas(nombrevj);
}

void Sistema::iniciarPartidaIndividual(bool nueva, string nameJuego) {
  // Validar si es un jugador
  Jugador *jugadorLogueado = (Jugador *)this->loggUser;

  char *charNameVj = const_cast<char *>(nameJuego.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  Videojuego * game = (Videojuego *)this->videojuegos->find(vjKey);
  if (game==NULL) {
    throw invalid_argument("El videojuego el cual intentas iniciar una partida no existe");
  }
  jugadorLogueado->iniciarPartidaIndividual(nueva, game);
}

ICollection * Sistema::listarJugadoresConSuscripcionAJuego(string nombrevj) {
  char *charNameVj = const_cast<char *>(nombrevj.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  Videojuego *juego = (Videojuego *)this->videojuegos->find(vjKey);

  if (juego) {
    return juego->getJugadoresActivos(this->fechaHora);
  } else {
    throw invalid_argument("Este videojuego no existe");
  }
}

Sistema *Sistema::getInstance()
{
  if (Sistema::instance == NULL)
  {
    Sistema::instance = new Sistema();
  }
  return Sistema::instance;
}

//-----------------HELPER FUNCTIONS-----------------------------

bool validateExistsGameName(string nameGame, IDictionary *games)
{
  char *charNameVj = const_cast<char *>(nameGame.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  Videojuego *juego = (Videojuego *)games->find(vjKey);

  if (juego)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Auxiliar para altaUsuario e iniciarSesion
string removerNumeros(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      str.erase(i, 1);
      i--;
    }
  }
  return str;
}

//--------------------------------------------------------------

void Sistema::continuarPartida(int idpartida)
{
  // Validar si es un jugador
  Jugador *jugadorLogueado = (Jugador *)this->loggUser;
  jugadorLogueado->continuarPartida(idpartida);
}


IDictionary * Sistema::listarVJ(){
  IDictionary * listaDTVJ = new OrderedDictionary();
  IIterator * it = this->videojuegos->getIterator();

  while(it->hasCurrent()){
    Videojuego *vjuego = (Videojuego *)it->getCurrent();
    it->next();

    ICollectible * vj = new DtVideojuego(vjuego->getNombre(), vjuego->getDescripcion(), vjuego->getPromedio_puntuacion(), vjuego->getPuntuaciones(), vjuego->getCategorias(), vjuego->getSuscripciones());
    string nombre = vjuego->getNombre();
    
    char *charNombreVJ = const_cast<char *>(nombre.c_str()); // paso de string a char (para poder implementar la key)
    String *vjuegoKey = new String(charNombreVJ);
    listaDTVJ->add(vjuegoKey, vj);
    it->next();
  }
  delete it;
  return listaDTVJ;
}

DtJugador * Sistema::jugadorConMasContrataciones() {
  IIterator * itJugadores = this->usuarios->getIterator();
  Jugador * jugadorConMasContrataciones = NULL;

  while (itJugadores->hasCurrent())
  {
    Usuario * user = (Usuario *)itJugadores->getCurrent();
    if (user->getTipo() == "Jugador") {
      Jugador * player = (Jugador *)user;
      if (jugadorConMasContrataciones  == NULL) {
        jugadorConMasContrataciones = player;
      } else if (player->getSizeContrataciones() > jugadorConMasContrataciones->getSizeContrataciones()) {
          jugadorConMasContrataciones = player;
      }
    }
    itJugadores->next();
  }
  
  if (jugadorConMasContrataciones == NULL) {
    throw invalid_argument("No tenemos datos suficientes para recopilar esta informacion");
  } 
  return jugadorConMasContrataciones->getDtJugador();
}

ICollection * Sistema::juegosMejoresPuntuados(int maxRange) {

  if (this->videojuegos->getSize() == 0) {
    throw invalid_argument("No tenemos suficientes videojuegos para calcular este dato :( !");
  }

  IDictionary * mejoresPuntuadosOrdered = new OrderedDictionary();

  IIterator * itJuegos = this->videojuegos->getIterator();
  while (itJuegos->hasCurrent())
  {
    Videojuego * vj = (Videojuego *)itJuegos->getCurrent();
    Integer * promKey = new Integer(vj->getPromedio_puntuacion());
    mejoresPuntuadosOrdered->add(promKey, vj);
    itJuegos->next();
  }

  ICollection * mejoresPuntuadosSort = new List();

  IIterator * itJuegosOrdered = mejoresPuntuadosOrdered->getIterator();
  while (itJuegosOrdered->hasCurrent())
  {
    Videojuego * vj = (Videojuego *)itJuegosOrdered->getCurrent();
    mejoresPuntuadosSort->add(vj->getDtVideojuego());
    if (mejoresPuntuadosSort->getSize() == maxRange) {
      break;
    }
    itJuegosOrdered->next();
  }

  return mejoresPuntuadosSort;
}

ICollectible * Sistema::findUserByNickname(string nickNameJugador) {
  ICollectible * jugador = NULL;

  IIterator * it = this->usuarios->getIterator();
  while (it->hasCurrent())
  {
    Usuario * user = (Usuario *)it->getCurrent();
    if (user->getTipo() == "Jugador") {
      Jugador * player = (Jugador *)user;
      if (player->getNickname() == nickNameJugador) {
        jugador = player;
        break;
      }
    }
    it->next();
  }
  delete it;
  return jugador;
}

void Sistema::iniciarPartidaMultijugador(ICollection *jugadores, bool enVIvo, string nameJuego) {
  ICollection * jugadoresAPartida = new List();

  char *charNameVj = const_cast<char *>(nameJuego.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  Videojuego * juego = (Videojuego *)this->videojuegos->find(vjKey);

  if (juego == NULL) {
    throw invalid_argument("El videojuego al cual intentas iniciar una partida no existe");
  } 

  IIterator * it = jugadores->getIterator();
  while (it->hasCurrent())
  {
    String * jugadorName = (String *)it->getCurrent();
    Jugador * jugador = (Jugador *)this->findUserByNickname(jugadorName->getValue());
    if (jugador != NULL) {
      bool yaExiste = false;
      IIterator * itPlayers = jugadoresAPartida->getIterator();
      while (itPlayers->hasCurrent())
      {
        Jugador * jug = (Jugador *)itPlayers->getCurrent();
        if (jug->getNickname() == jugadorName->getValue()) {
          yaExiste = true;
          break;
        }
        itPlayers->next();
      }

      if (yaExiste) {
        string namePlayer = jugadorName->getValue();
        throw invalid_argument("El jugador " + namePlayer + " ya es parte de esta partida");
      }
      jugadoresAPartida->add(jugador);
    } else {
      string namePlayer = jugadorName->getValue();
      throw invalid_argument("El jugador que intentas agregar no existe");
      break;
    }
    it->next();
  }
  jugadoresAPartida->add(this->loggUser);
  Jugador * jug = (Jugador *)this->loggUser;
  jug->iniciarPartidaMultijugador(jugadoresAPartida, true, juego, this->fechaHora);

  delete it;
}

void Sistema::eliminarVideoJuego(string nombreVideojuego)
{
  bool existeGame = validateExistsGameName(nombreVideojuego, this->videojuegos);
  if (existeGame)
  {
    char *charNameVj = const_cast<char *>(nombreVideojuego.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    Videojuego *vj = (Videojuego *)this->videojuegos->find(vjKey);
    this->videojuegos->remove(vjKey);
    delete vj;
    delete charNameVj;
    delete vjKey;
  }
  else
  {
    throw invalid_argument("El videojuego que intenta eliminar no existe");
  }
}

void Sistema::agregarCategoria(string nombre, string descripcion, string tipo)
{
  Categoria *categoria;
  if (getEGeneroJuego(getEnumGeneroJuego(tipo)) != "NINGUNO")
  {
    // ES UN GENRO DE TIPO CATEGORIAGENERO
    categoria = new CategoriaGenero(getEnumGeneroJuego(tipo), descripcion);
  }
  else if (getETipoPlataforma(getEnumETipoPlataforma(tipo)) != "NINGUNO")
  {
    // ES UN GENRO DE TIPO CATEGORIAPLATAFORMA
    categoria = new CategoriaPlataforma(getEnumETipoPlataforma(tipo), descripcion);
  }
  else
  {
    categoria = new CategoriaOtro(nombre, descripcion);
  }

  Integer *idKey = new Integer(categoria->getId());
  this->categorias->add(idKey, categoria);
}

void Sistema::agregarVideojuego(string nombre, string descricpcion, ICollection *costos_suscripcion, ICollection *dtsCategorias)
{
  bool existsGame = validateExistsGameName(nombre, this->videojuegos);

  if (existsGame)
  {
    throw invalid_argument("El videojuego " + nombre + " videojuego ya existe");
  }
  Videojuego *vj = new Videojuego(nombre, descricpcion, 0);

  if (costos_suscripcion) {
    IIterator *iterator = costos_suscripcion->getIterator();

    while (iterator->hasCurrent())
    {
      DtCostoSuscripcion *dtcostoS = (DtCostoSuscripcion *)iterator->getCurrent();
      Suscripcion *suscripcion = new Suscripcion(dtcostoS->getCosto(), dtcostoS->getTipo(), vj);
      vj->agregarSuscripcion(suscripcion);
      iterator->next();
    };
  }

  if (dtsCategorias) {
    IIterator *iteratorCategorias = dtsCategorias->getIterator();

    while (iteratorCategorias->hasCurrent())
    {
      DtCategoria *dtcat = (DtCategoria *)iteratorCategorias->getCurrent();

      Integer *catKey = new Integer(dtcat->getId());
      Categoria * categoria = (Categoria *)this->categorias->find(catKey);

      if (categoria) {
        vj->agregarCategoria(categoria);
      }
      iteratorCategorias->next();
    };
  }

  char *charNameVj = const_cast<char *>(nombre.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  this->videojuegos->add(vjKey, vj);
}

void Sistema::modificarFechaSistema(DtFechaHora *fechahora)
{
  this->fechaHora = fechahora;
}

DtFechaHora *Sistema::getFechaSistema()
{
  return this->fechaHora;
}

void Sistema::recorrerUsuarios()
{
  IIterator *it = this->usuarios->getIterator();
  while (it->hasCurrent())
  {
    Usuario *user = (Usuario *)it->getCurrent();
    cout << user->getEmail() << endl;
    it->next();
  }
  delete it;
}

void Sistema::altaUsuario(DtUsuario *user)
{
  if (user->getTipo() == "DtJugador")
  {
    Jugador *player = (Jugador *)user;
    string email = user->getEmail(); // cambié player por user
    string nickname = player->getNickname();
    bool emailExiste = false;
    bool nicknameExiste = false;
    IIterator *it = this->usuarios->getIterator();
    while (it->hasCurrent() && !emailExiste && !nicknameExiste)
    {
      string nominstanciaactual = typeid(*it->getCurrent()).name();
      nominstanciaactual = removerNumeros(nominstanciaactual);

      if (nominstanciaactual == "Desarrollador")
      {
        it->next();
      }
      if (nominstanciaactual == "Jugador")
      {
        Jugador *jg = (Jugador *)it->getCurrent();
        if (jg->getEmail() == email)
        {
          emailExiste = true;
          throw invalid_argument("ERROR: Ya existe un usuario con el email \"" + email +  "\"");
        }
        if (jg->getNickname() == nickname)
        {
          nicknameExiste = true;
          throw invalid_argument("ERROR: Ya existe un usuario con el nickname \"" + nickname + "\"");
        }
      }
      it->next();
    }
    delete it;
    // no se encontró usuario repetido (con ese email o nickname), se da de alta el usuario.
    if (!emailExiste && !nicknameExiste)
    {
      Jugador *jugador = new Jugador(player->getNickname(), player->getDescripcion(), player->getEmail(), player->getPassword());
      char *charEmail = const_cast<char *>(email.c_str()); // paso de string a char* (para poder implementar la key)
      String *email = new String(charEmail);
      OrderedKey *key = dynamic_cast<OrderedKey *>(email);
      this->usuarios->add(key, jugador);
    }
  }
  else if (user->getTipo() == "DtDesarrollador")
  { // funciona
    Desarrollador *dev = (Desarrollador *)user;
    string stremail = user->getEmail();
    char *charemail = const_cast<char *>(stremail.c_str()); // paso de string a char* (para poder implementar la key)
    String *email = new String(charemail);
    OrderedKey *key = dynamic_cast<OrderedKey *>(email); // ikey

    ICollectible *desarr = usuarios->find(key);
    if (desarr == NULL)
    {
      Desarrollador *desarrollador = new Desarrollador(dev->getNomEmpresa(), dev->getEmail(), dev->getPassword());
      this->usuarios->add(key, desarrollador);
    }
    else
    {
      delete key;
      throw invalid_argument("ERROR: Ya existe un desarrollador con el email \"" + stremail + "\"");
    }
  }
}

bool Sistema::iniciarSesion(string email, string password)
{ // TODO: cambiar a dtUsusario
  bool login = false;
  char *charemail = const_cast<char *>(email.c_str());
  String *mail = new String(charemail); // paso de string a char* (para poder implementar la key)
  OrderedKey *key = dynamic_cast<OrderedKey *>(mail);

  ICollectible *usuario = usuarios->find(key);

  if (usuario != NULL)
  {
    string instancename = typeid(*usuario).name(); // almacena el nombre de la instancia en un string
    instancename = removerNumeros(instancename);

    if (instancename == "Desarrollador")
    {
      Desarrollador *dev = (Desarrollador *)usuario;
      if (dev->getPassword() == password)
      {
        this->loggUser = dev;
        cout << "EXITO: Te logueaste como desarrollador!" << endl; // BORRAR ESTA LINEA, SOLO PARA TESTEO
        login = true;
      }
      else
      {
        login = false;
        throw invalid_argument("ERROR: Password incorrecto");
      }
    }
    else if (instancename == "Jugador")
    {
      Jugador *player = (Jugador *)usuario;
      if (player->getPassword() == password)
      {
        this->loggUser = player;
        cout << "EXITO: Te logueaste como jugador!" << endl; // BORRAR ESTA LINEA, SOLO PARA TESTEO
        login = true;
      }
      else
      {
        login = false;
        throw invalid_argument("ERROR: Password incorrecto");
      }
    }
  }
  else
  {
    throw invalid_argument("ERROR: No existe un usuario con el email \"" + email + "\"");
  }
  return login;
}

DtVideojuego* Sistema::verInfoVideojuego(string name) {
  if (validateExistsGameName(name, this->videojuegos) == false) {
    cout << "No existe el videojuego" << endl;
    return NULL;
  }
  else {
    char *charNameVj = const_cast<char *>(name.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    Videojuego *juego = (Videojuego *)videojuegos->find(vjKey);

    DtVideojuego* Info = new DtVideojuego(juego->getNombre(), juego->getDescripcion(), juego->getPromedio_puntuacion(), juego->getPuntuaciones(), juego->getCategorias(), juego->getSuscripciones());
    
    return Info;  
  }
  return NULL;
}

string Sistema::getTipoLoggUser()
{
  return this->loggUser->getTipo();
}

ICollection * Sistema::listarCategorias()
{
  ICollection *res = new List();
  IIterator *it = this->categorias->getIterator();

  while(it->hasCurrent())
  {
    Categoria *cat = (Categoria *)it->getCurrent();
    if (cat->darNombreInstancia() == "CategoriaPlataforma")
    {
      CategoriaPlataforma *catPlataforma = (CategoriaPlataforma *)cat;
      DtCategoria * catAgregar = new DtCategoria(catPlataforma->getId(), catPlataforma->darTipo(), catPlataforma->getDescripcion(), "PLATAFORMA");
      res->add(catAgregar);
    }
    if (cat->darNombreInstancia() == "CategoriaGenero")
    {
      CategoriaGenero *catGenero = (CategoriaGenero *)cat;
      DtCategoria * catAgregar = new DtCategoria(catGenero->getId(), catGenero->darTipo(), catGenero->getDescripcion(), "GENERO");
      res->add(catAgregar);
    }
    if (cat->darNombreInstancia() == "CategoriaOtro")
    {
      CategoriaOtro *catOtro = (CategoriaOtro *)cat;
      DtCategoria * catAgregar = new DtCategoria(catOtro->getId(), catOtro->darTipo(), catOtro->getDescripcion(), "OTRO");
      res->add(catAgregar);
    }
    it->next();
  }
  delete it;
  return res;
}

ICollection * Sistema::listarSuscripcionesPorVideojuego(){
   if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
    }
    Jugador * jugador = (Jugador*)this->loggUser;
    string nickname = jugador->getNickname();

    ICollection * res = new List();  //Collection of DtSuscripcion

    IIterator * it = this->videojuegos->getIterator();
    Videojuego * current;
    
    string nombreV;
    ICollection * info_suscr_current;

    while (it->hasCurrent()){
        current = (Videojuego*)it->getCurrent();
        nombreV = current->getNombre();
        info_suscr_current = current->getInfoSuscripciones(nickname);
        
        ICollectible * videoJuegoInfoSus = new DtSuscripcion(nombreV,info_suscr_current);
        res->add(videoJuegoInfoSus);
        it->next();
    }
    delete it;
    return res;
};  


DtContratacion * Sistema::getContratacion(string nombreVideojuego){
   if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
    }
    Jugador * jugador = (Jugador*)this->loggUser;
    DtContratacion * res = jugador->getContratacionByUser(nombreVideojuego,this->fechaHora);
    return res;
}



void Sistema::confirmarSuscripcion(string nombreVideojuego, int idSuscripcion, ETipoPago metodoPago){
  if(this->loggUser == NULL){
    throw invalid_argument("Debes logearte primero");
  }
  Jugador * jugador = (Jugador*)this->loggUser;

  char *charNameVj = const_cast<char *>(nombreVideojuego.c_str());
  IKey *vjKey = new String(charNameVj);

   ICollectible * vJ = this->videojuegos->find(vjKey);
   if(vJ == NULL){  
     throw invalid_argument("El videojuego no existe");
   }
   Videojuego * juego  = (Videojuego*)vJ;
   
   Suscripcion * sus = juego->getSuscripcion(idSuscripcion);
   if(sus == NULL){
    throw invalid_argument("La suscripcion no esta asociada a este videojuego");
   }

   jugador->suscribirseAVideojuego(sus,metodoPago,this->fechaHora);

}


void Sistema::cancelarSuscripcion(int idContratacion){
    if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
    }
    Jugador * jugador = (Jugador*)this->loggUser;
    jugador->cancelarContratacion(idContratacion);
    
}

void Sistema::asignarPuntajeVideojuego(double puntaje,string nombreV){
  if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
  }
  Jugador * jugador = (Jugador*)this->loggUser;
  
  char *charnombreV = const_cast<char *>(nombreV.c_str());
  String *nombreGame = new String(charnombreV);
  ICollectible * item = this->videojuegos->find(nombreGame);
  if(item == NULL){
    throw invalid_argument("No existe el videjuego con el nombre: " + nombreV );
  }
  Videojuego * videojuego = (Videojuego*)item;
  videojuego->agregarPuntuacion(puntaje,jugador);

}


  void Sistema::finalizarPartida(int idPartida){
     if(this->loggUser == NULL){
      throw invalid_argument("Debes logearte primero");
     }
     Jugador * jugador = (Jugador*)this->loggUser;
     jugador->finalizarPartida(idPartida, this->fechaHora);
     
  }

   ICollection * Sistema::listarPartidasUnido(){ 
      if(this->loggUser == NULL){ 
        throw invalid_argument("Debes logearte primero");
      }
      Jugador * jugador = (Jugador*)this->loggUser;
      ICollection * res = jugador->listarPartidasUnido();
      return res;
    
    } 

  void  Sistema::abandonarPartida(int idPartida){
    if(this->loggUser == NULL){ 
      throw invalid_argument("Debes logearte primero");
    }
    Jugador * jugador = (Jugador*)this->loggUser;
    jugador->abandonarPartida(idPartida,this->fechaHora);

  }

  PartidaMultijugador * Sistema::partidaMasLarga() {
    IIterator * itJugadores = this->usuarios->getIterator();
    PartidaMultijugador * partidaMasLarga = NULL;
    
    while (itJugadores->hasCurrent())
    {
      Usuario * user = (Usuario *)itJugadores->getCurrent();
      if (user->getTipo() == "Jugador"){
        Jugador * player = (Jugador *)user;
        PartidaMultijugador * partidaMasLargaDeUser = player->partidaMasLarga();
        if (partidaMasLarga == NULL && partidaMasLargaDeUser != NULL) {
          partidaMasLarga = partidaMasLargaDeUser;
        } 
        if (partidaMasLargaDeUser != NULL && partidaMasLargaDeUser->getDuracion() > partidaMasLarga->getDuracion()) {
          partidaMasLarga = partidaMasLargaDeUser;
        }
      }

      itJugadores->next();
    }

    return partidaMasLarga;
  }

#endif