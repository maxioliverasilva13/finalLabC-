#ifndef CONTRATACION_HEADER
#define CONTRATACION_HEADER

#include <iostream>

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
    ~Contratacion();
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
    string getNombreVideojuego();
    void asociarVideojuegoSuscripcion();
};
#endif