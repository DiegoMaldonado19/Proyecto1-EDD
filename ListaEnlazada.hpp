#include <stdlib.h>
#include <string>
#include "Nodo.hpp"

using namespace std;

class ListaEnlazada{
    private:
        string nombre;
        string descripcion;
        Nodo *cabeza;

    public: 
        static int numeroElementos;

        ListaEnlazada(string nombre, string descripcion);

        ~ListaEnlazada();

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