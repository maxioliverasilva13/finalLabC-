#include "Categoria.h"
#include "../../ICollection/interfaces/ICollectible.cpp"
#include<iostream>


using namespace std;

Categoria::Categoria(string descripcion, int id) {
    this->id = id;
    this->descripcion = descripcion;
}

void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}

int Categoria::getId() {
    return this->id;
}

void Categoria::setId(int id) {
    this->id = id;
}

Categoria::~Categoria(){
    cout << "Me borro";
}
