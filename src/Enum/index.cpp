#ifndef ENUM_HEADER
#define ENUM_HEADER
#include<iostream>

using namespace std;

enum ETipoPago { PAYPAL, TARJETA };

enum EEstado { FINALIZADA, ENCURSO };

enum ETipoPlataforma { PLATAFORMA, XBOXONE , XBOXX, PS5, PC, SWITCH, PS4 };

enum EGeneroJuego { GENERO , ACCCION, AVENTURA, ESTRATEGIA, DEPORTE };

enum EPeriodo { MENSUAL, TRIMESTRAL, ANUAL, VITALICIA };


string getETipoPago(ETipoPago p) {
    switch (p)
    {
    case PAYPAL:
        return "PAYPAL";
    case TARJETA:
        return "TARJETA";
    default:
        return "NINGUNO";
    }
};

string getEstado(EEstado e) {
    switch (e)
    {
    case FINALIZADA:
        return "FINALIZADA";
    case ENCURSO:
        return "ENCURSO";
    default:
        return "NINGUNO";
    };
};

string getETipoPlataforma(ETipoPlataforma e) {
    switch (e)
    {
    case XBOXONE:
        return "XBOXONE";
    case XBOXX:
        return "XBOXX";
    case PS5:
        return "PS5";
    case PC:
        return "PC";
    case SWITCH:
        return "SWITCH";
    case PS4:
        return "PS4";
    default:
        return "NINGUNO";
    };
};

ETipoPlataforma getEnumETipoPlataforma(string tipo) {
    if (tipo == "XBOXONE") {
        return XBOXONE;
    }
    if (tipo == "XBOXX") {
        return XBOXX;
    }
    if (tipo == "PS5") {
        return PS5;
    }
    if (tipo == "PC") {
        return PC;
    }
    if (tipo == "SWITCH") {
        return SWITCH;
    }
    if (tipo == "PS4") {
        return PS4;
    }
};

string getEGeneroJuego(EGeneroJuego e) {
    switch (e)
    {
    case ACCCION:
        return "ACCCION";
    case AVENTURA:
        return "AVENTURA";
    case ESTRATEGIA:
        return "ESTRATEGIA";
    case DEPORTE:
        return "DEPORTE";
    default:
        return "NINGUNO";
    };
};

EGeneroJuego getEnumGeneroJuego(string tipo) {
    if (tipo == "ACCCION") {
        return ACCCION;
    }
    if (tipo == "AVENTURA") {
        return AVENTURA;
    }
    if (tipo == "ESTRATEGIA") {
        return ESTRATEGIA;
    }
    if (tipo == "DEPORTE") {
        return DEPORTE;
    }
};


string getEPeriodo(EPeriodo e) {
    switch (e)
    {
    case MENSUAL:
        return "MENSUAL";
    case TRIMESTRAL:
        return "TRIMESTRAL";
    case ANUAL:
        return "ANUAL";
    case VITALICIA:
        return "VITALICIA";
    default:
        return "NINGUNO";
    };
};

#endif

