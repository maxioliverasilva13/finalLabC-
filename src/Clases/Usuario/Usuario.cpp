#include<iostream>
#include "Usuario.h"

using namespace std;

usuario::usuario(string e, string p){
    this->email = e;
    this->password = p;
}

void usuario::setEmail(string e) {
    this->email = e;
}

void usuario::setPassword(string p) {
    this->password = p;
}

string usuario::getEmail() {
    return this->email;
}

string usuario::getPassword() {
    return this->password;
}
