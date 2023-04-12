#include "Nodo.hpp"
#include <string.h>
#include <stdlib.h>
#include "Pila.hpp"

using namespace std;

class ListaCanciones{
    private:
        string nombre;
        string descripcion;
        Nodo* primero;
        Nodo* ultimo;

    public:
        static int numeroElementos;

        ListaCanciones(string nombre, string descripcion);

        ~ListaCanciones();

        string getNombre();

        void setNombre(string nombre);

        string getDescripcion();

        void setDescripcion(string nombre);

        Nodo* getPrimero();

        void setPrimero(Nodo* primero);

        Nodo* getUltimo();

        void setUltimo(Nodo* ultimo);

        void insertarCancion(Cancion* cancion);

        void imprimirLista();

        void buscarElemento(string nombre);

        void eliminarElementoPorId(int id);

        void eliminarElementoPorNombre(string nombre);

        void arreglarIndices();

        void reproduccionNormal();

        void reproduccionRepeticion();

        void reproduccion(Cancion* cancion);

        Pila* listaDeReproduccion(Cancion* cancionActual);

        void visualizarListaDeReproduccion(Pila* pila);

        Cancion* obtenerCancion(int id);

        Cancion* obtenerCancionProvidencial(int id);

        bool isVacia();

        void reiniciarNumeroElementos();
};