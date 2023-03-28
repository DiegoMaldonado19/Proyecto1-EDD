#include <stdlib.h>
#include "Cancion.hpp"

using namespace std;

class Nodo{
    private:
        Cancion *cancion;
        Nodo *siguiente;
    public:
        Nodo(Cancion *cancion);

        ~Nodo();

        Cancion* getCancion();

        void setCancion(Cancion *cancion);

        Nodo* getSiguiente();

        void setSiguiente(Nodo *siguiente);
};