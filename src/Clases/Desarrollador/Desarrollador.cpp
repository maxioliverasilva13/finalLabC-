#include<iostream>
#include "Desarrollador.h"

using namespace std;

desarrollador::desarrollador(string ne, string email, string pass):usuario(email, pass){
    this->nomEmpresa = ne;
}

void desarrollador::setNomEmpresa(string ne) {
    this->nomEmpresa = ne;
}

string desarrollador::getNomEmpresa() {
    return this->nomEmpresa;
}
