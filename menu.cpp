#include "src/Clases/Sistema.cpp"

#include <limits> // para validar ints en el cin
#include <iostream> 
#include <cstdlib> //es para el clear
#include <stdlib.h> // tambien para el clear pero fuera de windows
#include <string>
#include <cstdlib>

#ifdef _WIN32

  #include <windows.h>

  inline void sleep( unsigned long ms )
    {
    Sleep( ms * 1000);
    }

#else  /* POSIX */

  #include <unistd.h>

  inline void sleep( unsigned long ms )
    {
    usleep( ms );
    }

#endif

struct InfoSuscripcion{
    int id;
    bool suscrito;
    EPeriodo periodo;
};

using namespace std;

Sistema * s = Sistema::getInstance();
string usuarioActual = "";

void mostrarMenu();
int leerInt();
string leerString();

void mostrarMenuDesarrollador(); //contiene la interfaz grafica del menu de desarrollador
void mostrarMenuJugador(); //contiene la interfaz grafica del menu de jugador
void menu(); // itera llamando a los menús dependiendo del tipo de usuario logueado 
bool menuUsuario(); //contiene el switch de opciones del menu del usuario normal
void menuDesarrollador(); //contiene el switch de opciones del menu del desarrollador
void menuJugador(); //contiene el switch de opciones del menu del jugador


// *.*.*.*.*.*.*.*. Funciones del menú .*.*.*.*.*.*.*.*.*.*
// Usuario
void altaUsuarioMenu();
void iniciarSesionMenu();
void cargarDatosDePruebaMenu();


// Desarrollador
void agregarCategoriaMenu();
void publicarVideojuegoMenu();
void eliminarVideojuegoMenu();
void consultarEstadisticasMenu(); 
void verInfoVideojuegoMenu();
void modificarFechaSistemaMenu(); //hecha


//Jugador
void suscribirseAvideojuegoMenu();
void asignarPuntajeVJMenu();
void iniciarPartidaMenu();
void abandonarPartidaMJMenu();
void finalizarPartidaMenu();
void verInformacionVideojuegoMenu();


// *.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

// *.*.*.*.*.*. Funciones auxiliares a las del menú *.*.*.*
int menuJugadorOdesarrollador();
bool menuDeseaContinuarOcancelar();
// *.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

