#ifndef USUARIO_HEADER
#define USUARIO_HEADER

#include<iostream>

using namespace std;

class Usuario : public ICollectible {
    private:
        string email;
        string password;
    public:
        Usuario(string, string);
        void setEmail(string);
        void setPassword(string);
        string getEmail();
        string getPassword();
        virtual string getTipo() = 0;
};


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