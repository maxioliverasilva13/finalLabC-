#include "Sistema.h"
// #include "../Clases/Categoria/Categoria.cpp"
#include "../ICollection/Integer.cpp"
#include "../DataType/DtCategoria/DtCategoria.cpp"
#include "../ICollection/String.cpp"
#include "../ICollection/interfaces/IDictionary.cpp"
#include "../ICollection/interfaces/IIterator.cpp"
#include "../ICollection/collections/ListIterator.cpp"
#include "../ICollection/collections/ListNode.cpp"
#include "../ICollection/interfaces/OrderedKey.cpp"
#include "../ICollection/interfaces/IKey.cpp"
#include "../ICollection/interfaces/ICollection.cpp"
#include "../ICollection/collections/List.cpp"
#include "../ICollection/collections/OrderedDictionary.cpp"
#include "../ICollection/collections/OrderedDictionaryEntry.cpp"
#include "../clases/CategoriaPlataforma/CategoriaPlataforma.h"
#include "../clases/CategoriaPlataforma/CategoriaPlataforma.cpp"
#include "../clases/CategoriaOtro/CategoriaOtro.cpp"

Sistema *Sistema::instance = NULL;

Sistema::Sistema()
{
  this->categorias = new OrderedDictionary();
  this->videojuegos = new OrderedDictionary();
  this->usuarios = new OrderedDictionary();
}

Sistema *Sistema::getInstance()
{
  if (Sistema::instance == NULL)
  {
    Sistema::instance = new Sistema();
  }
  return Sistema::instance;
}

//-----------------HELPER FUNCTIONS-----------------------------

bool validateExistsGameName(string nameGame, IDictionary *games)
{
  char *charNameVj = const_cast<char *>(nameGame.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  Videojuego *juego = (Videojuego *)games->find(vjKey);

  if (juego)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------------------------------------

void Sistema::listarVJ()
{
  IIterator *it = this->videojuegos->getIterator();
  while (it->hasCurrent())
  {
    Videojuego *vj = (Videojuego *)it->getCurrent();
    cout << "------" << endl;
    cout << vj->getNombre() << endl;
    it->next();
  }
  delete it;
}

void Sistema::eliminarVideoJuego(string nombreVideojuego)
{
  bool existeGame = validateExistsGameName(nombreVideojuego, this->videojuegos);
  if (existeGame)
  {
    char *charNameVj = const_cast<char *>(nombreVideojuego.c_str()); // paso de string a char (para poder implementar la key)
    String *vjKey = new String(charNameVj);
    Videojuego *vj = (Videojuego *)this->videojuegos->find(vjKey);
    this->videojuegos->remove(vjKey);
    delete vj;
    delete charNameVj;
    delete vjKey;
  }
  else
  {
    throw invalid_argument("El videojuego que intenta eliminar no existe");
  }
}

void Sistema::agregarCategoria(ICollectible *category)
{
  Categoria *categoria;
  DtCategoria *cat = (DtCategoria *)category;
  if (getEGeneroJuego(getEnumGeneroJuego(cat->getTipo())) != "NINGUNO")
  {
    // ES UN GENRO DE TIPO CATEGORIAGENERO
    categoria = new CategoriaGenero(getEnumGeneroJuego(cat->getTipo()), cat->getDescripcion(), 1);
  }
  else if (getETipoPlataforma(getEnumETipoPlataforma(cat->getTipo())) != "NINGUNO")
  {
    // ES UN GENRO DE TIPO CATEGORIAPLATAFORMA
    categoria = new CategoriaPlataforma(getEnumETipoPlataforma(cat->getTipo()), cat->getDescripcion(), 1);
  }
  else
  {
    categoria = new CategoriaOtro(cat->getTipo(), cat->getDescripcion(), 1);
  }

  Integer *idKey = new Integer(categoria->getId());
  this->categorias->add(idKey, categoria);
}

void Sistema::agregarVideojuego(string nombre, string descricpcion, ICollection *costos_suscripcion, ICollection *dtsCategorias)
{
  bool existsGame = validateExistsGameName(nombre, this->videojuegos);

  if (existsGame)
  {
    throw invalid_argument("El videojuego " + nombre + " videojuego ya existe");
  }
  Videojuego *vj = new Videojuego(nombre, descricpcion, 0);

  IIterator *iterator = costos_suscripcion->getIterator();

  int iteratorId = 0;
  while (iterator->hasCurrent())
  {
    iteratorId++;
    DtCostoSuscripcion *dtcostoS = (DtCostoSuscripcion *)iterator->getCurrent();
    Suscripcion *suscripcion = new Suscripcion(iteratorId, dtcostoS->getCosto(), dtcostoS->getTipo(), vj);
    vj->agregarSuscripcion(suscripcion);
    iterator->next();
  };

  if (dtsCategorias)
  {
    IIterator *iteratorCategorias = dtsCategorias->getIterator();
    int iteratorIdC = 0;

    while (iteratorCategorias->hasCurrent())
    {
      iteratorIdC++;
      Categoria *categoria;
      DtCategoria *dtcat = (DtCategoria *)iteratorCategorias->getCurrent();

      if (getEGeneroJuego(getEnumGeneroJuego(dtcat->getTipo())) != "NINGUNO")
      {
        // ES UN GENRO DE TIPO CATEGORIAGENERO
        categoria = new CategoriaGenero(getEnumGeneroJuego(dtcat->getTipo()), dtcat->getDescripcion(), iteratorIdC);
      }
      else if (getETipoPlataforma(getEnumETipoPlataforma(dtcat->getTipo())) != "NINGUNO")
      {
        // ES UN GENRO DE TIPO CATEGORIAPLATAFORMA
        categoria = new CategoriaPlataforma(getEnumETipoPlataforma(dtcat->getTipo()), dtcat->getDescripcion(), iteratorIdC);
      }
      else
      {
        categoria = new CategoriaOtro(dtcat->getTipo(), dtcat->getDescripcion(), iteratorIdC);
      }

      Integer *categoriaKey = new Integer(categoria->getId());
      vj->agregarCategoria(categoria);
      iteratorCategorias->next();
    };
  }

  char *charNameVj = const_cast<char *>(nombre.c_str()); // paso de string a char (para poder implementar la key)
  String *vjKey = new String(charNameVj);
  this->videojuegos->add(vjKey, vj);
}