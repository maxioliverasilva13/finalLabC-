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
    static int countItems;
    Contratacion(ETipoPago, float, DtFechaHora *, DtFechaHora *, bool, Suscripcion *, Jugador *);
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
<<<<<<< HEAD
    bool getActiva();
    string getNickNameDuenio();
    string getNombreVideojuego();
    void asociarVideojuegoSuscripcion();
};
=======
    bool getActiva(DtFechaHora *);
    string getNickNameDuenio();
    string getVideojuego();
    void asociarVideojuegoSuscripcion();
};

>>>>>>> 0526c5c6e7fe2fed2054c341c199beb6df9533e7
#endif