int leerInt(){
    int eleccion;
    while (!(cin >> eleccion)) {
		cout << "Solo numeros por favor..."<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
    return eleccion;
}

float leerFloat(){
    float eleccion;
    while (!(cin >> eleccion)) {
		cout << "Solo numeros por favor..."<< endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
    return eleccion;
}

char leerChar(){
    char eleccion;
    cin >> eleccion;
    return eleccion;
}

string leerString(){
    string eleccion;
    getline(cin >> ws, eleccion); //ws hace que se puedan almacenar espacios.
    return eleccion;
}

// auxiliar verInformacionVideojuego
void recorerCategorias(IDictionary * categorias) {
    cout << endl;
    cout << "---- Categorias del videojuego: ----" << endl; 
    if (categorias->getSize() == 0) {
        cout << "  Al parecer no tienes categorias por mostrar :) " << endl;
    }
    IIterator * itCategorias = categorias->getIterator();
    while (itCategorias->hasCurrent())
    {
        Categoria * cat = (Categoria *)itCategorias->getCurrent();
        cout << "  -" << cat->darTipo() << endl;
        itCategorias->next();
    }
}

// auxiliar verInformacionVideojuego
void recorrerSuscripcionesVJ(IDictionary * suscripciones, bool isDevelop){
    cout << "---- Suscripciones del videojuego: ----" << endl;
    if (suscripciones->getSize() == 0) {
        cout << "Uups ! Al parecer no tienes ninguna suscripcion para este  videojuego " << endl;
    }
    IIterator * itSuscripciones = suscripciones->getIterator();
    while (itSuscripciones->hasCurrent())
    {
        Suscripcion * suscr = (Suscripcion *)itSuscripciones->getCurrent();
        cout << "  -Preiodo:" << getEPeriodo(suscr->getPeriodo()) << endl; 
        cout << "   Precio: " << suscr->getPrecio() << endl;
        if (isDevelop) {
            // mostrar todas las suscripciones
        }
        cout << "-------------" << endl;
        itSuscripciones->next();
    }
    
}

void mostrarMenu(){
    system("cls");
    cout <<"******** Menu de Interaccion ********" << endl;
    cout << " 1 - Alta de Usuario." << endl;
    cout << " 2 - Iniciar Sesion." << endl;
    cout << " 3 - Cargar datos de prueba." << endl;
    cout << " 4 - Salir." << endl;
    cout << "*************************************" << endl;
    cout << " Ingrese una opcion: (entre 1-4)" << endl;
}

void mostrarMenuDesarrollador(){
    system("cls");
    cout <<"******** Menu de Desarrollador ********" << endl;
    cout << " 1 - Agregar Categoria." << endl;
    cout << " 2 - Publicar Videojuego." << endl;
    cout << " 3 - Eliminar Videojuego." << endl;
    cout << " 4 - Consultar Estadisticas." << endl;
    cout << " 5 - Ver informacion de videojuego." << endl;
    cout << " 6 - Modificar fecha del sistema." << endl;
    cout << " 7 - Salir." << endl;
    cout << "*************************************" << endl;
    cout << " Ingrese una opcion: (entre 1-7)" << endl;
}

void mostrarMenuJugador(){
    system("cls");
    cout <<"*********** Menu de Jugador ***********" << endl;
    cout << " 1 - Suscribirse a videojuego." << endl;
    cout << " 2 - Asignar puntaje a videojuego." << endl;
    cout << " 3 - Iniciar partida." << endl;
    cout << " 4 - Abandonar partida multijugador." << endl;
    cout << " 5 - Finalizar partida." << endl;
    cout << " 6 - Ver informacion de videojuego." << endl;
    cout << " 7 - Modificar fecha del sistema." << endl;
    cout << " 8 - Salir." << endl;
    cout << "**************************************" << endl;
    cout << " Ingrese una opcion: (entre 1-8)" << endl;
};

void cerrarSesionMenu(){
    system("cls");
    cout << "Cerrando sesion..." << endl;
    sleep(1);
    usuarioActual = "";
}

bool cerrarMenuDesarrollador = false;
bool cerrarMenuJugador = false;
void menu(){
    
    try
    {
        if (usuarioActual == ""){
            bool menuOk = menuUsuario();
            while(!menuOk){
                menu();
            }
        } 
        if (usuarioActual == "Desarrollador"){
            while(!cerrarMenuDesarrollador){
                menuDesarrollador();
            }
            cerrarMenuDesarrollador = false;
        }
        if (usuarioActual == "Jugador"){
            while(!cerrarMenuJugador){
                menuJugador();
            }
            cerrarMenuJugador = false;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    } 
}

// auxiliar asignar puntaje
void recorrerVideojuegosMenu(IDictionary * coleccVJ ) 
{
    system("cls");
    IIterator *it = coleccVJ->getIterator();
    int contador_categorias = 1;
    while (it->hasCurrent()){
        DtVideojuego *vj = (DtVideojuego *)it->getCurrent();
        cout << "Nombre: "<< vj->getNombreVideojuego() << endl;
        cout << "Descripcion: " << vj->getDescripcionVideojuego() << endl;
        cout << "-----------------------------------------" << endl;
        contador_categorias++;
        it->next();
    }
    delete it;
}

// terminado
bool menuUsuario(){
        mostrarMenu();
        int eleccion = leerInt();

        switch (eleccion){
            case 1: altaUsuarioMenu(); break;
            case 2: iniciarSesionMenu();break;
            case 3: cargarDatosDePruebaMenu(); break;
            case 4: cout << "Saliendo..."; sleep(2); exit(3); break; 
            default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo." << endl; sleep(2); break; 
        }
    return false;
}

// logica e interfaz grafica del menu de desarrollador
void menuDesarrollador(){
    mostrarMenuDesarrollador();
    int eleccion = leerInt();
    switch (eleccion){
        case 1: agregarCategoriaMenu(); break;
        case 2: publicarVideojuegoMenu();break; // TODO fixear
        case 3: eliminarVideojuegoMenu(); break; 
        case 4: consultarEstadisticasMenu(); break; // TODO implementar entre todos
        case 5: verInfoVideojuegoMenu(); break; // TODO queda pendiente que leo fixee su codigo e implementar entre los 4
        case 6: modificarFechaSistemaMenu(); break;
        case 7: cerrarSesionMenu(); cerrarMenuDesarrollador = true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
    }  
}



//Funcion auxiliar menu si o no
char menuYesOrNo(){
    char op;
    do{ 
        cout << "y/n";
        op = leerChar();
    }while (op != 'n' && op != 'N' && op != 'y' && op != 'Y');
    return op;
}
 
void menuJugador(){
    mostrarMenuJugador();
    int eleccion = leerInt();
    switch (eleccion){
        case 1: suscribirseAvideojuegoMenu(); break; // TODO
        case 2: asignarPuntajeVJMenu();break; 
        case 3: iniciarPartidaMenu(); break; // TODO
        case 4: abandonarPartidaMJMenu(); break; // TODO
        case 5: finalizarPartidaMenu(); break; // TODO
        case 6: verInformacionVideojuegoMenu(); break; 
        case 7: modificarFechaSistemaMenu(); break;
        case 8: cerrarSesionMenu(); cerrarMenuJugador = true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
    } 
}

// falta cargar más datos, a medida que se agreguen funcionalidades
void cargarDatosDePruebaMenu(){
    try
    {
        system("cls");
        DtDesarrollador * d1 = new DtDesarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
        DtDesarrollador * d2 = new DtDesarrollador("epic@mail.com", "123", "Epic Games");
        DtDesarrollador * d3 = new DtDesarrollador("mojang@mail.com", "123", "Mojang Studios");
        DtDesarrollador * d4 = new DtDesarrollador("ea@mail.com", "123", "EA Sports");
        DtJugador * j1 = new DtJugador("gamer@mail.com", "123", "gamer", "soy gamer");
        DtJugador * j2 = new DtJugador("ari@mail.com", "123", "ari", "soy ari");
        DtJugador * j3 = new DtJugador("ibai@mail.com", "123", "ibai", "soy ibai");
        DtJugador * j4 = new DtJugador("camila@mail.com", "123", "camila", "soy camila");
        s->altaUsuario(d1);
        s->altaUsuario(d2);
        s->altaUsuario(d3);
        s->altaUsuario(d4);
        s->altaUsuario(j1);
        s->altaUsuario(j2);
        s->altaUsuario(j3);
        s->altaUsuario(j4);

        s->agregarCategoria("PC", "Esta es la cat1", "PLATAFORMA");                                         // 1
        s->agregarCategoria("PS4", "Esta es la cat2", "PLATAFORMA");                                        // 2
        s->agregarCategoria("XBOXONE", "Esta es la cat3", "PLATAFORMA");                                    // 3
        s->agregarCategoria("DEPORTE", "Esta es la cat4", "GENERO");                                        // 4
        s->agregarCategoria("SUPERVIVENCIA", "Esta es la cat5", "GENERO");                                  // 5
        s->agregarCategoria("ESTRATEGIA", "Esta es la cat6", "GENERO");                                     // 6
        s->agregarCategoria("Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", "OTRO"); // 7
        s->agregarCategoria("E", "Su contenido está dirigido para todo publico", "OTRO");                   // 8
        s->agregarCategoria("ACCION", "Esta es la cat9", "GENERO");                                         // 9
        s->agregarCategoria("AVENTURA", "Esta es la cat10", "GENERO");                                      // 10
        s->agregarCategoria("SWITCH", "Esta es la cat11", "PLATAFORMA");                                    // 11
        s->agregarCategoria("XBOXX", "Esta es la cat12", "PLATAFORMA");                                     // 12
        s->agregarCategoria("PS5", "Esta es la cat13", "PLATAFORMA");                                       // 13


// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
    
//  VIDEOJUEGO 1
        ICollection * categorias1 = new List();
        ICollection * costos_suscripcion = new List();
        
        DtCategoria * cat1 = new DtCategoria(1, "PC", "Esta es la cat1", "PLATAFORMA");
        DtCategoria * cat2 = new DtCategoria(2, "PS4", "Esta es la cat2", "PLATAFORMA");
        DtCategoria * cat3 = new DtCategoria(6, "ESTRATEGIA", "Esta es la cat6", "GENERO");
        DtCategoria * cat4 = new DtCategoria(8, "E", "Su contenido está dirigido para todo publico", "OTRO");
        categorias1->add(cat1);
        categorias1->add(cat2);
        categorias1->add(cat3);
        categorias1->add(cat4);

        DtCostoSuscripcion * costo1 = new DtCostoSuscripcion(VITALICIA, 14);
        DtCostoSuscripcion * costo2 = new DtCostoSuscripcion(ANUAL, 7);
        DtCostoSuscripcion * costo3 = new DtCostoSuscripcion(MENSUAL, 1);
        DtCostoSuscripcion * costo4 = new DtCostoSuscripcion(TRIMESTRAL, 2);
        costos_suscripcion->add(costo1);
        costos_suscripcion->add(costo2);
        costos_suscripcion->add(costo3);
        costos_suscripcion->add(costo4);

        s->iniciarSesion("ironhide@mail.com", "123");
        s->agregarVideojuego("KingdomRush", "Juego 1", costos_suscripcion, categorias1);

        s->cerrarSesion();
        usuarioActual = "";
// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//  VIDEOJUEGO 2
        ICollection * categorias2 = new List();
        ICollection * costos_suscripcion2 = new List();
        
        DtCategoria * cat5 = new DtCategoria(1, "PC", "Esta es la cat1", "PLATAFORMA");
        DtCategoria * cat6 = new DtCategoria(2, "PS4", "Esta es la cat2", "PLATAFORMA");
        DtCategoria * cat7 = new DtCategoria(3, "XBOXONE", "Esta es la cat3", "PLATAFORMA");
        DtCategoria * cat8 = new DtCategoria(5, "SUPERVIVENCIA", "Esta es la cat5", "GENERO");
        DtCategoria * cat9 = new DtCategoria(7, "Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", "OTRO");
        categorias2->add(cat5);
        categorias2->add(cat6);
        categorias2->add(cat7);
        categorias2->add(cat8);
        categorias2->add(cat9);

        DtCostoSuscripcion * costo5 = new DtCostoSuscripcion(VITALICIA, 60); //5
        DtCostoSuscripcion * costo6 = new DtCostoSuscripcion(ANUAL, 30); //6
        DtCostoSuscripcion * costo7 = new DtCostoSuscripcion(MENSUAL, 3); //7
        DtCostoSuscripcion * costo8 = new DtCostoSuscripcion(TRIMESTRAL, 8); //8
        costos_suscripcion2->add(costo5);
        costos_suscripcion2->add(costo6);
        costos_suscripcion2->add(costo7);
        costos_suscripcion2->add(costo8);

        s->iniciarSesion("epic@mail.com", "123");
        s->agregarVideojuego("Fortnite", "Juego 2", costos_suscripcion2, categorias2);

        s->cerrarSesion();
        usuarioActual = "";

// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//  VIDEOJUEGO 3
        ICollection * categorias3 = new List();
        ICollection * costos_suscripcion3 = new List();
        
        DtCategoria * cat10 = new DtCategoria(1, "PC", "Esta es la cat1", "PLATAFORMA");
        DtCategoria * cat11 = new DtCategoria(5, "SUPERVIVENCIA", "Esta es la cat5", "GENERO");
        DtCategoria * cat12 = new DtCategoria(8, "E", "Su contenido está dirigido para todo publico", "OTRO");
        categorias3->add(cat10);
        categorias3->add(cat11);
        categorias3->add(cat12);

        DtCostoSuscripcion * costo9 = new DtCostoSuscripcion(VITALICIA, 40); //9
        DtCostoSuscripcion * costo10 = new DtCostoSuscripcion(ANUAL, 28); //10 
        DtCostoSuscripcion * costo11 = new DtCostoSuscripcion(MENSUAL, 2); //11
        DtCostoSuscripcion * costo12 = new DtCostoSuscripcion(TRIMESTRAL, 5); //12
        costos_suscripcion3->add(costo9);
        costos_suscripcion3->add(costo10);
        costos_suscripcion3->add(costo11);
        costos_suscripcion3->add(costo12);

        s->iniciarSesion("mojang@mail.com", "123");
        s->agregarVideojuego("Minecraft", "Juego 3", costos_suscripcion3, categorias3);

        s->cerrarSesion();
        usuarioActual = "";
        
// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//  VIDEOJUEGO 4
        ICollection * categorias4 = new List();
        ICollection * costos_suscripcion4 = new List();
        
        DtCategoria * cat13 = new DtCategoria(1, "PC", "Esta es la cat1", "PLATAFORMA");
        DtCategoria * cat14 = new DtCategoria(2, "PS4", "Esta es la cat2", "PLATAFORMA");
        DtCategoria * cat15 = new DtCategoria(3, "XBOXONE", "Esta es la cat3", "PLATAFORMA");
        DtCategoria * cat16 = new DtCategoria(5, "SUPERVIVENCIA", "Esta es la cat5", "GENERO");
        DtCategoria * cat17 = new DtCategoria(7, "Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", "OTRO");
        categorias4->add(cat13);
        categorias4->add(cat14);
        categorias4->add(cat15);
        categorias4->add(cat16);
        categorias4->add(cat17);

        DtCostoSuscripcion * costo13 = new DtCostoSuscripcion(VITALICIA, 300); //13
        DtCostoSuscripcion * costo14 = new DtCostoSuscripcion(ANUAL, 200); //14
        DtCostoSuscripcion * costo15 = new DtCostoSuscripcion(MENSUAL, 100); //15
        DtCostoSuscripcion * costo16 = new DtCostoSuscripcion(TRIMESTRAL, 150); //16
        costos_suscripcion4->add(costo13);
        costos_suscripcion4->add(costo14);
        costos_suscripcion4->add(costo15);
        costos_suscripcion4->add(costo16);

        s->iniciarSesion("ea@mail.com", "123");
        s->agregarVideojuego("FIFA 22", "Juego 4", costos_suscripcion4, categorias4);
        
        s->cerrarSesion();
        usuarioActual = "";


// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

    // ------------ Suscripcion 1 y 2 (Jugador 1) ------------
//inicio sesión jugador 1
/*
        s->iniciarSesion("gamer@mail.com", "123");

        // 01/06/22 - 9am
        int dia = 1;
        int mes = 6;
        int anio = 2022;
        int hora = 9;
        int minuto = 0;

        DtFechaHora * fechamodificada = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada);
        delete fechamodificada;
        s->confirmarSuscripcion("KingdomRush", 4, PAYPAL);       // TRIMESTRAL

        // 02/06/22 - 11am
        dia = 2;
        mes = 6;
        anio = 2022;
        hora = 11;
        minuto = 0;
        DtFechaHora * fechamodificada2 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada2);
        delete fechamodificada2;
        s->confirmarSuscripcion("Fortnite", 8, TARJETA);         // TRIMESTRAL

        // ---PUNTUACIONES J1---
        s->asignarPuntajeVideojuego(4, "KingdomRush");
        s->asignarPuntajeVideojuego(5, "Fortnite");
        // ---------------------


    // -------Partidas individuales J1-------
        // Partida 1

            // 02/06/22 - 9am INICIO
            dia = 2;
            mes = 6;
            anio = 2022;
            hora = 10;
            minuto = 0;
            DtFechaHora * fechainicio = new DtFechaHora(dia, mes, anio, hora, minuto);
            s->modificarFechaSistema(fechainicio);
            s->iniciarPartidaIndividual(true, "KingdomRush");
            delete fechainicio;

            // 02/06/22 - 10am FIN
            dia = 2;
            mes = 6;
            anio = 2022;
            hora = 10;
            minuto = 0;
            DtFechaHora * fechafin = new DtFechaHora(dia, mes, anio, hora, minuto);
            s->modificarFechaSistema(fechafin);
            s->finalizarPartida(1);
            delete fechafin;

        // ----------------------
        // Partida 2

            // 03/06/22 - 3pm INICIO
            dia = 3;
            mes = 6;
            anio = 2022;
            hora = 15;
            minuto = 0;
            DtFechaHora * fechainicio2 = new DtFechaHora(dia, mes, anio, hora, minuto);
            s->modificarFechaSistema(fechainicio2);
            s->continuarPartida(1);
            delete fechainicio;

            // 03/06/22 - 4pm FIN
            dia = 3;
            mes = 6;
            anio = 2022;
            hora = 16;
            minuto = 0;
            DtFechaHora * fechafin2 = new DtFechaHora(dia, mes, anio, hora, minuto);
            s->modificarFechaSistema(fechafin2);
            s->finalizarPartida(1);
            delete fechafin;
        // ----------------------
    // ----------------------------------


    // -------Partidas multijugador J1-------
        // PartidaMJ 1
        ICollection * jugadores = new List();
        string nickJ2 = j2->getNickname();
        char * charNameJ2 = const_cast<char *>(nickJ2.c_str());
        String * nomJ2 = new String(charNameJ2);

        string nickJ3 = j3->getNickname();
        char *charNameVj = const_cast<char *>(nickJ3.c_str());
        String * nomJ3 = new String(charNameVj);
        jugadores->add(nomJ2);
        jugadores->add(nomJ3);

        // 05/06/22 - 5pm INICIO
        dia = 5;
        mes = 6;
        anio = 2022;
        hora = 17;
        minuto = 0;
        DtFechaHora * fechainicioMJ1 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechainicioMJ1);
        s->iniciarPartidaMultijugador(jugadores, true, "Fortnite");
        delete fechainicioMJ1;

        // 05/06/22 - 7pm FIN
        dia = 5;
        mes = 6;
        anio = 2022;
        hora = 19;
        minuto = 0;
        DtFechaHora * fechafinMJ1 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechafinMJ1);
        s->finalizarPartida(2);
        delete fechafinMJ1;

        // PartidaMJ 2

        // 06/06/22 - 5pm INICIO
        dia = 6;
        mes = 6;
        anio = 2022;
        hora = 17;
        minuto = 0;
        DtFechaHora * fechainicioMJ2 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechainicioMJ2);
        s->iniciarPartidaMultijugador(jugadores, true, "Fortnite");
        delete fechainicioMJ2;

        // 06/06/22 - 7pm FIN
        dia = 6;
        mes = 6;
        anio = 2022;
        hora = 19;
        minuto = 0;
        DtFechaHora * fechafinMJ2 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechafinMJ2);
        s->finalizarPartida(2);
        delete fechafinMJ2;
        delete jugadores;
    // --------------------------------------

    s->cerrarSesion();
    usuarioActual = "";
// cierre de sesión Jugador 1

        // setteo de nuevo la fecha del sistema a la actual para volverlo a la normalidad.
        time_t t = time(0);
        tm *now = localtime(&t);
        dia = now->tm_mday;
        mes = 1 + now->tm_mon;
        anio = 1900 + now->tm_year;
        hora = now->tm_hour;
        minuto = now->tm_min;
        DtFechaHora *ahora = new DtFechaHora(dia, mes, anio, hora, minuto);
        
        s->modificarFechaSistema(ahora);

    // -----------------------------------------------------------


    // ------------ Suscripcion 3 y 4 (Jugador 2) ------------
        s->iniciarSesion("ari@mail.com", "123");


        // 04/06/22 - 9am
        dia = 4;
        mes = 6;
        anio = 2022;
        hora = 9;
        minuto = 0;
        DtFechaHora * fechamodificada3 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada3);
        delete fechamodificada3;
        s->confirmarSuscripcion("Fortnite", 7, PAYPAL);          // MENSUAL


        // 11/06/22 - 9am
        dia = 11;
        mes = 6;
        anio = 2022;
        hora = 9;
        minuto = 0;
        DtFechaHora * fechamodificada4 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada4);
        delete fechamodificada4;
        s->confirmarSuscripcion("Minecraft", 10, TARJETA);        // ANUAL

        // ---PUNTUACIONES J2---
        s->asignarPuntajeVideojuego(5, "Fortnite");
        s->asignarPuntajeVideojuego(3, "Minecraft");
        // ---------------------

    // -------Partidas individuales J2-------
        // Partida 1 (La unica que tiene)

        // 12/06/22 - 4pm INICIO, NO TIENE FIN
        dia = 12;
        mes = 6;
        anio = 2022;
        hora = 16;
        minuto = 0;
        DtFechaHora * fechainicio3 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechainicio3);
        s->iniciarPartidaIndividual(true, "Minecraft");
        delete fechainicio3;
    // --------------------------------------

    // -------Partidas multijugador J2-------
        // PartidaMJ 3
        ICollection * jugadores2 = new List();

        jugadores2->add(nomJ3);

        // 05/06/22 - 5pm INICIO
        dia = 5;
        mes = 6;
        anio = 2022;
        hora = 17;
        minuto = 0;
        DtFechaHora * fechainicioMJ3 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechainicioMJ2);
        s->iniciarPartidaMultijugador(jugadores2, false, "Minecraft");
        delete fechainicioMJ2;
        delete jugadores2;

    // --------------------------------------


    // -------Abandonar Partida multijugador Jugador 2-------

        // 05/06/22 - 6pm ABANDONA A ESA HORA
        dia = 5;
        mes = 6;
        anio = 2022;
        hora = 18;
        minuto = 0;
        DtFechaHora * fechaAbandonar1 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechaAbandonar1);
        s->abandonarPartida(4);
        delete fechaAbandonar1;

        // 06/06/22 - 5:30pm ABANDONA A ESA HORA
        dia = 6;
        mes = 6;
        anio = 2022;
        hora = 17;
        minuto = 30;
        DtFechaHora * fechaAbandonar2 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechaAbandonar2);
        s->abandonarPartida(5);
        delete fechaAbandonar2;

    // ------------------------------------------------------

        // cierre de sesión Jugador 2
        s->cerrarSesion();
        usuarioActual = "";

        // setteo de nuevo la fecha del sistema a la actual para volverlo a la normalidad.
        s->modificarFechaSistema(ahora);
    // -----------------------------------------------------------


    // ------------ Suscripcion 5 y 6 (Jugador 3) ------------
        s->iniciarSesion("ibai@mail.com", "123");

        // 03/06/22 - 7am
        dia = 3;
        mes = 6;
        anio = 2022;
        hora = 7;
        minuto = 0;
        DtFechaHora * fechamodificada5 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada5);
        delete fechamodificada5;
        s->confirmarSuscripcion("Fortnite", 7, TARJETA);         // MENSUAL


        // 22/12/20 - 3pm
        dia = 22;
        mes = 12;
        anio = 2020;
        hora = 15;
        minuto = 0;
        DtFechaHora * fechamodificada6 = new DtFechaHora(dia, mes, anio, hora, minuto);
        s->modificarFechaSistema(fechamodificada6);
        delete fechamodificada6;
        s->confirmarSuscripcion("Minecraft", 9, TARJETA);        // VITALICIA

        // cierre de sesión Jugador 3
        s->cerrarSesion();
        usuarioActual = "";

        // setteo de nuevo la fecha del sistema a la actual para volverlo a la normalidad.
        s->modificarFechaSistema(ahora);
    // -----------------------------------------------------------
*/
        cout << "Datos de prueba cargados." << endl;
        sleep(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //cout << "ERROR: Ya se han cargado los datos de prueba." << endl;
        sleep(3);
    }   
}


bool menuDeseaContinuarOcancelar(){
    do{
        system("cls");
        cout << "Desea intentarlo nuevamente, o cancelar? " << endl;
        cout << "1 - Intentar de nuevo" << endl;
        cout << "2 - Cancelar" << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return true;  break;
        case 2: return false; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (true);
    return false;
}

void altaUsuarioMenu(){
    bool ok = false; // cuando el login se lleva a cabo.
    int tipoUsuario;

    while(!ok){
        try
        {
            system("cls");
            cout << "Ingrese el EMAIL para el usuario: "<< endl;
            string email = leerString();

            system("cls");
            cout << "Ingrese PASSWORD para el usuario: "<< endl;
            string pass = leerString();
            
            int tipoUsuario = menuJugadorOdesarrollador();
            if (tipoUsuario == 1){ // eligió Jugador           
                //bucle hasta que ponga un nickname que no exista o se quiera salir
                //confirmar alta
                try{
                    system("cls");
                    string nickname;
                    cout << "Ingrese un NICKNAME para el usuario: "<< endl;
                    nickname = leerString();

                    system("cls");
                    string descripcion;
                    cout << "Ingrese una DESCRIPCION para el usuario: "<< endl;
                    descripcion = leerString();
                    DtJugador * jugador = new DtJugador(email, pass, nickname, descripcion);
                    s->altaUsuario(jugador);
                    system("cls");
                    cout << "EXITO: Jugador ingresado al sistema!"<< endl;
                    sleep(2);
                    ok = true; // si no salta excepcion, es que no existe el nickname, llega y se corta el while    
                                
                }
                catch(const std::exception& e)
                {
                    system("cls");
                    std::cerr << e.what() << '\n';
                    sleep(2);
                    bool eleccion = menuDeseaContinuarOcancelar();
                        if (eleccion == false)
                            return;
                }
            }else if(tipoUsuario == 2){ // si eligió Desarrollador
                try
                {
                    system("cls");
                    string nomEmp;
                    cout << "Ingrese el NOMBRE DE LA EMPRESA en la que trabaja: "<< endl;
                    DtDesarrollador * desarrollador = new DtDesarrollador(email, pass, nomEmp);
                    nomEmp = leerString();
                    s->altaUsuario(desarrollador);
                    system("cls");
                    cout << "EXITO: Desarrollador ingresado al sistema!"<< endl;
                    sleep(2);
                    ok = true;
                }
                catch(const std::exception& e)
                {
                    system("cls");
                    std::cerr << e.what() << '\n';
                    sleep(2);
                }
            }
        }
        catch(const std::exception& e) // cierre try abajo de while(!error && menu){
        {
            std::cerr << e.what() << '\n';
            sleep(2);
        }
    }
}

int menuJugadorOdesarrollador(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el tipo de usuario que desea registrar: "<<endl;
        cout << "1 - Jugador." << endl;
        cout << "2 - Desarrollador." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return 1; opcionValida = true; break;
        case 2: return 2; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo." << endl; sleep(2); break;
        }
    } while (opcionValida == false);
    return -1111;
}

void iniciarSesionMenu(){
    string email;
    string password;
    bool ok = false;
    while (!ok){
        try{
            system("cls");
            cout << "Ingrese EMAIL para el inicio de sesion: "<< endl;
            email = leerString();

            system("cls");
            cout << "Ingrese PASSWORD para el inicio de sesion: "<< endl;
            password = leerString();

            system("cls");
            s->iniciarSesion(email, password);
            usuarioActual = s->getTipoLoggUser();
            ok = true;
            sleep(2);
        }catch(const std::exception& e){
            system("cls");
            std::cerr << e.what() << '\n';
            sleep(2);
            bool eleccion = menuDeseaContinuarOcancelar();
            if (eleccion == false){
                usuarioActual = "";
                return;
            }
        }
    }
}


// *-*-*-*-*-* HELPERS PARA AGREGARCATEGORIA *-*-*-*-*-* 
int inputTipoCategoria(){
    bool opcionValida = false;
    do{
        //system("cls");
        cout << "Seleccione el TIPO de CATEGORIA que desea registrar: "<<endl;
        cout << "1 - Plataforma." << endl;
        cout << "2 - Genero." << endl;
        cout << "3 - Otro." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return 1; opcionValida = true; break;
        case 2: return 2; opcionValida = true; break;
        case 3: return 3; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo." << endl; sleep(2); break;
        }
    } while (opcionValida == false);
    return -1111;
}

string inputTipoPlataforma(){
    bool opcionValida = false;
    do{
        //system("cls");
        cout << "Seleccione el TIPO de CATEGORIA que desea registrar: "<<endl;
        cout << "1 - XBOX ONE" << endl;
        cout << "2 - XBOX X" << endl;
        cout << "3 - PS5" << endl;
        cout << "4 - PC" << endl;
        cout << "5 - SWITCH" << endl;
        cout << "6 - PS4" << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return "XBOXONE"; opcionValida = true; break;
        case 2: return "XBOXX"; opcionValida = true; break;
        case 3: return "PS5"; opcionValida = true; break;
        case 4: return "PC"; opcionValida = true; break;
        case 5: return "SWITCH"; opcionValida = true; break;
        case 6: return "PS4"; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

string inputTipoGenero(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el TIPO de CATEGORIA que desea registrar: "<<endl;
        cout << "1 - ACCION." << endl;
        cout << "2 - AVENTURA." << endl;
        cout << "3 - ESTRATEGIA." << endl;
        cout << "4 - DEPORTE." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return "ACCION"; opcionValida = true; break;
        case 2: return "AVENTURA"; opcionValida = true; break;
        case 3: return "ESTRATEGIA"; opcionValida = true; break;
        case 4: return "DEPORTE"; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

void recorrerCategoriasMenu(ICollection * colecc ) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    int contador_categorias = 1;
    while (it->hasCurrent()){
        DtCategoria *cat = (DtCategoria *)it->getCurrent();
        cout << "Categoria " << contador_categorias << ": " << endl;
        cout << "Nombre: "<< cat->getNombre() << endl;
        cout << "Descripcion: " << cat->getDescripcion() << endl;
        cout << "Tipo: " << cat->getTipo() << endl;
        cout << "-----------------------------------------" << endl;
        contador_categorias++;
        it->next();
    }
    delete it;
}
// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


// funcional, queda pendiente de testear.
// Desarrollador
void agregarCategoriaMenu(){
    cout << "---- Categorias ya registradas: ----" << endl;
    ICollection * cats = s->listarCategorias();
    recorrerCategoriasMenu(cats);

    string nombre;
    string descripcion;
    string tipo;

    int tipoCategoria = inputTipoCategoria();

    system("cls");
    cout << "Ingrese el NOMBRE para la CATEGORIA a agregar: "<< endl;
    nombre = leerString();
    if (tipoCategoria == 1){
        tipo = "PLATAFORMA";   
    }else if (tipoCategoria == 2){
        tipo = "GENERO";
    }else if (tipoCategoria == 3){
        tipo = "OTRO";
    }

    system("cls");
    cout << "Ingrese la DESCRIPCION para la CATEGORIA a agregar: "<< endl;
    descripcion = leerString();
    system("cls");

    s->agregarCategoria(nombre, descripcion, tipo);
    cout << "Categoria registrada correctamente !";
    sleep(2);
    //s->agregarCategoria(); recibe un icollectible
}

// TODO: pedir fecha con formato y parsear (LEO) xd
void modificarFechaSistemaMenu(){
    try
    {
        DtFechaHora * fechahoraActual = s->getFechaSistema();
        system("cls");
        cout << "Fecha actual: " << fechahoraActual->getDay() << "/" << fechahoraActual->getMonth() << "/" << fechahoraActual->getYear() << " " << fechahoraActual->getHour() << ":" << fechahoraActual->getMinute() << endl;
        bool ok = false;
        while (!ok){
            int dia;
            int mes;
            int anio;
            int hora;
            int minuto;
            
            cout << "Ingrese DIA: "<< endl;
            dia = leerInt();

            system("cls");
            cout << "Ingrese MES: "<< endl;
            mes = leerInt();

            system("cls");
            cout << "Ingrese ANIO: "<< endl;
            anio = leerInt();
            system("cls");

            system("cls");
            cout << "Ingrese HORA: "<< endl;
            hora = leerInt();

            system("cls");
            cout << "Ingrese MINUTOS: "<< endl;
            minuto = leerInt();

            DtFechaHora * fechamodificada = new DtFechaHora(dia, mes, anio, hora, minuto);
            s->modificarFechaSistema(fechamodificada);
            cout << "EXITO: Fecha modificada.";
            ok = true;
            sleep(2);
        }
    }
    catch(const std::exception& e)
    {
        system("cls");
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

// auxiliar publicarVideojuego
void recorrerCategoriasID(ICollection * colecc ) 
{
    //system("cls");
    IIterator *it = colecc->getIterator();
    while (it->hasCurrent()){
        DtCategoria *cat = (DtCategoria *)it->getCurrent();
        cout << "ID: " << cat->getId() << ": " << endl;
        cout << "Nombre: "<< cat->getNombre() << endl;
        cout << "Descripcion: " << cat->getDescripcion() << endl;
        cout << "Tipo: " << cat->getTipo() << endl;
        cout << "-----------------------------------------" << endl;
        it->next();
    }
    delete it;
}

bool menuDeseaContinuarAgregando(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea continuar agregando categorias? " << endl;
        cout << "1 - Si" << endl;
        cout << "2 - No" << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
    return false;
}

// SIN TERMINAR, FALTA AGREGAR EL ID A DTCATEGORIA
void publicarVideojuegoMenu(){
    try
    {
        system("cls");
        cout << "Ingrese el NOMBRE para el videojuego: "<< endl;
        string nombre = leerString();

        system("cls");
        cout << "Ingrese DESCRIPCION para el videojuego: "<< endl;
        string descripcion = leerString();

        system("cls");
        cout << "Ingrese COSTO de suscripcion MENUSAL para el videojuego: "<< endl;
        float mensual = leerFloat();

        system("cls");
        cout << "Ingrese COSTO de suscripcion TRIMESTRAL para el videojuego: "<< endl;
        float trimestral = leerFloat();

        system("cls");
        cout << "Ingrese COSTO de suscripcion ANUAL para el videojuego: "<< endl;
        float anual = leerFloat();
        
        system("cls");
        cout << "Ingrese COSTO de suscripcion VITALICIA para el videojuego: "<< endl;
        float vitalicia = leerFloat();

        ICollection * categorias_videojuego = new List();
        bool termino = false;
        do{
            system("cls");
            // PERO TIENE QUE SER UN DICCIONARIO PARA PODER FILTRARLO
            ICollection * cats = s->listarCategorias(); // me traigo una copia (LISTA DE DTS) de las categorias registradas
            recorrerCategoriasID(cats); // muestro todas las categorias registradas
            cout << "---- Seleccione una Categoria: ----" << endl;

            int eleccionIDCategoria;
            int correct_choice = false;
            ICollectible * catAgregar;
            do{
                correct_choice = false;
                eleccionIDCategoria = leerInt();
                 IIterator * it = cats->getIterator();
                 DtCategoria * current;
                 while (it->hasCurrent()){
                    current = (DtCategoria*)it->getCurrent();
                    if(current->getId() == eleccionIDCategoria){
                        catAgregar = new DtCategoria( eleccionIDCategoria, current->getNombre(), current->getDescripcion(), current->getTipo());
                        correct_choice = true;
                        break;
                    }
                    it->next();
                }
                delete it;
                if(!correct_choice){
                    cout << endl << "Opcion invalida .El id ingresado no corresponde a ninguna categoria." << endl;
                    cout << "Ingreselo nuevamente: ";
                }
            }while (!correct_choice);
      
            
            categorias_videojuego->add(catAgregar);

            bool isFinish = !menuDeseaContinuarAgregando();
            if (isFinish == true) {
                IIterator * itCategoriasAgregadas = categorias_videojuego->getIterator();
                bool hasCategoriaGenero = false;
                bool hasCategoriaPlataforma = false;

                while (itCategoriasAgregadas->hasCurrent())
                {
                    DtCategoria * categ = (DtCategoria *)itCategoriasAgregadas->getCurrent();
                    if (categ->getTipo() == "GENERO") {
                        hasCategoriaGenero = true;
                    }
                    if (categ->getTipo() == "PLATAFORMA") {
                        hasCategoriaPlataforma = true;
                    }
                    if (hasCategoriaPlataforma && hasCategoriaGenero) {
                        break;
                    }
                    itCategoriasAgregadas->next();
                }
                delete itCategoriasAgregadas;

                if (! hasCategoriaGenero || !hasCategoriaPlataforma) {
                    system("cls");
                    cout << "El videojuego tiene que tener al menos una categoria de GENERO y una de PLATAFORMA" << endl;
                    sleep(2);
                }else {
                    termino = true;
                }

            }

        }while (!termino);

        ICollection * costos_suscr = new List();

        ICollectible * costoM = new DtCostoSuscripcion(MENSUAL, mensual);
        ICollectible * costoT = new DtCostoSuscripcion(TRIMESTRAL, trimestral);
        ICollectible * costoA = new DtCostoSuscripcion(ANUAL, anual);
        ICollectible * costoV = new DtCostoSuscripcion(VITALICIA, vitalicia);

        costos_suscr->add(costoM);
        costos_suscr->add(costoT);
        costos_suscr->add(costoA);
        costos_suscr->add(costoV);


        s->agregarVideojuego(nombre, descripcion, costos_suscr, categorias_videojuego);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void eliminarVideojuegoMenu(){
    try
    {
        system("cls");
        cout << "Ingrese el ID del videojuego que desea eliminar: "<< endl;
        string id = leerString();
        s->eliminarVideoJuego(id);
        cout << "EXITO: Videojuego eliminado.";
        sleep(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

// TODO
void verInfoVideojuegoMenu(){
    system("cls");
    cout << "---- Videojuegos ya registrados: ----" << endl;
    IDictionary * vj = s->listarVJ();
    recorrerVideojuegosMenu(vj);

    cout << "Ingrese el NOMBRE del VIDEOJUEGO de la lista: "<< endl;
    string nombrevj = leerString();

    char *charNameVj = const_cast<char *>(nombrevj.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    DtVideojuego * res = (DtVideojuego *)vj->find(vjKey);

    if (res == NULL) {
        cout << "El videojuego que ingreso no existe";
        sleep(2);
        return;
    }

    system("cls");
    cout << "------------------- INFORMACION DE VIDEOJUEGO  ------------------------" << endl;
    cout << "Nombre: " << res->getNombreVideojuego() << endl;
    cout << "Descripcion: " <<  res->getDescripcionVideojuego() << endl;
    cout << "Empresa del desarrollador : " <<  res->getEmpresaDesarrollador() << endl;
    cout << "Suma total de horas jugadas en este juego: " << s->calcularSumaTotalHorasAJuego(res->getNombreVideojuego()) << endl;

    recorerCategorias(res->getCategorias());
    recorrerSuscripcionesVJ(res->getSuscripciones(), true);

    system("PAUSE");
}


// TODO es re larga xd
void suscribirseAvideojuegoMenu(){
   ICollection * videojuegos_info = s->listarSuscripcionesPorVideojuego();
   IIterator * it = videojuegos_info->getIterator();
   DtSuscripcion * current;
   IIterator * it_susByVj;
   DtInfoSuscripcion * current_sus; 

   while (it->hasCurrent())
   {   

       current = (DtSuscripcion*)it->getCurrent();
       cout << "Videojuego: " << current->getNombreVideojuego() << endl;
       it_susByVj = current->getSuscripcion()->getIterator();
       while (it_susByVj->hasCurrent()){
           current_sus = (DtInfoSuscripcion*)it_susByVj->getCurrent();
           cout << getEPeriodo(current_sus->getPeriodo()) << ": " << current_sus->getPrecio() <<  "$" << endl;
           it_susByVj->next();
       }
       cout << "----------------------------------------------";
       delete it_susByVj;
       it->next();
   }
   delete it;

   cout << endl << "INGRESA EL NOMBRE DEL VIDEOJUEGO QUE DESEAS SUSCRIBIRTE :  ";
   string choiceName;
   bool correctChoice = false;

   do{
     choiceName = leerString();
     it = videojuegos_info->getIterator();
     while (it->hasCurrent())
     {
          current = (DtSuscripcion*)it->getCurrent();
          if(choiceName == current->getNombreVideojuego()){
            correctChoice = true;
            break;
          }
          it->next();
     }
     if(!correctChoice){
        cout  << endl << "El videojuego con el nombre  " << choiceName << " no se encuentra en la lista.Intentalo de nuevo: "; 
     }
     
   }while(!correctChoice); 

   cin.clear();
   it_susByVj = current->getSuscripcion()->getIterator();

   InfoSuscripcion info_sus[4];
   int cont = 0;
   while (it_susByVj->hasCurrent())
   {
           
           current_sus = (DtInfoSuscripcion*)it_susByVj->getCurrent();
           info_sus[cont].id = current_sus->getId();
           info_sus[cont].periodo = current_sus->getPeriodo();
           info_sus[cont].suscrito = current_sus->getSuscrito();
           cont ++;

           cout << "ID: " << current_sus->getId() << " " <<  getEPeriodo(current_sus->getPeriodo()) << ": " << current_sus->getPrecio() <<  "$" << endl;
           it_susByVj->next();
   }

   cout << "Escoge ahora la suscripcion para ese videojuego escribiendo su id:";
   int opcion;
   bool correct_choice = false;

   while(!correct_choice){
     opcion = leerInt();
     it_susByVj = current->getSuscripcion()->getIterator();
     while (it_susByVj->hasCurrent())
     {
        current_sus = (DtInfoSuscripcion*)it_susByVj->getCurrent();
        if(current_sus->getId() == opcion){
            correct_choice = true;
            break;
        }
        it_susByVj->next();
     }
     if(!correct_choice){
        cout << "ID incorrecto vuelve a intentarlo:";
     }
     
   } 

   bool esVitalicio = false;
   for(int i = 0 ;  i < 4; i ++){
    if(info_sus[i].periodo == VITALICIA && info_sus[i].suscrito){
        esVitalicio = true;
        break;
    }
   }
   if(esVitalicio){
     cout << "YA TIENES UNA SUSCRIPCION VITALICIA PARA ESTE VIDEOJUEGO.." << endl;
     cout << "rediriendo al menu..";
     sleep(3);
     return;
   }

    bool tieneTemporal = false;
    int idTemporal = 0;
    EPeriodo periodo;
    for(int i = 0 ;  i < 4; i ++){
    if(info_sus[i].periodo != VITALICIA && info_sus[i].suscrito){
        tieneTemporal = true;
        idTemporal = info_sus[i].id;
        periodo = info_sus[i].periodo;
        break;
    }
    }

    if(tieneTemporal){
        cout << "Ya tienes una suscripcion temporal de este videojuego de tipo : " << getEPeriodo(periodo) << endl;;
        DtContratacion * contratacion = s->getContratacion(choiceName);
         cout << "--------CONTRATACION--------" << endl;
        cout << "TIPO PAGO: " << contratacion->getTipoPago() << endl;
         DtFechaHora * fecha = contratacion->getFechaHora();
        DtFechaHora * fechaV = contratacion->getFechaVencimiento() ;
        cout << "FECHA CREACION: " << fecha->getDay() << "/" << fecha->getMonth() << "/" << fecha->getYear() << endl;
        cout << "FECHA VENCIMIENTO: " << fechaV->getDay() << "/" << fechaV->getMonth() << "/" << fechaV->getYear() << endl;
        cout << "MONTO PAGADO : " << contratacion->getMonto() << "$" << endl;
        cout << "Deseas cancelarla? " << endl;
        char res = menuYesOrNo();
        if(res == 'n' || res == 'N'){
            return;
        }
        s->cancelarSuscripcion(contratacion->getId());
        cout << "Contratacion previa cancelada!!";
    }
   
   cin.clear();  

   int opcionPago = 0;
   ETipoPago metodoPago;
   
   while (opcionPago != 1 && opcionPago != 2){
            cout << "Escoge un metodo de pago" << endl;
            cout << "1-TARJETA" << endl;
            cout << "2-PAYPAL";
            opcionPago = leerInt();
            switch (opcionPago){
                case 1: 
                    opcionPago = 1;
                    metodoPago = TARJETA;
                    break;
                case 2:
                    opcionPago = 2;
                    metodoPago = PAYPAL;
                    break;
                default:
                    cout << endl  << "Opcion incorrecta vuelve a intentarlo" << endl; 
                    break;
            }
   }
   try{
    s->confirmarSuscripcion(choiceName,opcion,metodoPago);
    cin.clear();
    cout << "te has suscrito .. ";
    sleep(2);
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

// auxiliar verInformacionVideojuego
void recorrerSuscripcionesVJ(DtVideojuego * vj){
    cout << "---- Suscripciones del videojuego: ----";
    //IIterator *it = vj->suscripciones->getIterator(); //revisar
        /*
    while (it->hasCurrent()){
        DtSuscripcion *suscripcion = (DtSuscripcion *)it->getCurrent();
        cout << "ID: " << suscripcion->getID() << endl;
        cout << "Fecha de inicio: " << suscripcion->getFechaInicio() << endl;
        cout << "Fecha de fin: " << suscripcion->getFechaFin() << endl;
        cout << "-----------------------------------------" << endl;
        it->next();
    }
    delete it;
        */
}


// pseudocodigo, fixear
void verInformacionVideojuegoMenu(){

    try
    {
    cout << "---- Videojuegos ya registrados: ----" << endl;
    cout << "llego 1" << endl;
    IDictionary * vj = s->listarVJ();
    recorrerVideojuegosMenu(vj);

    cout << "Ingrese el NOMBRE del VIDEOJUEGO de la lista: "<< endl;
    string nombrevj = leerString();

    char *charNameVj = const_cast<char *>(nombrevj.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    DtVideojuego * res = (DtVideojuego *)vj->find(vjKey);

    if (res == NULL) {
        cout << "El videojuego que ingreso no existe";
        sleep(2);
        return;
    } 

    system("cls"); 
    cout << "---- Informacion del VIDEOJUEGO: ----" << endl;
    cout << "Nombre: " << res->getNombreVideojuego() << endl;
    cout << "Descripcion: " << res->getDescripcionVideojuego() << endl;
    cout << "Promedio Puntuacion: " << res->getPromedioPuntuaciones() << endl;
    cout << "Cantidad Puntuaciones: " << res->getPuntuaciones()->getSize() << endl;
    cout << "Empresa del desarrollador : " <<  res->getEmpresaDesarrollador() << endl;

    recorerCategorias(res->getCategorias());
    recorrerSuscripcionesVJ(res->getSuscripciones(), false);
    
    system("PAUSE");
    //cout << "Nombre: " << recorrerSuscripcionesVJ(res) << endl;
    //cout << "Nombre: " << recorrerCategoriasVJ(res) << endl;
} catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void asignarPuntajeVJMenu(){
    try
    {
        int puntaje;
        string nombrevj;
        do {
            cout << "---- Videojuegos ya registrados: ----" << endl;
            IDictionary * vj = s->listarVJ();
            recorrerVideojuegosMenu(vj);

            cout << "Ingrese el NOMBRE del VIDEOJUEGO de la lista: "<< endl;
            nombrevj = leerString();
    
            cout << "Ingrese el PUNTAJE que desea asignar: "<< endl;
            puntaje = leerInt();   
            
            if (puntaje > 5 || puntaje < 1) {
                system("cls");
                cout << "Por favor, ingrese un valor entre 1 y 5";
                sleep(3);
            }
        } while (puntaje > 5 || puntaje < 1); 
        s->asignarPuntajeVideojuego(puntaje, nombrevj);
        system("cls");
        cout << "Puntaje asignado.";
        sleep(3);
    }  
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void recorrerVideojuegosActivosMenu(ICollection * colecc) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    int contador_categorias = 1;
    while (it->hasCurrent()){
        DtCategoria *cat = (DtCategoria *)it->getCurrent();
        cout << "Categoria " << contador_categorias << ": " << endl;
        cout << "Nombre: "<< cat->getNombre() << endl;
        cout << "Descripcion: " << cat->getDescripcion() << endl;
        cout << "Tipo: " << cat->getTipo() << endl;
        cout << "-----------------------------------------" << endl;
        contador_categorias++;
        it->next();
    }
    delete it;
}

// auxiliar iniciarPartida
bool menuIndividualOmultijugador()
{
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el tipo de partida deseado: "<<endl;
        cout << "1 - Individual." << endl;
        cout << "2 - Multijugador." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
    return false;
}

// auxiliar iniciarPartida
bool menuMultijugadorTransmitidaOno()
{
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea transmitir su partida en vivo?"<<endl;
        cout << "1 - Si." << endl;
        cout << "2 - No." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
    return false;
}

// auxiliar obtenerJugadoresIniciarPartida
void recorrerJugadoresMenu(ICollection * colecc ) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    while (it->hasCurrent())
    {
        String *nick = (String *)it->getCurrent();
        cout << "Nickname: "<< nick->getValue() << endl;
        cout << "-----------------------------------------" << endl;
        it->next();
    }
    delete it;
}

// auxiliar obtenerJugadoresIniciarPartida
bool menuMostrarSeguirAgregandoJugador()
{
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea seguir agregando jugadores a esta partida ?"<<endl;
        cout << "1 - Si." << endl;
        cout << "2 - No." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return true; opcionValida = true; break;
        case 2: return false; opcionValida = true;break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
    return false;
}

// auxiliar obtenerJugadoresIniciarPartida
bool recorrerJugadoresEnPartidaMenu(ICollection * colecc, string  nick ) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    bool res = false;
    while (it->hasCurrent())
    {
    
        String *nickJ = (String *)it->getCurrent();
        if(nickJ->getValue() == nick){
            res = true;
            break;
        }
        it->next();
    }
    delete it;
    return res;

}





// auxiliar iniciarPartida
ICollection * obtenerJugadoresIniciarPartida(string nomVJ)
{
    system("cls");
    cout << "---- Jugadores registrados, con suscripcion en ese juego: ----" << endl;
    ICollection * jugadoresSuscritos = s->listarJugadoresConSuscripcionAJuego(nomVJ);
    recorrerJugadoresMenu(jugadoresSuscritos);

    ICollection * jugadores = new List();

    bool opcion = true;
    while (opcion != false)
    {
        cout << "Ingrese el nickname del jugador que desea agregar a esta partida: " << endl;
        string nick = leerString();
        
        bool jug = recorrerJugadoresEnPartidaMenu(jugadoresSuscritos, nick);
        if(jug == true){
                char *charNick = const_cast<char *>(nick.c_str()); // paso de string a char (para poder implementar la key)
                String * nickString = new String(charNick);
                bool jugadorYaExiste = recorrerJugadoresEnPartidaMenu(jugadores, nick);
                if(jugadorYaExiste){
                    cout << "Este jugador ya es parte de esta partida." << endl;
                    sleep(2);
                }
                else{
                    char *charNickk = const_cast<char *>(nick.c_str()); // paso de string a char (para poder implementar la key)
                    jugadores->add(nickString);
                    system("cls");
                    cout << "EXITO: El jugador fue agregado a la partida." << endl;
                    sleep(2);
                }
        }
        else
        {
            cout << "El jugador no existe." << endl;
            sleep(2);
        }

        opcion = menuMostrarSeguirAgregandoJugador();
    }
    return jugadores;
}


void recorrerPartidasFinalizadas(ICollection * colecc ) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    while (it->hasCurrent()){
        DtPartida *part = (DtPartida *)it->getCurrent();
        cout << "                    ID: "<< part->getId() << endl;
        cout << "Fecha/Hora realizacion: "<< part->getFecha() << endl;
        cout << "              Duracion: "<< part->getDuracion() << endl;
        cout << "-----------------------------------------" << endl;
        it->next();
    }
    delete it;
}

// auxiliar iniciarPartida
bool menuIndividualNuevaoContinuar()
{
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Seleccione el tipo de partida deseado: "<<endl;
        cout << "1 - Partida Nueva." << endl;
        cout << "2 - Continuar Partida." << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return false; opcionValida = true; break;
        case 2: return true; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}

void iniciarPartidaMenu(){
    IIterator* sus = s->listarVideoJuegosActivos()->getIterator();
    if(sus->hasCurrent() == false) {
       cout << "No tiene suscripciones a ningun videojuego, suscribase a uno para inciar una partida" << endl;
       sleep(4);
    }
    else {
        
        cout << "---- Videojuegos a los que estas suscrito: ----" << endl;
        ICollection * vja = s->listarVideoJuegosActivos();
        //recorrerVideojuegosActivosMenu(vja);

        IIterator *it = vja->getIterator();
        while (it->hasCurrent()){
            String *cat = (String *)it->getCurrent();
            cout << "Nombre: "<< cat->getValue() << endl;
            cout << "-----------------------------------------" << endl;
            it->next();
        }
        delete it;

        cout << "Ingrese un NOMBRE del VIDEOJUEGO de la lista: "<< endl;
        string nombrevj = leerString();
        char *charNameVj = const_cast<char *>(nombrevj.c_str()); // paso de string a char (para poder implementar la key)
        String *vjKey = new String(charNameVj);
        //String * res = (String *)vja->find(vjKey);
        system("cls");

        bool individualOmultij = menuIndividualOmultijugador();
        if(individualOmultij){
            // pregunto si será o no una continuación de una anterior
            // SI LO ES, listamos en orden cronologico las partidas individuales ya finalizadas (ID, fechahora, duracion).
            // selecciona de la lista con el ID
            // confirmar o cancelar el inicio de partida.
            bool continuar = menuIndividualNuevaoContinuar();
            if (!continuar){ 
                // eligió crear nueva
                
                bool respuestaConfirmar;
                bool opcionValida = false;
                do{
                    system("cls");
                    cout << "Confirmar la creacion de la partida individual?" << endl;
                    cout << "1 - Si" << endl;
                    cout << "2 - No" << endl;

                    int eleccion;
                    eleccion = leerInt();

                    switch (eleccion)
                    {
                    case 1: respuestaConfirmar = true;opcionValida = true; break;
                    case 2: respuestaConfirmar = false; opcionValida = true;break;
                    default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
                    }
                } while (opcionValida == false);

                if(respuestaConfirmar){
                    s->iniciarPartidaIndividual(true, nombrevj);
                    cout << "EXITO: Creando partida..." << endl;
                    sleep(2);
                }
                else{
                    cout << "La partida no se creo." << endl;
                    sleep(2);
                }

            }else{ // eligió continuar

                bool correct_choice = false;
                int id;
                DtPartidaIndividual * res = NULL;
                do{
                    system("cls");
                    cout << "---- Partidas Finalizadas ---- "<< endl;
                    ICollection * parFinalizadas = s->listarHistorialPartidasFinalizadas(nombrevj);
                    recorrerPartidasFinalizadas(parFinalizadas);

                    cout << "Ingrese el ID de la partida que desea continuar: "<< endl;
                    id = leerInt();
                    cout << endl;
                    IIterator * it = parFinalizadas->getIterator();
                    while (it->hasCurrent())
                    {
                        DtPartidaIndividual * current = (DtPartidaIndividual *)it->getCurrent();
                        if(current->getId() == id){
                            correct_choice = true;
                            break;
                        }
                        it->next();
                    }
                    if(!correct_choice){
                        cout << "ERROR: No existe una partida con ese ID. " << endl;
                        sleep(2);
                        bool deseaContinuar = menuDeseaContinuarOcancelar(); // llega acá si ingresó un ID incorrecto
                        if(!deseaContinuar){
                            return;
                        }
                    }
                }while (!correct_choice);
                
                bool respuestaConfirmar;
                bool opcionValida = false;
                do{
                    system("cls");
                    cout << "Confirmar la continuacion de la partida?" << endl;
                    cout << "1 - Si" << endl;
                    cout << "2 - No" << endl;

                    int eleccion;
                    eleccion = leerInt();

                    switch (eleccion)
                    {
                    case 1: respuestaConfirmar = true;opcionValida = true; break;
                    case 2: respuestaConfirmar = false; opcionValida = true;break;
                    default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
                    }
                } while (opcionValida == false);
                if(respuestaConfirmar){
                    s->continuarPartida(id);
                    cout << "EXITO: Continuando partida..." << endl;
                    sleep(2);
                }
                else{
                    cout << "La partida no se inicio." << endl;
                    sleep(2);
                }
            }
        }else{ // eligió multijugador
            // transmitida o no
            // listamos los jugadores CON SUSCRIPCION ACTIVA que estan en el sistema
            // elige nickname de la lista para agregar a la partida y se le pregunta si desea seguir agregando
            // confirmar o cancelar el inicio de partida.
            system("cls");
            bool enVivo;
            enVivo = menuMultijugadorTransmitidaOno(); // preguntamos si quiere transmitirla en vivo o no.

            ICollection * jugadoresEnPartida = obtenerJugadoresIniciarPartida(nombrevj);

            bool respuestaConfirmar;
            bool opcionValida = false;
            do{
                system("cls");
                cout << "Confirmar el inicio de partida?" << endl;
                cout << "1 - Si" << endl;
                cout << "2 - No" << endl;

                int eleccion;
                eleccion = leerInt();

                switch (eleccion)
                {
                case 1: respuestaConfirmar = true;opcionValida = true; break;
                case 2: respuestaConfirmar = false; opcionValida = true;break;
                default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
                }
            } while (opcionValida == false);
            if(respuestaConfirmar){
                s->iniciarPartidaMultijugador(jugadoresEnPartida, enVivo, nombrevj);
                cout << "Hola";
                sleep(3);
            }
            else{
                cout << "La partida no se inició." << endl;
                sleep(2);
            }
        }
    }
}

void abandonarPartidaMJMenu(){
    cin.clear();
    IIterator * itPartida = s->listarPartidasUnido()->getIterator();
    DtPartidaMultijugador * current;


    cout << "------------PARTIDAS UNIDO -----------------" << endl;
    int cont_partidas = 0;
    if(itPartida->hasCurrent()){
        current = (DtPartidaMultijugador*)itPartida;
        cout << "ID: " << current->getId() << endl;
        cout << "Nombre Videojuego: " << current->getNombreV() << endl;
        DtFechaHora * fecha = current->getFecha();
        cout << "Fecha comienzo: " << fecha->getDay() << "/" << fecha->getMonth() <<"/" <<fecha->getYear() << "  " << fecha->getHour()<<":"<< fecha->getMinute() << endl;
        cout << "Transmitida en vivo: ";
        if(current->getTransmitidaEnVivo()){
            cout << " Si";
        }else{
            cout << "No";
        }
        cout << endl;
        cout << "Creador: " << current->getNicknameCreador() << endl;

        IIterator * itJugadores = current->getJugadoresUnidos()->getIterator();
        cout << "Jugadores unidos: ";
        String * current_jugador;
        while (itJugadores->hasCurrent())
        {
            current_jugador = (String*)itJugadores;
            cout << current_jugador->getValue() << ",";
            itJugadores->next();
        }
        delete itJugadores;
        cout << "---------------------------------------------" << endl;
        cont_partidas++;
        itPartida->next();

    }
    if(cont_partidas == 0){
        cout << "Lo sentimos no estas unido a ninguna partida" << endl;
        cout << "redirigiendo al menu..";
        sleep(3);
        return;
    }
    delete itPartida;
    

    bool correct_choice = false;
    char salir = 'n';
    int inputId;
    bool isOwner;
    do{
        cout << "Escribe el id de la partida multijugador que deseas abandonar: ";
        inputId = leerInt();
        cout << endl;
        itPartida = s->listarPartidasUnido()->getIterator();
        while (itPartida->hasCurrent())
        {
            current = (DtPartidaMultijugador*)itPartida->getCurrent();
            if(current->getId() == inputId){
                correct_choice = true;
                isOwner = current->isUserOwner();
                break;
            }
            itPartida->next();
        }
        if(!correct_choice){
            cout << "La id ingresada no corresponde a ninguna partida " << endl;
            cout << "Deseas salir? y/n";
            salir = leerChar();
        }
        
    }while (!correct_choice && (salir == 'n' || salir == 'N'));

    if(!correct_choice){
        return;
    }

    if(!isOwner){
        cout << "abandonando partida..";
        sleep(3);
        try{
            s->abandonarPartida(inputId);
        }catch(exception& e){
            cout << e.what();
        }
    }else{
        cout << "Eres el creador de esta partida por lo tanto al irte la partida se finalizara.." << endl;
        cout << "Finalizando .." << endl;
        sleep(3);
        try{
            s->finalizarPartida(inputId);
        }catch(exception& e){
            cout << e.what();
        }
        return;
    }

}


void finalizarPartidaMenu() {
    try
    {
    IDictionary* P = s->listarPartidasActivas();
    IIterator* I = P->getIterator();
    
    int cont = 0;
    cout << "Listado de partidas activas: " << endl;
    while (I->hasCurrent()) {
        DtPartida* info =(DtPartida*) I->getCurrent();
        cout << endl;
        cout << "ID: " << info->getId() << endl;
        cout << "Fecha de Inicio: " <<  info->getFecha()->getDay() << "/" << info->getFecha()->getMonth() << "/" << info->getFecha()->getYear() << endl;
        cout << "Videojuego: " << info->getJuego()->getNombreVideojuego() << endl;
        if (info->getTipo() == "DtPartidaIndividual") {
            DtPartidaIndividual * infoIndividual = (DtPartidaIndividual *)info;
            cout << "Continuacion de partida anterior: ";
            if (infoIndividual->getContinuar() == true) {
                cout << "Si" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            DtPartidaMultijugador * infoIndividual = (DtPartidaMultijugador *)info;
            cout << "Transmitiada en vivo: ";
            if (infoIndividual->getTransmitidaEnVivo() == true) {
                cout << "Si" << endl;
            }
            else {
                cout << "No" << endl;
            }
            IIterator* J = infoIndividual->getJugadoresUnidos()->getIterator();
            cout << endl;
            cout << "Listado de jugadores unidos a la partida: ";
            while (J->hasCurrent()) {
                String* jugadorName =(String*) J->getCurrent(); 
                cout << "-" << jugadorName->getValue();
                J->next();
            }
        }
        I->next();
        cont ++;
        }
        
        if(cont == 0){
            cout << endl << "No tienes partida inicada" << endl;
            cout << "Redirigiendo al menu..";
            sleep(3);
            return;
        }
        cout << endl;
        DtPartida * existe;
        bool opcionCorrecta = false;
        int Id;
        do {
            cout << "Ingrese el Id de la partida que desea finalizar" << endl;
            Id = leerInt();
            Integer * Pkey = new Integer(Id);
            cout << "busco : " << Pkey->getValue() << endl;
            DtPartida * existe = (DtPartida *)P->find(Pkey);
            if (existe == NULL) {
                bool deseaContinuar = menuDeseaContinuarOcancelar();
                if (!deseaContinuar) {
                    return ;
                }
                system("cls"); 
                cout << "Id de partida incorrecto, por favor intente nuevamente" << endl; 
                sleep(2); 
            } else {
                opcionCorrecta = true;
            }
        } while (!opcionCorrecta);
        s->finalizarPartida(Id);
        system("cls"); 
        cout << "Partida finalizada correctamente !";
        sleep(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(3);
    }
    
}

int inputMenuTipoEstadistica(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "**** Seleccione el tipo de estadistica que desea consultar: ****"<<endl;
        cout << "1 - Partida mas Larga " << endl;
        cout << "2 - Jugador con mas contrataciones" << endl;
        cout << "3 - Juegos mejores puntuados" << endl;
        cout << "****************************************************************" << endl;
        cout << " Ingrese una opcion: (entre 1-3)" << endl;

        int eleccion;
        eleccion = leerInt();

        switch (eleccion)
        {
        case 1: return 1; opcionValida = true; break;
        case 2: return 2; opcionValida = true; break;
        case 3: return 3; opcionValida = true; break;
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
        }
    } while (opcionValida == false);
}


void consultarEstadisticasMenu(){
    try
    {
    int eleccion = inputMenuTipoEstadistica();

    if (eleccion == 1) {
        system("cls");
        Partida * partidaMasLarga = s->partidaMasLarga();

        if (partidaMasLarga == NULL) {
            cout << "Uups ! al parecer no tenemos partidas para procesar la informacion !" << endl;
            sleep(2);
        } else {
            cout << "La id de la partida es " << partidaMasLarga->getId() << endl;
            cout << "La duracion es " << partidaMasLarga->getDuracion() << " Minutos" << endl;
            cout << "La partida fue iniciada el " <<  partidaMasLarga->getFecha()->getDay() << "/" << partidaMasLarga->getFecha()->getMonth() << "/" << partidaMasLarga->getFecha()->getYear() << endl;
            cout << "El jugador " << partidaMasLarga->getCreador()->getNickname() << " inicio esta partida" << endl;
            sleep(4);
        }
    }
    if (eleccion == 2) {
        system("cls");
          DtJugador * jugadorConMasContrataciones = s->jugadorConMasContrataciones();

          if (jugadorConMasContrataciones == NULL) {
            cout << "Uups ! al parecer no tenemos partidas para procesar la informacion !" << endl;
          } else {
            cout << "***** Jugador con mas Contrataciones: ******" << endl;
            cout << "Nickname: " << jugadorConMasContrataciones->getNickname() << endl;
            cout << "Descripcion: " << jugadorConMasContrataciones->getDescripcion() << endl;
            cout << "Email: " << jugadorConMasContrataciones->getEmail() << endl;
            cout << "Contrataciones: " << jugadorConMasContrataciones->getSizeContrataciones() << endl;
            sleep(4);
          }
          
      }
    if (eleccion == 3) {
       system("cls");

       cout << "Ingrese un Top (1-5)" << endl;
       int range = leerInt();

       system("cls");
       cout << "***** Los juegos mas puntuados son: *****" << endl;
       ICollection * masPuntuados = s->juegosMejoresPuntuados(range);
       IIterator * it = masPuntuados->getIterator();
       while (it->hasCurrent())
       {
         DtVideojuego * dtVj = (DtVideojuego *)it->getCurrent();
         cout << "------------- " << dtVj->getNombreVideojuego() << " -------------" << endl;
         cout << "Promedio Puntuacion:" << dtVj->getPromedioPuntuaciones() << endl;
         cout << "Cantidad Puntuaciones:" << dtVj->getPuntuaciones()->getSize() << endl;
         cout << "-----------------------------------------------------------------" << endl;
         it->next();
       }
       system("PAUSE");
       delete it;
       delete masPuntuados;
    }
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << '\n';
       sleep(2);
    }
    
    return;
}

