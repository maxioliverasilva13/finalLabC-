#ifndef CONTRATACION_HEADER
#define CONTRATACION_HEADER

#include <iostream>
#include "../../Clases/Suscripcion/Suscripcion.cpp"
#include "../../Clases/Jugador/Jugador.cpp"
#include "../../DataType/DtFechaHora/DtFechaHora.cpp"

using namespace std;

class Contratacion : public ICollectible
{
private:
    int id;
    ETipoPago tipoPago;
    float monto;
    DtFechaHora *FechaHora;
    DtFechaHora *FechaVencimiento;
    bool cancelada;
    Suscripcion *suscripcion;
    Jugador *duenio;

public:
    Contratacion(int, ETipoPago, float, DtFechaHora *, DtFechaHora *, bool, Suscripcion *, Jugador *);
    int getId();
    float getMonto();
    ETipoPago getTipoPago();
    DtFechaHora *getFechaHora();
    DtFechaHora *getFechaVencimiento();
    bool getCancelada();
    void setId(int);
    void setMonto(float);
    void setFechaHora(DtFechaHora *);
    void setFechaVencimiento(DtFechaHora *);
    void setCancelada(bool);
    void setTipoPago(ETipoPago);
    bool getActiva();
    string getNickNameDuenio();
    string getVideojuego();
    void asociarVideojuegoSuscripcion();
};

Contratacion::Contratacion(int id, ETipoPago tipoPago, float monto, DtFechaHora *FechaHora,
                           DtFechaHora *FechaVencimiento, bool cancelada, Suscripcion *suscripcion, Jugador *duenio)
{
    this->id = id;
    this->tipoPago = tipoPago;
    this->monto = monto;
    this->FechaHora = FechaHora;
    this->FechaVencimiento = FechaVencimiento;
    this->cancelada = cancelada;
    this->suscripcion = suscripcion;
    this->duenio = duenio;
}

int Contratacion::getId()
{
    return this->id;
}
float Contratacion::getMonto()
{
    return this->monto;
}
DtFechaHora *Contratacion::getFechaHora()
{
    return this->FechaHora;
}
DtFechaHora *Contratacion::getFechaVencimiento()
{
    return this->FechaVencimiento;
}
ETipoPago Contratacion::getTipoPago()
{
    return this->tipoPago;
}
bool Contratacion::getCancelada()
{
    return this->cancelada;
}

void Contratacion::setId(int id)
{
    this->id = id;
}

void Contratacion::setMonto(float monto)
{
    this->monto = monto;
}

void Contratacion::setFechaHora(DtFechaHora *fechaHora)
{
    this->FechaHora = fechaHora;
}

void Contratacion::setFechaVencimiento(DtFechaHora *fechaVencimiento)
{
    this->FechaVencimiento = fechaVencimiento;
}

void Contratacion::setCancelada(bool cancelada)
{
    this->cancelada = cancelada;
}

void Contratacion::setTipoPago(ETipoPago tipoPago)
{
    this->tipoPago = tipoPago;
}

bool Contratacion::getActiva()
{
    /*POR IMPLEMENTAR*/
}

string Contratacion::getNickNameDuenio()
{
    /*POR IMPLEMENTAR*/
}

string Contratacion::getVideojuego()
{
    /*POR IMPLEMENTAR*/
}

void Contratacion::asociarVideojuegoSuscripcion()
{
    /*POR IMPLEMENTAR*/
}

#endif