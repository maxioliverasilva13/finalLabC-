#include "./src/Clases/Sistema.cpp"
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
bool menuUsuario();
bool menuDesarrollador(); //contiene el switch de opciones del menu del desarrollador
bool menuJugador(); //contiene el switch de opciones del menu del desarrollador

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
//modificarFechaSistemaMenu();

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

// TODO: IMPLEMENTAR INTERFAZ GRAFICA
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

void menu(){
    try
    {
        if (usuarioActual == ""){
            while(!menuUsuario()){
                menuUsuario();
            }
        } else {
            if (usuarioActual == "Desarrollador"){
                while(!menuDesarrollador()){
                    menuDesarrollador();
                }
                //mostrarMenuDesarrollador();
                //menu = false; // se cierra el menu normal, al salir del while.
                sleep(2);
            } else if (usuarioActual == "Jugador"){
                while(!menuJugador()){
                    menuJugador();
                }
                sleep(2);
            } 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        sleep(2);
    } 
}

// TODO 
// logica e interfaz grafica del menu de usuario
bool menuUsuario(){
        mostrarMenu();
        int eleccion = leerInt();

        switch (eleccion){
            case 1: altaUsuarioMenu(); break;
            case 2: iniciarSesionMenu();break;
            //case 3: cargarDatosDePruebaMenu(); break;
            case 4: system("cls"); return true; break;
            default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
        }
    return false;
}

// TODO
// logica e interfaz grafica del menu de desarrollador
bool menuDesarrollador(){
    mostrarMenuDesarrollador();
    int eleccion = leerInt();
    switch (eleccion){
        case 1: agregarCategoriaMenu(); break;
        //case 2: publicarVideojuegoMenu();break;
        //case 3: eliminarVideojuegoMenu(); break;
        //case 4: consultarEstadisticasMenu(); break;
        //case 5: verInfoVideojuegoMenu(); break;
        case 6: modificarFechaSistemaMenu(); break;
        case 7: return true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
    }  
}

// TODO: IMPLEMENTAR LOGICA JUGADOR
bool menuJugador(){
    mostrarMenuJugador();
    int eleccion = leerInt();
    switch (eleccion){
        //case 1: suscribirseAvideojuegoMenu(); break;
        //case 2: asignarPuntajeVJMenu();break;
        //case 3: iniciarPartidaMenu(); break;
        //case 4: abandonarPartidaMJMenu(); break;
        //case 5: finalizarPartidaMenu(); break;
        //case 6: verInformacionVideojuegoMenu(); break;
        case 7: modificarFechaSistemaMenu(); break;
        case 8: return true; system("cls");break;
        default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
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
    // 1 pido email y contrasenia
    // 2 pregunto si será jugador (nickname, descripcion) o desarrollador (nombreempresa)
    // 3 si existe user con el nick, se le sigue preguntando hasta q no quiera
    //  TODO 4 confirmar o cancelar el alta

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
    if (ok == true){
        if (usuarioActual == "Desarrollador"){
            while (!menuDesarrollador()){
                menuUsuario();
            }
        } else if (usuarioActual == "Jugador"){
            while(!menuJugador()){
                menuJugador();
            }
        } 
    }
        
}

// Desarrollador
void agregarCategoriaMenu(){
    ICollection * cats = s->listarCategorias();
    cats = s->listarCategorias();
    IIterator *it = cats->getIterator();
    // imprimo las categorias
    while (it->hasCurrent()){
        DtCategoria * cat = (DtCategoria*)it->getCurrent();
        cout << cat->getNombre() << endl;
        it->next();
    }
    delete it;
    system("PAUSE");
    // luego de listar, pregunto por la categoria a agregar
    string nombre;
    string descripcion;
    string tipo;

    // TODO: validar en un menu aparte las 3 opciones (Plataforma(EnumETipoPlataforma), Genero(EnumGeneroJuego) u Otro)
    cout << "Ingrese el TIPO de la CATEGORIA a agregar: "<< endl;
    tipo = leerString();
    system("cls");

    // TODO: dar las opciones en un menu aparte, si eligió Otro, 
    //       le pasa un string sino en las otras 2 le pasas un Enum
    cout << "Ingrese el NOMBRE de la CATEGORIA a agregar: "<< endl;
    nombre = leerString();
    system("cls");

    cout << "Ingrese la DESCRIPCION para la CATEGORIA a agregar: "<< endl;
    descripcion = leerString();
    system("cls");

    DtCategoria * categoriaNueva = new DtCategoria(nombre, descripcion, tipo);
    s->agregarCategoria(categoriaNueva);
    //s->agregarCategoria(); recibe un icollectible
}
// TODO: pedir fecha con formato y parsear (LEO) xd
void modificarFechaSistemaMenu(){
    try
    {
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;

        system("cls");
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
        sleep(2);
    }
    catch(const std::exception& e)
    {
        system("cls");
        std::cerr << e.what() << '\n';
        sleep(2);
    }
}