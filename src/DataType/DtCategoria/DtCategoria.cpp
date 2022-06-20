#ifndef DTCATEGORIA_HEADER
#define DTCATEGORIA_HEADER

#include <iostream>
#include <string>

using namespace std;

class DtCategoria : public ICollectible
{
private:
    int id;
    string nombre;
    string descripcion;
    string tipo; // este string tendria que ser igual a ETIPOPLAYAFORMA y ETIPOGENERO
public:
    DtCategoria(int id,string nombre, string descripcion, string tipo);
    string getNombre();
    string getDescripcion();
    string getTipo();
    int getId();
};

DtCategoria::DtCategoria(int id,string nombre, string descripcion, string tipo)
{
    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
};

string DtCategoria::getNombre()
{
    return this->nombre;
}

int DtCategoria::getId()
{
    return this->id;
}

string DtCategoria::getDescripcion()
{
    return this->descripcion;
}

string DtCategoria::getTipo()
{
    return this->tipo;
}

#endif
