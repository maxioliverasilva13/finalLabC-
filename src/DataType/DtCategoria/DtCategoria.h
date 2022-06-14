#ifndef DTCATEGORIA_HEADER
#define DTCATEGORIA_HEADER

#include "../../Clases/Categoria/Categoria.h"

#include<string>
using std::string;

class DtCategoria: public ICollectible {
    private:
      string nombre;
      string descripcion;
      string tipo; // este string tendria que ser igual a ETIPOPLAYAFORMA y ETIPOGENERO
    public:
      DtCategoria(string nombre, string descripcion, string tipo);
      string getNombre();
      string getDescripcion();
      string getTipo();
};

#endif