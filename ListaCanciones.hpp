#include <stdlib.h>
#include <string>
#include "Nodo.hpp"

using namespace std;

class ListaCanciones{
    private:
        string nombre;
        string descripcion;
        Nodo *cabeza;

    public: 
        static int numeroElementos;

        ListaCanciones();

        ListaCanciones(string nombre, string descripcion);

        ~ListaCanciones();

        void insertarCancion(Cancion *cancion);

        void eliminarCancionPorNombre(string nombre);

        void eliminarCancionPorIndice(int indice);

        bool isVacia();

        void graficarLista();

        void buscarCancionPorNombre(string nombre);

        void buscarCancionPorIndice(int indice);

        void arreglarIndices();

        Nodo* obtenerNodo(int indice);

        void setNombre(string nombre);

        string getNombre();

        void setDescripcion(string nombre);

        string getDescripcion();
};