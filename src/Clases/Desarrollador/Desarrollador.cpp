#ifndef DESARROLLADOR_HEADER
#define DESARROLLADOR_HEADER


using namespace std;

class Desarrollador : public Usuario {
    private:
        string nomEmpresa;
    public:
        Desarrollador(string, string, string);
        void setNomEmpresa(string);
        string getNomEmpresa();
        string getTipo();
};


Desarrollador::Desarrollador(string ne, string email, string pass):Usuario(email, pass){
    this->nomEmpresa = ne;
}


void Desarrollador::setNomEmpresa(string ne) {
    this->nomEmpresa = ne;
}

string Desarrollador::getNomEmpresa() {
    return this->nomEmpresa;
}

string Desarrollador::getTipo() {
    return "Desarrollador";
}

#endif