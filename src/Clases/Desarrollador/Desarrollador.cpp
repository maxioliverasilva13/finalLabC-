#ifndef DESARROLLADOR_FUNCTIONS
#define DESARROLLADOR_FUNCTIONS
#include "Desarrollador.h"

using namespace std;

Desarrollador::Desarrollador(string ne, string email, string pass) : Usuario(email, pass)
{
    this->nomEmpresa = ne;
}

void Desarrollador::setNomEmpresa(string ne)
{
    this->nomEmpresa = ne;
}

string Desarrollador::getNomEmpresa()
{
    return this->nomEmpresa;
}

string Desarrollador::getTipo() {
    return "Desarrollador";
}

#endif