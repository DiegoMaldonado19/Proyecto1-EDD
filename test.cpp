#include <iostream>
#include <string>
#include "ListaPlaylist.hpp"
#include "Pila.hpp"

int main(){

    int elemento=0;
    Cancion *cancion = new Cancion("One - Metallica", "C:\\Users\\ACER");
    Nodo *inicio = new Nodo(cancion, NULL);
    ListaCanciones *lista = new ListaCanciones("Lista 1", "Lista de prueba");
    Cancion *cancion2 = new Cancion("Beso - Rosalia", "C:\\Users\\ACER");
    Cancion *cancion3 = new Cancion("Leech - Sylosis", "C:\\Users\\ACER");
    Cancion *cancion4 = new Cancion("Arise - Sepultura", "C:\\Users\\ACER");
    lista->insertarCancion(cancion2);
    lista->insertarCancion(cancion3);
    lista->insertarCancion(cancion4);

    Cancion *cancion5 = new Cancion("Chicharron - Guayna", "C:\\Users\\ACER");
    Cancion *cancion6 = new Cancion("Rompe Rodillas - Guayna", "C:\\Users\\ACER");
    Cancion *cancion7 = new Cancion("Tra Tra - Guayna", "C:\\Users\\ACER");
    Cancion *cancion8 = new Cancion("", "C:\\Users\\ACER");
    Cancion *cancion9 = new Cancion("Chicharron - Guayna", "C:\\Users\\ACER");
    Cancion *cancion10 = new Cancion("Chicharron - Guayna", "C:\\Users\\ACER");

    Nodo *inicio2 = new Nodo(cancion5, NULL);

    ListaCanciones *lista2 = new ListaCanciones("Lista 2", "Lista en array");
    lista2->insertarCancion(cancion5);
    lista2->insertarCancion(cancion6);
    lista2->insertarCancion(cancion7);
    lista2->insertarCancion(cancion8);
    lista2->insertarCancion(cancion9);
    lista2->insertarCancion(cancion10);

    ListaPlaylist *listadoPlaylist = new ListaPlaylist();

    NodoPlaylist *nodoNuevo = new NodoPlaylist(lista, NULL);
    NodoPlaylist *nodoNuevo2 = new NodoPlaylist(lista2, NULL);

    listadoPlaylist->insertarListaPlaylist(nodoNuevo);
    listadoPlaylist->insertarListaPlaylist(nodoNuevo2);

    listadoPlaylist->graficarListaPlaylist();

    Pila *pila = new Pila(10);

    Cancion *cancionPila = new Cancion("Song 1", "C:\\");
    Cancion *cancionPila2 = new Cancion("Song 2", "C:\\");
    Cancion *cancionPila3 = new Cancion("Song 3", "C:\\");
    Cancion *cancionPila4 = new Cancion("Song 4", "C:\\");
    Cancion *cancionPila5 = new Cancion("Song 5", "C:\\");
    Cancion *cancionPila6 = new Cancion("Song 6", "C:\\");

    pila->push(cancionPila);
    pila->push(cancionPila2);
    pila->push(cancionPila3);
    pila->push(cancionPila4);
    pila->push(cancionPila5);
    pila->push(cancionPila6);

    pila->imprimirPila();

    delete pila;

    delete lista;
    delete lista2;
    return 0;
}