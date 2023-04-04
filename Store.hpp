#include <stdlib.h>
#include <string>
#include "Nodo.hpp"

using namespace std;

class Store{
    private:
        string nombre;
        string descripcion;
        Nodo *cabeza;

    public: 
        static int numeroElementos;

        Store(string nombre, string descripcion);

        ~Store();

        void insertarCancion(Cancion *cancion);

        void eliminarCancionPorNombre(string nombre);

        void eliminarCancionPorIndice(int indice);

        bool isVacia();

        void graficarLista();

        void buscarCancionPorNombre(string nombre);

        void buscarCancionPorIndice(int indice);

        int* getNumeroElementos();

        void arreglarIndices();

        Nodo* obtenerNodo(int indice);
};