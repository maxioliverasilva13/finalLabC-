#ifndef DESARROLLADOR_HEADER
#define DESARROLLADOR_HEADER

#include<iostream>
#include "../Usuario/Usuario.h"
using namespace std;

class desarrollador : public usuario {
    private:
        string nomEmpresa;
    public:
        desarrollador(string, string, string);
        void setNomEmpresa(string);
        string getNomEmpresa();
};

#endif
