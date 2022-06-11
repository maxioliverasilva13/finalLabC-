#include<iostream>
#include "Jugador.h"
#include "../Usuario/Usuario.cpp"
#include "../../ICollection/Integer.cpp"
#include "../../Clases/Partida/Partida.cpp"

using namespace std;

Jugador::Jugador(string nick, string desc, string email, string pass):Usuario(email, pass){
    this->nickname = nick;
    this->descripcion = desc;
    this->partidas = new OrderedDictionary();
    this->contrataciones = new OrderedDictionary();
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

DtContratacion * Jugador::getContratacionByUser(int contratoId) {
    return NULL;
}

void Jugador::agregarPartida(Partida * part) {
    Integer * idKey = new Integer(part->getId());
    this->partidas->add(idKey, part);
};

