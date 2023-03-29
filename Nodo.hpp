#include <stdlib.h>
#include "Cancion.hpp"

using namespace std;

class Nodo{
    private:
        int indice;
        Cancion *cancion;
        Nodo *siguiente;
    public:
        Nodo(Cancion *cancion, Nodo *siguiente);

        ~Nodo();

        Cancion* getCancion();

        void setCancion(Cancion *cancion);

        Nodo* getSiguiente();

        void setSiguiente(Nodo *siguiente);

        int getIndice();

        void setIndice(int indice);
};