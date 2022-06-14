//#ifndef USUARIO_HEADER
//#define USUARIO_HEADER

#include<iostream>
#include "../../ICollection/interfaces/ICollection.h"

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
};

//#endif
