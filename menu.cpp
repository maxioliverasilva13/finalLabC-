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

string leerString(){
    string eleccion;
    getline(cin >> ws, eleccion); //ws hace que se puedan almacenar espacios.
    return eleccion;
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
            menuUsuario();
            while(!menuUsuario()){
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

// terminado
bool menuUsuario(){
        mostrarMenu();
        int eleccion = leerInt();

        switch (eleccion){
            case 1: altaUsuarioMenu(); break;
            case 2: iniciarSesionMenu();break;
            case 3: cargarDatosDePruebaMenu(); break;
            case 4: system("cls"); return true; break;
            default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
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

void menuJugador(){
    mostrarMenuJugador();
    int eleccion = leerInt();
    switch (eleccion){
        case 1: suscribirseAvideojuegoMenu(); break; // TODO
        case 2: asignarPuntajeVJMenu();break; 
        //case 3: iniciarPartidaMenu(); break; // TODO
        //case 4: abandonarPartidaMJMenu(); break; // TODO
        //case 5: finalizarPartidaMenu(); break; // TODO
        //case 6: verInformacionVideojuegoMenu(); break; // TODO queda pendiente que leo fixee su codigo y terminar de implementarla
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

        DtCategoria * c1 = new DtCategoria("PC", "Esta es la cat1", "PLATAFORMA");
        DtCategoria * c2 = new DtCategoria("PS4", "Esta es la cat2", "PLATAFORMA");
        DtCategoria * c3 = new DtCategoria("XBOXONE", "Esta es la cat3", "PLATAFORMA");
        DtCategoria * c4 = new DtCategoria("DEPORTE", "Esta es la cat4", "GENERO");
        DtCategoria * c5 = new DtCategoria("SUPERVIVENCIA", "Esta es la cat5", "GENERO");
        DtCategoria * c6 = new DtCategoria("ESTRATEGIA", "Esta es la cat6", "GENERO");
        DtCategoria * c7 = new DtCategoria("Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", "OTRO");
        DtCategoria * c8 = new DtCategoria("E", "Su contenido está dirigido para todo público", "OTRO");
        DtCategoria * c9 = new DtCategoria("ACCION", "Esta es la cat9", "GENERO");
        DtCategoria * c10 = new DtCategoria("AVENTURA", "Esta es la cat10", "GENERO");
        DtCategoria * c11 = new DtCategoria("SWITCH", "Esta es la cat11", "PLATAFORMA");
        DtCategoria * c12 = new DtCategoria("XBOXX", "Esta es la cat12", "PLATAFORMA");
        DtCategoria * c13 = new DtCategoria("PS5", "Esta es la cat13", "PLATAFORMA");
        
        s->agregarCategoria(c1);
        s->agregarCategoria(c2);
        s->agregarCategoria(c3);
        s->agregarCategoria(c4);
        s->agregarCategoria(c5);
        s->agregarCategoria(c6);
        s->agregarCategoria(c7);
        s->agregarCategoria(c8);
        s->agregarCategoria(c9);
        s->agregarCategoria(c10);
        s->agregarCategoria(c11);
        s->agregarCategoria(c12);
        s->agregarCategoria(c13);

        cout << "Datos de prueba cargados." << endl;
        sleep(1);
    }
    catch(const std::exception& e)
    {
        cout << "ERROR: Ya se habian cargado los datos de prueba." << endl;
        sleep(3);
    }   
}

bool menuDeseaContinuarOcancelar(){
    bool opcionValida = false;
    do{
        system("cls");
        cout << "Desea intentarlo nuevamente, o cancelar? " << endl;
        cout << "1 - Intentar de nuevo" << endl;
        cout << "2 - Cancelar" << endl;

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
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
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
        default:system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break;
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

    if (tipoCategoria == 1){
        system("cls");
        nombre = inputTipoPlataforma();
        tipo = "PLATAFORMA";   
        // luego le pido el nombre y descripcion
    }else if (tipoCategoria == 2){
        system("cls");
        nombre = inputTipoGenero();
        tipo = "GENERO";
    }else if (tipoCategoria == 3){
        system("cls");
        cout << "Ingrese el NOMBRE para la CATEGORIA a agregar: "<< endl;
        nombre = leerString();
        tipo = "OTRO";
    }

    system("cls");
    cout << "Ingrese la DESCRIPCION para la CATEGORIA a agregar: "<< endl;
    descripcion = leerString();
    system("cls");

    s->agregarCategoria(nombre, descripcion, tipo);
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
    system("cls");
    IIterator *it = colecc->getIterator();
    int contador_categorias = 1;
    while (it->hasCurrent()){
        DtCategoria *cat = (DtCategoria *)it->getCurrent();
        cout << "Categoria " << contador_categorias << ": " << endl;
        //cout << "ID: " << cat->getID() << ": " << endl;
        cout << "Nombre: "<< cat->getNombre() << endl;
        cout << "Descripcion: " << cat->getDescripcion() << endl;
        cout << "-----------------------------------------" << endl;
        contador_categorias++;
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
            cout << "---- Seleccione una Categoria: ----" << endl;
            // PERO TIENE QUE SER UN DICCIONARIO PARA PODER FILTRARLO
            ICollection * cats = s->listarCategorias(); // me traigo una copia (LISTA DE DTS) de las categorias registradas
            recorrerCategoriasID(cats); // muestro todas las categorias registradas
            int eleccionIDCategoria = leerInt();
            
            IIterator *it = cats->getIterator(); 

            //ICollectible * catAgregar = new DtCategoria( /*id del que findee*/, /*nombre del que hicefind*/, /*descripcion del find*/, /*tipo del find*/);
            //categorias_videojuego->add(catAgregar);


            termino = menuDeseaContinuarAgregando();
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
    cout << "pendiente...";
    return;
}


void consultarEstadisticasMenu(){
    cout << "pendiente...";
    return;
}

// TODO es re larga xd
void suscribirseAvideojuegoMenu(){
    cout << "pendiente...";
    return;
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
    cout << "---- Videojuegos ya registrados: ----" << endl;
    IDictionary * vj = s->listarVJ();
    recorrerVideojuegosMenu(vj);

    cout << "Ingrese el NOMBRE del VIDEOJUEGO de la lista: "<< endl;
    string nombrevj = leerString();

    char *charNameVj = const_cast<char *>(nombrevj.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    DtVideojuego * res = (DtVideojuego *)vj->find(vjKey);

    system("cls"); 
    cout << "---- Informacion del VIDEOJUEGO: ----" << endl;
    cout << "Nombre: " << res->getNombreVideojuego() << endl;
    cout << "Nombre: " << res->getDescripcionVideojuego() << endl;
    cout << "Nombre: " << res->getPromedioPuntuaciones() << endl;
    //cout << "Nombre: " << recorrerSuscripcionesVJ(res) << endl;
    //cout << "Nombre: " << recorrerCategoriasVJ(res) << endl;
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

void asignarPuntajeVJMenu(){
    try
    {
        cout << "---- Videojuegos ya registrados: ----" << endl;
        IDictionary * vj = s->listarVJ();
        recorrerVideojuegosMenu(vj);

        cout << "Ingrese el NOMBRE del VIDEOJUEGO de la lista: "<< endl;
        string nombrevj = leerString();

        cout << "Ingrese el PUNTAJE que desea asignar: "<< endl;
        int puntaje = leerInt();

        s->asignarPuntajeVideojuego(puntaje, nombrevj);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}
