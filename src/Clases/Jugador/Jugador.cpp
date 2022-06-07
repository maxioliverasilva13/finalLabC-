#include<iostream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador(string nick, string desc, string email, string pass):Usuario(email, pass){
    this->nickname = nick;
    this->descripcion = desc;
}

void Jugador::setNickname(string nick) {
    this->nickname = nick;
}

void Jugador::setDescripcion(string des) {
    this->descripcion = des;
}

string Jugador::getNickname() {
    return this->nickname;
}

string Jugador::getDescripcion() {
    return this->descripcion;
}

