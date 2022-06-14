#ifndef DTFECHAHORA_CPP
#define DTFECHAHORA_CPP


#include <iostream>
#include "DtFechaHora.h"

using namespace std;

DtFechaHora::DtFechaHora(int day , int month , int year, int hour, int minute){
    if(day > 30 || day < 1){
        throw invalid_argument("Dia es invalido");
    }
    if(month > 12 || month < 1){
        throw invalid_argument("Mes es invalido");
    }
    if (year < 1900){
        throw invalid_argument("Año invalido");
    }
    if (hour < 0 || hour > 23){
        throw invalid_argument("Hora invalida");
    }
    if (minute < 0 || minute > 59){
        throw invalid_argument("Minuto invalido");
    }
    this->day =  day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
}



int DtFechaHora::getDay(){
    return this->day;
}


int DtFechaHora::getMonth()
{
    return this->month;
}


int DtFechaHora::getYear(){
    return this->year;
}



int DtFechaHora::getHour()
{
    return this->hour;
}



int DtFechaHora::getMinute()
{
    return this->minute;
}


#endif