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

        bool isVacia();

        void graficarListaPlaylist();

        void actualizarDatosListaPorIndice(int indice);

        void arreglarIndices();

        NodoPlaylist* obtenerNodoPlaylist(int indice);
};