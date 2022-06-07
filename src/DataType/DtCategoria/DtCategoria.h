#ifndef DTCATEGORIA_HEADER
#define DTCATEGORIA_HEADER

#include<string>
using std::string;

class DtCategoria {
    private:
      string nombre;
      string descripcion;
      string tipo;
    public:
      DtCategoria(string nombre, string descripcion, string tipo);
      string getNombre();
      string getDescripcion();
      string getTipo();

}

#endif