#ifndef CONTRATACION_FUNCTIONS
#define CONTRATACION_FUNCTIONS

#include <iostream>
#include "Contratacion.h"

using namespace std;

int Contratacion::countItems = 0;

Contratacion::Contratacion(ETipoPago tipoPago, float monto, DtFechaHora *FechaHora,
                           DtFechaHora *FechaVencimiento, bool cancelada, Suscripcion *suscripcion, Jugador *duenio)
{
    this->tipoPago = tipoPago;
    this->monto = monto;
    this->FechaHora = FechaHora;
    this->FechaVencimiento = FechaVencimiento;
    this->cancelada = cancelada;
    this->suscripcion = suscripcion;
    this->duenio = duenio;

    this->countItems++;
    this->id = this->countItems;
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

bool Contratacion::getActiva(DtFechaHora * ahora)
{
    if(this->cancelada){
        return !this->cancelada;
    }

    EPeriodo e_periodo = this->suscripcion->getPeriodo();
    if(e_periodo == VITALICIA){
        return true;
    }

   time_t t = time(0);
   tm *now = localtime(&t);
   int dia = now->tm_mday;
   int mes = 1 + now->tm_mon;
   int anio = 1900 + now->tm_year;
   int hora = now->tm_hour;
   int minuto = now->tm_min;
    

   if(ahora->getYear() > this->FechaVencimiento->getYear()){
     return false;
   }

   if(ahora->getYear() == this->FechaVencimiento->getYear() &&
   ahora->getMonth() > this->FechaVencimiento->getMonth()){
     return false;
   }  

   if(ahora->getYear() == this->FechaVencimiento->getYear() &&
   ahora->getMonth() == this->FechaVencimiento->getMonth() &&
   ahora->getDay() > this->FechaVencimiento->getDay()){
     return false;
   }  

   if(ahora->getYear() == this->FechaVencimiento->getYear() &&
   ahora->getMonth() == this->FechaVencimiento->getMonth() &&
   ahora->getDay() == this->FechaVencimiento->getDay() &&
   ahora->getHour() > this->FechaVencimiento->getHour()){
     return false;
   }  

 if(ahora->getYear() == this->FechaVencimiento->getYear() &&
   ahora->getMonth() == this->FechaVencimiento->getMonth() &&
   ahora->getDay() == this->FechaVencimiento->getDay() &&
   ahora->getHour() == this->FechaVencimiento->getHour() &&
   ahora->getMinute() > this->FechaVencimiento->getMinute()){
     return false;
  }  

  return true;
}

string Contratacion::getNickNameDuenio()
{
    return this->duenio->getNickname();
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
