#include<iostream>
#include "src/Clases/Sistema.cpp"
#include "menu.cpp"

#include <typeinfo>

using namespace std;

class Sistema;

int main() {
    // menu();

   try
   {
     Sistema * s = Sistema::getInstance();  
     Videojuego * vj = new Videojuego("God of war", "algo", 0); 
     DtJugador * jugador1 = new DtJugador("algo@algo.com", "algo123", "maxi1", "asd11");
     DtJugador * jugador2 = new DtJugador("meto@meto.com", "alt", "maxi2", "asd11");
     DtJugador * jugador3 = new DtJugador("tata@tata.com", "mick", "maxi3", "asd11");   
     s->altaUsuario(jugador1);
     s->altaUsuario(jugador2);
     s->altaUsuario(jugador3);  
     s->iniciarSesion("tata@tata.com", "mick"); 
     ICollection * players = new List();
     String *jug1 = new String("maxi1");
     String *jug2 = new String("maxi2");
     String *jug3 = new String("maxi3");
     players->add(jug1);
     players->add(jug2);    
    s->iniciarPartidaMultijugador(players, true, vj);

     cout << endl << "jeje" << endl;
   }
   catch(const std::exception& e)
   {
    cout << e.what();
   }
   
};
