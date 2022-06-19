#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include <iostream>
using namespace std;

class Categoria : public ICollectible
{
protected:
    static int id;
    string descripcion;

public:
    Categoria(string);
    ~Categoria();
    void setDescripcion(string);
    string getDescripcion();
    int getId();
    virtual string darTipo() = 0;
    virtual string darNombreInstancia() = 0;
};

int Categoria::id;

Categoria::Categoria(string descripcion)
{
    Categoria::id++;
    this->descripcion = descripcion;
}

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
