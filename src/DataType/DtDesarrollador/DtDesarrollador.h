#ifndef DTDESARROLLADOR_HEADER
#define DTDESARROLLADOR_HEADER

#include<string>
#include "../DtUsuario/DtUsuario.h"
using std::string;

class DtDesarrollador : public DtUsuario {
    private:
      string nombreEmpresa;
    public:
      DtDesarrollador(string email, string password, string nombreEmpresa);
      string getNombreEmpresa();
};

#endif