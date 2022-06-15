#ifndef DTCONTRATACION_HEADER
#define DTCONTRATACION_HEADER

#include <iostream>

using namespace std;

class DtContratacion
{
private:
    int id;
    float monto;
    ETipoPago tipoPago;
    DtFechaHora *FechaHora;
    DtFechaHora *FechaVencimiento;
    bool cancelada;

public:
    DtContratacion(int id, float monto, ETipoPago tipoPago, DtFechaHora *FechaHora, DtFechaHora *FechaVencimiento, bool cancelada);
    int getId();
    ETipoPago getTipoPago();
    float getMonto();
    DtFechaHora *getFechaHora();
    DtFechaHora *getFechaVencimiento();
    bool getCancelada();
};

using namespace std;

DtContratacion::DtContratacion(int id, float monto, ETipoPago tipoPago, DtFechaHora *FechaHora, DtFechaHora *FechaVencimiento, bool cancelada)
{
    this->id = id;
    this->monto = monto;
    this->tipoPago = tipoPago;
    this->FechaHora = FechaHora;
    this->FechaVencimiento = FechaVencimiento;
};

int DtContratacion::getId()
{
    return this->id;
}

ETipoPago DtContratacion::getTipoPago()
{
    return this->tipoPago;
}

float DtContratacion::getMonto()
{
    return this->monto;
}

DtFechaHora *DtContratacion::getFechaHora()
{
    return this->FechaHora;
}

DtFechaHora *DtContratacion::getFechaVencimiento()
{
    return this->FechaVencimiento;
}

bool DtContratacion::getCancelada()
{
    return this->cancelada;
}

#endif