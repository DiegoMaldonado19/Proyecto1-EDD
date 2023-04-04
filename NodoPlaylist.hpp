#include <stdlib.h>
#include "ListaCanciones.hpp"

using namespace std;

class NodoPlaylist{
    private:
        int indice;
        ListaCanciones *lista;
        NodoPlaylist *siguiente;
    public:
        
        NodoPlaylist(ListaCanciones *lista, NodoPlaylist *siguiente);

        ~NodoPlaylist();

        ListaCanciones* getLista();

        void setLista(ListaCanciones *lista);

        NodoPlaylist* getSiguiente();

        void setSiguiente(NodoPlaylist *siguiente);

        int getIndice();

        void setIndice(int indice);
};