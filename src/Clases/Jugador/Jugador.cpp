#include<iostream>
#include "Jugador.h"

using namespace std;

jugador::jugador(string nick, string desc, string email, string pass):usuario(email, pass){
    this->nickname = nick;
    this->descripcion = desc;
}

void jugador::setNickname(string nick) {
    this->nickname = nick;
}

void jugador::setDescripcion(string des) {
    this->descripcion = des;
}

string jugador::getNickname() {
    return this->nickname;
}

string jugador::getDescripcion() {
    return this->descripcion;
}

