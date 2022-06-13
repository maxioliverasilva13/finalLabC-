//#ifndef DTJUGADOR_CPP
//#define DTJUGADOR_CPP

#include<iostream>
#include "DtJugador.h"
#include "../DtUsuario/DtUsuario.h"

using namespace std;


DtJugador::DtJugador(string email,string password,string nickname,string descripcion):DtUsuario(email,password) {
    this->nickname = nickname;
    this->descripcion = descripcion;
};

string DtJugador::getNickname(){
    return this->nickname;
}

string DtJugador::getDescripcion(){
    return this->descripcion; 
}

// es un virtual para hacer comprobaciones con el nombre de la instancia.
string DtJugador::getTipo(){
    return "DtJugador";
}

//#endif