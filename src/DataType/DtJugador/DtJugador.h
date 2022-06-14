#ifndef DTJUGADOR_HEADER
#define DTJUGADOR_HEADER

#include<string>
#include "../DtUsuario/DtUsuario.h"
using std::string;

class DtJugador : public DtUsuario {
    private:
      string nickname;
      string descripcion;
    public:
      DtJugador(string email, string password, string nickname,string descripcion);
      string getNickname();
      string getDescripcion();
      string getTipo();
};

#endif