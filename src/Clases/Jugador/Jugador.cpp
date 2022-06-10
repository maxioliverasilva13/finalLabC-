#include<iostream>
#include "Jugador.h"
#include "../Usuario/Usuario.cpp"

using namespace std;

Jugador::Jugador(string nick, string desc, string email, string pass):Usuario(email, pass){
    this->nickname = nick;
    this->descripcion = desc;
    this->partidas = new OrderedDictionary();
}

Jugador::~Jugador() {
    cout << "Me borro";
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

void Jugador::agregarPartida(Partida * part) {
    Integer * idKey = new Integer(part->getId());
    this->partidas->add(idKey, part);
};
