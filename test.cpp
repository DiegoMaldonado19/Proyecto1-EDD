#include <iostream>
#include <string>
#include "ListaCanciones.hpp"

int main(){
    /*
    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;

    cancion->setNombre("JOse");
    cancion->setPath("132");

    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;   
    */

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

    ListaCanciones *array = new ListaCanciones[10];

    array[0] = lista;


    delete lista;
    delete lista2;
    return 0;
}