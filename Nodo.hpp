#include "Cancion.hpp"
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Nodo{
    private:
        int indice;
        Cancion* cancion;
        Nodo* anterior;
        Nodo* siguiente;

    public:
        
        Nodo(Cancion* cancion);

        ~Nodo();

        Nodo* getAnterior();

        void setAnterior(Nodo* anterior);

        Nodo* getSiguiente();

        void setSiguiente(Nodo* siguiente);

        Cancion* getCancion();

        void setCancion(Cancion* cancion);

        int getIndice();

        void setIndice(int indice);
};