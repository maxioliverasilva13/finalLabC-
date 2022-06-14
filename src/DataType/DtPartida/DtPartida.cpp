
#ifndef DTPARTIDA_HEADER
#define DTPARTIDA_HEADER

#include <iostream>
using namespace std;

class DtPartida
{
private:
    int id;
    DtFechaHora *fecha;
    int duracion;

public:
    DtPartida(int, DtFechaHora *, int);
    int getId();
    DtFechaHora *getFecha();
    int getDuracion();
};

DtPartida::DtPartida(int id, DtFechaHora *fecha, int duracion)
{
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
};

int DtPartida::getId()
{
    return this->id;
}

DtFechaHora *DtPartida::getFecha()
{
    return this->fecha;
}

int DtPartida::getDuracion()
{
    return this->duracion;
}

#endif
