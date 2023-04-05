#include <string>
#include <iostream>
#include "Cancion.hpp"

using namespace std;

class Pila{
    public: 
        Cancion** array;
        int top;
        int capacidad;

    public:
        Pila(int tamanio);

        ~Pila();

        void push(Cancion *elemento);

        void pop();

        int getTamanio();

        bool vacia();

        bool llena();

        void imprimirPila();
};