//#ifndef DTDESARROLLADOR_CPP
//#define DTDESARROLLADOR_CPP

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

// es un virtual para hacer comprobaciones con el nombre de la instancia.
string DtDesarrollador::getTipo(){
    return "DtDesarrollador";
}

//#endif