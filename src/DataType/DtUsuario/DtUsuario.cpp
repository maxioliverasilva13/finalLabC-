#include <iostream>
#include "DtUsuario.h"

using namespace std;

DtUsuario::DtUsuario(string email,string password){
   this->email = email;
   this->password = password;
}



string DtUsuario::getEmail(){
    return this->email;
}


string DtUsuario::getPassword(){
    return this->password;
}


