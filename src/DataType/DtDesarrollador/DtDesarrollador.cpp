#include<iostream>
#include "DtDesarrollador.h"
#include "../DtUsuario/DtUsuario.h"

using namespace std;



DtDesarrollador::DtDesarrollador(string email,string password,string nombreEmpresa):DtUsuario(email,password) {
    this->nombreEmpresa = nombreEmpresa;
};

string DtDesarrollador::getNombreEmpresa(){
    return this->nombreEmpresa;
}