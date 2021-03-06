#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include <iostream>
using namespace std;

class Categoria : public ICollectible
{
protected:
    static int cant;
    int id;
    string customName;
    string descripcion;

public:
    Categoria(string);
    ~Categoria();
    void setDescripcion(string);
    string getDescripcion();
    int getId();
    virtual string darTipo() = 0;
    virtual string darNombreInstancia() = 0;
    void setCustomName(string);
    string getCustomName();
};

int Categoria::cant = 0;

Categoria::Categoria(string descripcion)
{
    
    Categoria::cant++;
    this->id = cant;
    this->descripcion = descripcion;
}

void Categoria::setCustomName(string customName) {
    this->customName = customName;
};

string Categoria::getCustomName(){
    return this->customName;
};

void Categoria::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

string Categoria::getDescripcion()
{
    return this->descripcion;
}

int Categoria::getId()
{
    return Categoria::id;
}

Categoria::~Categoria()
{
    cout << "Me borro";
}

#endif
