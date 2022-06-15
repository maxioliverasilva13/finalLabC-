#include "./src/Clases/Sistema.cpp"
#include <limits> // para validar ints en el cin
#include <iostream> 
#include <cstdlib> //es para el clear
#include <stdlib.h> // tambien para el clear pero fuera de windows
#include <string>

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
Usuario * usuarioActual = NULL;

void mostrarMenu();
int leerInt();
string leerString();

void mostrarMenuDesarrollador(); //contiene la interfaz grafica del menu de desarrollador
void menuDesarrollador(); //contiene el switch de opciones del menu del desarrollador

// *.*.*.*.*.*.*.*. Funciones del menú .*.*.*.*.*.*.*.*.*.*
// Usuario
void altaUsuarioMenu();
void iniciarSesionMenu();

// Desarrollador
void cambiarFechaSistemaMenu();
// *.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

// *.*.*.*.*.*. Funciones auxiliares a las del menú *.*.*.*
int menuJugadorOdesarrollador();
// *.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.

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


void menu(){
    int eleccion;
    bool menu = true;

    while(menu){
        if (usuarioActual == NULL){
            mostrarMenu();
            eleccion = leerInt();

            switch (eleccion){
                case 1: altaUsuarioMenu(); break;
                case 2: iniciarSesionMenu();break;
                //case 3: agregarJugadorMenu(); break;
                case 4: menu = false; system("cls");break;
                default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
            }
        } else {
            string instancename = typeid(*usuarioActual).name(); // almacena el nombre de la instancia en un string
            instancename = removerNumeros(instancename);
            if (instancename == "Desarrollador"){
                menuDesarrollador();
            } else if (instancename == "Jugador"){
                //menuDesarrollador(); TODO: implementar esa funcion
                cout << "Jugador" << endl;
            } 
        }
    }
}

void menuDesarrollador(){
    int eleccion;
    bool menu = true;

    while(menu){
        mostrarMenuDesarrollador();
        eleccion = leerInt();
        switch (eleccion){
            //case 1: altaUsuarioMenu(); break;
            //case 2: iniciarSesionMenu();break;
            //case 3: agregarJugadorMenu(); break;
            //case 4: agregarJugadorMenu(); break;
            //case 5: agregarJugadorMenu(); break;
            case 6: cambiarFechaSistemaMenu(); break;
            case 7: menu = false; system("cls");break;
            default: system("cls"); cout<<"Valor invalido, vuelva a intentarlo."; sleep(2); break; 
        }    
    }
    return;
}

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
    // 4 confirmar o cancelar el alta

    system("cls");
    string email;
    cout << "Ingrese el EMAIL para el usuario: "<< endl;
    email = leerString();

    system("cls");
    string pass;
    cout << "Ingrese PASSWORD para el usuario: "<< endl;
    pass = leerString();

    int tipoUsuario = menuJugadorOdesarrollador();

    try{
        if (tipoUsuario == 1){ // eligió Jugador           
            //bucle hasta que ponga un nickname que no exista o se quiera salir
            //confirmar alta
            try{
                bool ok = false;
                bool error = false;
                while (!ok){
                    try
                    {
                        if (error == true){
                            bool eleccion = menuDeseaContinuarOcancelar();
                            if (eleccion == false)
                                return;
                        }
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
                        error = true;
                        sleep(2);
                    }
                }
            }
            catch(const std::exception& e)
            {
                system("cls");
                std::cerr << e.what() << '\n';
                sleep(2);
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
            }
            catch(const std::exception& e)
            {
                system("cls");
                std::cerr << e.what() << '\n';
                sleep(2);
            }
        }
    }catch(const std::exception& e){
        system("cls");
        std::cerr << e.what() << '\n';
        sleep(2);
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
    bool error = false;
    while (!ok){
        try{
            if (error == true){
                system("cls");
                bool eleccion = menuDeseaContinuarOcancelar();
                if (eleccion == false){
                    return;
                }
            }
            system("cls");
            cout << "Ingrese EMAIL para el inicio de sesion: "<< endl;
            email = leerString();

            system("cls");
            cout << "Ingrese PASSWORD para el inicio de sesion: "<< endl;
            password = leerString();

            system("cls");
            s->iniciarSesion(email, password);
            usuarioActual = s->getLoggUser();
            ok = true;
            sleep(2);
        }catch(const std::exception& e){
            system("cls");
            std::cerr << e.what() << '\n';
            error = true;
            sleep(2);
        }
    }
}

// TODO: pedir fecha con formato y parsear (LEO) xd
void cambiarFechaSistemaMenu(){
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
    }
}