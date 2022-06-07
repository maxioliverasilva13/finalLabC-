#include<iostream>
#include "DtCategoria.h"

using namespace std;

DtCategoria::DtCategoria(string nombre,string descripcion ,string tipo){
    this->nombre = nombre;
    this->descripcion = descripcion; 
    this->tipo = tipo;
};

string DtCategoria::getNombre(){
    return this->nombre;
}

string DtCategoria::getDescripcion(){
    return this->descripcion;
}

string DtCategoria::getTipo(){
    return this->tipo;
}