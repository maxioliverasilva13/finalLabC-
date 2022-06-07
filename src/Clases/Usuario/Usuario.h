#ifndef USUARIO_HEADER
#define USUARIO_HEADER

#include<iostream>
using namespace std;

class Usuario {
    private:
        string email;
        string password;
    public:
        Usuario(string, string);
        void setEmail(string);
        void setPassword(string);
        string getEmail();
        string getPassword();
};

#endif
