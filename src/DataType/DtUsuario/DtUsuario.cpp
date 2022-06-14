#ifndef DTUSUARIO_HEADER
#define DTUSUARIO_HEADER

#include <iostream>
using namespace std;

class DtUsuario
{
private:
    string email;
    string password;

public:
    DtUsuario(string email, string password);
    string getEmail();
    string getPassword();
    virtual string getTipo() = 0; // es para hacer comprobaciones con el nombre de la instancia.
};

DtUsuario::DtUsuario(string email, string password)
{
    this->email = email;
    this->password = password;
}

string DtUsuario::getEmail()
{
    return this->email;
}

string DtUsuario::getPassword()
{
    return this->password;
}

#endif
