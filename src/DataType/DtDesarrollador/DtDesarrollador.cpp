#ifndef DTDESARROLLADOR_HEADER
#define DTDESARROLLADOR_HEADER

#include <string>
using std::string;

class DtDesarrollador : public DtUsuario
{
private:
    string nombreEmpresa;

public:
    DtDesarrollador(string email, string password, string nombreEmpresa);
    string getNombreEmpresa();
    string getTipo();
};

using namespace std;

DtDesarrollador::DtDesarrollador(string email, string password, string nombreEmpresa) : DtUsuario(email, password)
{
    this->nombreEmpresa = nombreEmpresa;
};

string DtDesarrollador::getNombreEmpresa()
{
    return this->nombreEmpresa;
}

// es un virtual para hacer comprobaciones con el nombre de la instancia.
string DtDesarrollador::getTipo()
{
    return "DtDesarrollador";
}

#endif
