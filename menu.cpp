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

//estadisticas

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
    
    sleep(5);
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
            case 4: abandonarPartidaMJMenu();  break;
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
        case 3: iniciarPartidaMenu(); break;
        case 4: abandonarPartidaMJMenu(); break; // TODO
        //case 5: finalizarPartidaMenu(); break; // TODO
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

        s->agregarCategoria("PC", "Esta es la cat1", "PLATAFORMA");
        s->agregarCategoria("PS4", "Esta es la cat2", "PLATAFORMA");
        s->agregarCategoria("XBOXONE", "Esta es la cat3", "PLATAFORMA");
        s->agregarCategoria("DEPORTE", "Esta es la cat4", "GENERO");
        s->agregarCategoria("SUPERVIVENCIA", "Esta es la cat5", "GENERO");
        s->agregarCategoria("ESTRATEGIA", "Esta es la cat6", "GENERO");
        s->agregarCategoria("Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", "OTRO");
        s->agregarCategoria("E", "Su contenido está dirigido para todo público", "OTRO");
        s->agregarCategoria("ACCION", "Esta es la cat9", "GENERO");
        s->agregarCategoria("AVENTURA", "Esta es la cat10", "GENERO");
        s->agregarCategoria("SWITCH", "Esta es la cat11", "PLATAFORMA");
        s->agregarCategoria("XBOXX", "Esta es la cat12", "PLATAFORMA");
        s->agregarCategoria("PS5", "Esta es la cat13", "PLATAFORMA");

        s->agregarVideojuego("Minecraft", "desc1", NULL, NULL);
      
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

void finalizarPartidaMenu() {
    IDictionary* P = s->listarPartidasActivas();
    cout << "Listado de partidas activas: " << endl;
    IIterator* I = P->getIterator();
/*
    while (I->hasCurrent()) {
        DtPartida* info =(DtPartida*) I->getCurrent();
        cout << endl;
        cout << "ID: " << info->getId() << endl;
        cout << "Fecha de Inicio: " << info->getFecha();
        cout << "Videojuego: " << info->getVideojuego()->getNombreVideojuego() << endl;
        if (info->getTipo() == "Individual") {
            cout << "Continuacion de partida anterior: ";
            if (info->getNueva() == True) {
                cout << "Si" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else
        cout << "Transmitiada en vivo: ";
        if (info->getTransmitida() == true) {
            cout << "Si" << endl;
        }
        else {
            cout << "No" << endl;
            IIterator* J = info->getJugadores();
            cout << endl;
            cout << "Listado de jugadores unidos a la partida"
            while (J->hasCurrent()) {
                DtJugador* jugadores =(DtJugador*) J->getCurrent(); 
                cout << "-" << juegadores->getNick();
            }
        }
        cout << endl;
        do {
            Int Id;
            cout << "Ingrese el Id de la partida que desea finalizar" << endl;
            Id = leerInt();
            IKey* Pkey =(IKey*) new int(Id);
            I = P->find(Pkey)

            if (I == NULL) {
                system("cls"); 
                cout << "Id de partida incorrecto, por favor intente nuevamente"; 
                sleep(2); 
            }
        }
        while (I == NULL);
        DtPartida* f =(DtPartida*) I->getCurrent();
        s->finalizarPartida(f->getId());
    }
    */
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
        cout << "ID: " << cat->getId() << ": " << endl;
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
            termino = !menuDeseaContinuarAgregando();

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
    cin.clear();
    cout << "Ingresa el nombre de un videojuego: \n";
    string nameVj = leerString();
    char salir = 'n';
    DtVideojuego * res = NULL;
    do{
        res = s->verInfoVideojuego(nameVj);
        if(res == NULL){
            cout << "El juego: " << nameVj << " no existe" << endl;
            cout << "Deseas salir? y/n";
            salir = leerChar();
        }
    }while (res == NULL && (salir == 'n' || salir == 'N'));
    if(salir == 'y'){
        return;
    }

    cout << "-------------------------------------------";
    cout << "Nombre: " << res->getNombreVideojuego();
    cout << "Descripcion: " <<  res->getDescripcionVideojuego();
    cout << "De";
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
        cout << " Ingrese una opcion: (entre 1-1)" << endl;

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
        PartidaMultijugador * partidaMasLarga = s->partidaMasLarga();

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

       cout << "Ingrese un rango entre (1-5)" << endl;
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
        cout << "holi";
    }  
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}

void recorrerVideojuegosActivosMenu(ICollection * colecc ) 
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
bool recorrerJugadoresEnPartidaMenu(ICollection * colecc, String * nick ) 
{
    system("cls");
    IIterator *it = colecc->getIterator();
    while (it->hasCurrent())
    {
        String *nick = (String *)it->getCurrent();
        if(nick->getValue());
        it->next();
    }
    delete it;
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
        system("cls");
        cout << "Ingrese el nickname del jugador que desea agregar a esta partida: " << endl;
        string nick = leerString();
        ICollectible * jug = NULL;
        jug = s->findUserByNickname(nick); // revisar
        if(jug != NULL){
            jugadores->add(jug);
        }
        else
        {
            cout << "El jugador no existe." << endl;
            sleep(2);
        }
        //Valido si jugador ya existe en la lista que estoy creando
        //parseo el nick a char
        char *charNick = const_cast<char *>(nick.c_str()); // paso de string a char (para poder implementar la key)
        String * nickString = new String(charNick);
        bool jugadorYaExiste = recorrerJugadoresEnPartidaMenu(jugadores, nickString);
        if(jugadorYaExiste){
            cout << "Este jugador ya es parte de esta partida." << endl;
            sleep(2);
        }
        else
        {
            system("cls");
            cout << "EXITO: El jugador fue agregado a la partida." << endl;
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
    cout << "---- Videojuegos a los que estás suscrito: ----" << endl;
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
        }
        else{
            cout << "La partida no se inició." << endl;
            sleep(2);
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

