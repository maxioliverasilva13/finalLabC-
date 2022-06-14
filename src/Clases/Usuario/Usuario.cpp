#ifndef USUARIO_CPP
#define USUARIO_CPP


#include<iostream>
#include "Usuario.h"

using namespace std;

Usuario::Usuario(string e, string p){
    this->email = e;
    this->password = p;
}

void Usuario::setEmail(string e) {
    this->email = e;
}

void Usuario::setPassword(string p) {
    this->password = p;
}

string Usuario::getEmail() {
    return this->email;
}

string Usuario::getPassword() {
    return this->password;
}

#endif