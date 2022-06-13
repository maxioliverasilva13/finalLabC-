#include <ctime>

#include "Sistema.h"
#include "../ICollection/interfaces/IDictionary.cpp"
#include "../ICollection/collections/OrderedDictionary.cpp"
#include "../ICollection/collections/OrderedDictionaryentry.cpp"
#include "../ICollection/collections/ListIterator.cpp"
#include "../ICollection/collections/ListNode.cpp"
#include "../ICollection/interfaces/OrderedKey.cpp"
#include "../ICollection/interfaces/IIterator.cpp"
#include "../ICollection/interfaces/IKey.cpp"
#include "../ICollection/String.cpp"
#include "Desarrollador/Desarrollador.cpp"
#include "Jugador/Jugador.cpp"
#include <typeinfo>


Sistema * Sistema::instance = NULL;

Sistema::Sistema(){
  this->categorias = new OrderedDictionary();
  this->videojuegos = new OrderedDictionary();
  this->usuarios = new OrderedDictionary();

  time_t t = time(0);
  tm* now = localtime(&t);    
  int dia = now->tm_mday;
  int mes = 1 + now->tm_mon;
  int anio = 1900 + now->tm_year;
  int hora = now->tm_hour;
  int minuto = now->tm_min;
  DtFechaHora * ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
  this->fechaHora = ahora;
}

Sistema * Sistema::getInstance(){
  if (Sistema::instance == NULL){
    Sistema::instance = new Sistema();
  }
  return Sistema::instance;
}

// terminada
void Sistema::modificarFechaSistema(DtFechaHora * fechahora){
  this->fechaHora = fechahora;
}


DtFechaHora * Sistema::getFechaSistema(){
  return this->fechaHora;
}

void Sistema::recorrerUsuarios(){
  IIterator * it = this->usuarios->getIterator();
  while(it->hasCurrent()){
    Usuario * user = (Usuario*)it->getCurrent();
    cout << user->getEmail() << endl;
    it->next();
  }
}

//Auxiliar para altaUsuario e iniciarSesion
string removerNumeros(string str) {
    for(int i = 0; i < str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                str.erase(i, 1);
                i--;
            }
        }
    return str;
}


void Sistema::altaUsuario(DtUsuario * user){
  
  if(user->getTipo() == "DtJugador"){
    Jugador * player = (Jugador *)user;
    string email = user->getEmail();  // cambié player por user
    string nickname = player->getNickname();
    bool emailExiste = false;
    bool nicknameExiste = false;
    IIterator * it = this->usuarios->getIterator();
    while(it->hasCurrent() && !emailExiste && !nicknameExiste){
      string nominstanciaactual = typeid(*it->getCurrent()).name();
      nominstanciaactual = removerNumeros(nominstanciaactual);

      if(nominstanciaactual == "Desarrollador"){
        cout << "Estoy parado en 1 Desarrollador" << endl;
        it->next();
      } 
      if(nominstanciaactual == "Jugador"){
        cout << "Estoy parado en 1 Jugador" << endl;
        Jugador * jg = (Jugador*)it->getCurrent();
        if(jg->getEmail() == email){
          emailExiste = true;
          throw invalid_argument("ERROR: Ya existe un usuario con ese email.");
        }
        if(jg->getNickname() == nickname){
          nicknameExiste = true;
          throw invalid_argument("ERROR: Ya existe un usuario con ese nickname.");
        }
      }
      it->next();
    }
    // no se encontró usuario repetido (con ese email o nickname), se da de alta el usuario.
    if(!emailExiste && !nicknameExiste){
      Jugador * jugador = new Jugador(player->getNickname(), player->getDescripcion(), player->getEmail(), player->getPassword());
      char* charEmail = const_cast<char*>(email.c_str()); // paso de string a char* (para poder implementar la key)
      String * email = new String(charEmail);
      OrderedKey *key = dynamic_cast<OrderedKey *>(email);
      this->usuarios->add(key, jugador);
    }
  }else if(user->getTipo() == "DtDesarrollador"){ // funciona
    Desarrollador * dev = (Desarrollador *)user;
    string stremail = user->getEmail();
    char* charemail = const_cast<char*>(stremail.c_str()); // paso de string a char* (para poder implementar la key)
    String * email = new String(charemail);
    OrderedKey *key = dynamic_cast<OrderedKey *>(email); // ikey

    ICollectible * desarr = usuarios->find(key);
    if (desarr == NULL){
      Desarrollador * desarrollador = new Desarrollador(dev->getNomEmpresa(), dev->getEmail(), dev->getPassword());
      this->usuarios->add(key, desarrollador); 
    }
    else{
      delete key;
      throw invalid_argument("ERROR: Ya existe un desarrollador con ese email.");
    }
  }
}


// TODO: login
bool Sistema::iniciarSesion(string email, string password){  // TODO: cambiar a dtUsusario
  bool login = false;
  char* charemail = const_cast<char*>(email.c_str());
  String * mail = new String(charemail); // paso de string a char* (para poder implementar la key)
  OrderedKey * key = dynamic_cast<OrderedKey *>(mail);

  ICollectible * usuario = usuarios->find(key);
  
  if (usuario != NULL){
    string instancename = typeid(*usuario).name(); // almacena el nombre de la instancia en un string
    instancename = removerNumeros(instancename);

    if(instancename == "Desarrollador"){
      Desarrollador * dev = (Desarrollador *)usuario;
      if(dev->getPassword() == password){
        this->loggUser = dev;
        cout << "¡Te logueaste como desarrollador!" << endl;  // BORRAR ESTA LINEA, SOLO PARA TESTEO
        login = true;
      }else{
        login = false;
        throw invalid_argument("ERROR: Password incorrecto");
      }
    }else if(instancename == "Jugador"){
      Jugador * player = (Jugador *)usuario;
      if(player->getPassword() == password){
        this->loggUser = player;
        cout << "¡Te logueaste como jugador!" << endl;        // BORRAR ESTA LINEA, SOLO PARA TESTEO
        login = true;
      }else{
        login = false;
        throw invalid_argument("ERROR: Password incorrecto");
      }
    }
    }else{
      throw invalid_argument("ERROR: No existe un usuario con ese email");
    }
  return login;
}

// CASTEO:
//usuario * user = (Usuario*)it->getCurrent();
