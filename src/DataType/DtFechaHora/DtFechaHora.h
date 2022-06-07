#ifndef DTFECHAHORA_HEADER
#define DTFECHAHORA_HEADER

#include<iostream>

class DtFechaHora{
    private:
       int day;
       int month;
       int year;
       int hour;
       int minute;
    public:
      DtFechaHora(int day, int month, int year, int hour, int minute);
      int getDay();
      int getMonth();
      int getYear();
      int getHour();
      int getMinute();      
};

#endif