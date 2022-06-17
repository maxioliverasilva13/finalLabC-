#ifndef DESARROLLADOR_HEADER
#define DESARROLLADOR_HEADER

using namespace std;

class Desarrollador : public Usuario
{
private:
    string nomEmpresa;
    
public:
    Desarrollador(string, string, string);
    void setNomEmpresa(string);
    string getNomEmpresa();
    string getTipo();
};

#endif