#ifndef DTUSUARIO_HEADER
#define DTUSUARIO_HEADER

#include<iostream>

class DtUsuario{
    private:
       string email;
       string password;
    public:
      DtUsuario(string email,string password);
      string getEmail();
      string getPassword(); 
      virtual string getTipo() = 0; // es para hacer comprobaciones con el nombre de la instancia.
};

#endif