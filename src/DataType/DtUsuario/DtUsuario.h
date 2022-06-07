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
};

#endif