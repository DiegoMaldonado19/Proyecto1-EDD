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

        void eliminarCancion();

        bool isVacia();

        void graficarLista();

        void buscarCancion();

        int* getNumeroElementos();
};