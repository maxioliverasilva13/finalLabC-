#include<iostream>

//#include "src/Clases/Sistema.cpp"
#include "menu.cpp"

//Sistema * s = Sistema::getInstance();


using namespace std;

void imprimirFecha(DtFechaHora * fecha){
  cout << fecha->getDay() << "/" << fecha->getMonth() << "/" << fecha->getYear() << " " << fecha->getHour() << ":" << fecha->getMinute() << endl;
}

//DtDesarrollador * d0 = new DtDesarrollador("rodrigo@asd.com", "ro123", "EmpresaRodrigo");
//DtDesarrollador * d1 = new DtDesarrollador("rodrigo@asd.com", "ro123", "EmpresaRodrigo");
//DtDesarrollador * d2 = new DtDesarrollador("rodrigo@asd.com", "ro123", "EmpresaRodrigo");
//Jugador * j1 = new Jugador("Manuel", "Soy Manuel", "asd@asd", "asd");
DtJugador * j2 = new DtJugador("manu3344@asd.com", "ma123", "Maxi", "Soy Maxi");
//DtJugador * j3 = new DtJugador("manu5566@asd.com", "ma123", "Manuel", "Soy manuel");


int main() {
    menu();
    //s->altaUsuario(j2);
    //cout << "1: " + s->getTipoLoggUser() << endl;
    //s->iniciarSesion(j2->getEmail(), j2->getPassword());
    //cout << s->getTipoLoggUser() << endl;
    return 0;
};