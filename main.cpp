#include <iostream>

#include "src/Clases/Sistema.cpp"

using namespace std;

int main()
{
    Sistema *s = s->getInstance();

    /*try{
        ICollection * col = s->listarSuscripcionesPorVideojuego();
        IIterator * it = col->getIterator();
        DtSuscripcion * current;
        while (it->hasCurrent()){
            current = (DtSuscripcion*)it->getCurrent();
            cout << current->getNombreVideojuego();
        }

    }catch(invalid_argument e){
        cout << "debes logearte primero";
    }*/


    cout << "Hola";
    return 0;
}