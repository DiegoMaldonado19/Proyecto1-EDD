#ifndef LISTAPLAYLIST_H
#define LISTAPLAYLIST_H
#include <stdlib.h>
#include <string>
#include "NodoPlaylist.hpp"

using namespace std;

class ListaPlaylist{
    private:
        NodoPlaylist *cabeza;

    public: 
        static int numeroElementos;

        ListaPlaylist();

        ~ListaPlaylist();

        void insertarListaPlaylist(NodoPlaylist *nuevo);

        void eliminarListaPorIndice(int indice);

        void eliminarListaPorNombre(string nombre);

        bool isVacia();

        void graficarListaPlaylist();

        void actualizarDatosListaPorIndice(int indice);

        void arreglarIndices();

        NodoPlaylist* obtenerNodoPlaylist(int indice);

        void ingresarCancion(Cancion* cancion, int id);

        void eliminarCancion(int cancionId, int id);

        void imprimirListaEspecifica(int id);

        void reproduccionNormal(int id);

        void reproduccionRepeticion(int id);
};
#endif 