#ifndef USUARIO_HEADER
#define USUARIO_HEADER

#include<iostream>
using namespace std;

class usuario {
    private:
        string email;
        string password;
    public:
        usuario(string, string);
        void setEmail(string);
        void setPassword(string);
        string getEmail();
        string getPassword();
};

#endif
