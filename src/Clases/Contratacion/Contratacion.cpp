#ifndef CONTRATACION_FUNCTIONS
#define CONTRATACION_FUNCTIONS

#include <iostream>
#include "Contratacion.h"

using namespace std;

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

Contratacion::~Contratacion()
{
    this->FechaHora = NULL;
    this->FechaVencimiento = NULL;
    this->suscripcion = NULL;
    this->duenio->eliminarSuscripcion(this);
    cout << "bueno me voy a borrar" << endl;
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

string Contratacion::getNombreVideojuego()
{
    return this->suscripcion->darNombreJuego();
}

void Contratacion::asociarVideojuegoSuscripcion()
{
    /*POR IMPLEMENTAR*/
}

#endif
