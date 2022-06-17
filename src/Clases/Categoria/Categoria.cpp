#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER

#include <iostream>
using namespace std;

class Categoria : public ICollectible
{
private:
    int id;
    string descripcion;

public:
    Categoria(string, int);
    ~Categoria();
    void setDescripcion(string);
    void setId(int);
    string getDescripcion();
    int getId();
    virtual string darTipo() = 0;
    virtual string darNombreInstancia() = 0;
};

Categoria::Categoria(string descripcion, int id)
{
    this->id = id;
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
    return this->id;
}

void Categoria::setId(int id)
{
    this->id = id;
}

Categoria::~Categoria()
{
    cout << "Me borro";
}

#endif
