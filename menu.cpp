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
        //case 2: publicarVideojuegoMenu();break; // TODO
        //case 3: eliminarVideojuegoMenu(); break; // TODO
        //case 4: consultarEstadisticasMenu(); break; // TODO
        //case 5: verInfoVideojuegoMenu(); break; // TODO
        case 6: modificarFechaSistemaMenu(); break;
        case 7: cerrarSesionMenu(); cerrarMenuDesarrollador = true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
    }  
}

void menuJugador(){
    mostrarMenuJugador();
    int eleccion = leerInt();
    switch (eleccion){
        //case 1: suscribirseAvideojuegoMenu(); break; // TODO
        //case 2: asignarPuntajeVJMenu();break; // TODO
        //case 3: iniciarPartidaMenu(); break; // TODO
        //case 4: abandonarPartidaMJMenu(); break; // TODO
        //case 5: finalizarPartidaMenu(); break; // TODO
        //case 6: verInformacionVideojuegoMenu(); break; // TODO
        case 7: modificarFechaSistemaMenu(); break;
        case 8: cerrarSesionMenu(); cerrarMenuJugador = true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
    } 
}

// falta cargar más datos, a medida que se agreguen funcionalidades
void cargarDatosDePruebaMenu(){
    system("cls");
    cout << "Cargando datos de prueba..." << endl;
    sleep(1);

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

    system("cls");
    cout << "Datos de prueba cargados." << endl;
    sleep(1);
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

void recorrerCategoriasMenu(ICollection * colecc) // ELIMINAR, SOLO CON FINES DE TESTING.
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

    DtCategoria * categoriaNueva = new DtCategoria(nombre, descripcion, tipo);
    s->agregarCategoria(categoriaNueva);   
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