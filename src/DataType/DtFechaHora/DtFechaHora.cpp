#ifndef DTFECHAHORA_HEADER
#define DTFECHAHORA_HEADER

#include <iostream>

class DtFechaHora
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

public:
    DtFechaHora();
    DtFechaHora(int day, int month, int year, int hour, int minute);
    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    DtFechaHora * getAhora();
};

using namespace std;

DtFechaHora::DtFechaHora(int day, int month, int year, int hour, int minute)
{
    if (day > 30 || day < 1)
    {
        throw invalid_argument("Dia es invalido");
    }
    if (month > 12 || month < 1)
    {
        throw invalid_argument("Mes es invalido");
    }
    if (year < 1900)
    {
        throw invalid_argument("Año invalido");
    }
    if (hour < 0 || hour > 23)
    {
        throw invalid_argument("Hora invalida");
    }
    if (minute < 0 || minute > 59)
    {
        throw invalid_argument("Minuto invalido");
    }
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
}

DtFechaHora * DtFechaHora::getAhora() {
  time_t t = time(0);
  tm *now = localtime(&t);
  int dia = now->tm_mday;
  int mes = 1 + now->tm_mon;
  int anio = 1900 + now->tm_year;
  int hora = now->tm_hour;
  int minuto = now->tm_min;
  DtFechaHora *ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
  return ahora;
}

int DtFechaHora::getDay()
{
    return this->day;
}

int DtFechaHora::getMonth()
{
    return this->month;
}

int DtFechaHora::getYear()
{
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
