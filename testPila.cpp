#include <iostream>
#include <string>
#include "Pila.hpp"

using namespace std;

int main(){


    Pila *pila = new Pila(10);

    Cancion *cancion = new Cancion("Song 1", "C:\\");
    Cancion *cancion2 = new Cancion("Song 2", "C:\\");
    Cancion *cancion3 = new Cancion("Song 3", "C:\\");
    Cancion *cancion4 = new Cancion("Song 4", "C:\\");
    Cancion *cancion5 = new Cancion("Song 5", "C:\\");
    Cancion *cancion6 = new Cancion("Song 6", "C:\\");

    pila->push(cancion);
    pila->push(cancion2);
    pila->push(cancion3);
    pila->push(cancion4);
    pila->push(cancion5);
    pila->push(cancion6);

    delete pila;

    return 0;
}