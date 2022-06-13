#ifndef CONTRATACION_HEADER
#define CONTRATACION_HEADER

#include<iostream>

using namespace std;

#include "../../Enum/index.cpp"
#include "../../DataType/DtFechaHora/DtFechaHora.h"
#include "../Suscripcion/Suscripcion.h"
#include "../Jugador/Jugador.h"
#include "../../ICollection/interfaces/ICollectible.h"

class Contratacion: public ICollectible {
    private:
        int id;
        ETipoPago tipoPago;
        float monto;
        DtFechaHora * FechaHora;
        DtFechaHora * FechaVencimiento;
        bool cancelada;
        Suscripcion * suscripcion;
        Jugador * duenio;
        
    
    public:
        Contratacion(int, ETipoPago,float,DtFechaHora*,DtFechaHora*,bool,Suscripcion * suscripcion, Jugador * duenio);
        int getId();
        float getMonto();
        ETipoPago getTipoPago();
        DtFechaHora * getFechaHora();
        DtFechaHora * getFechaVencimiento();
        bool getCancelada();
        void setId(int);
        void setMonto(float);
        void setFechaHora(DtFechaHora *);
        void setFechaVencimiento(DtFechaHora *);
        void setCancelada(bool);
        void setTipoPago(ETipoPago);
        bool getActiva();
        string getNickNameDueño();
        string getVideojuego();
        void asociarVideojuegoSuscripcion();        
};
   

#endif