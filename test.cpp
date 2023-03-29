#include <iostream>
#include <string>
#include "ListaEnlazada.hpp"

int main(){
    /*
    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;

    cancion->setNombre("JOse");
    cancion->setPath("132");

    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;   
    */
    Cancion *cancion = new Cancion("One - Metallica", "C:\\Users\\ACER");
    Nodo *inicio = new Nodo(cancion, NULL);
    ListaEnlazada *lista = new ListaEnlazada("Lista 1", "Lista de prueba");
    Cancion *cancion2 = new Cancion("Beso - Rosalia", "C:\\Users\\ACER");
    Cancion *cancion3 = new Cancion("Leech - Sylosis", "C:\\Users\\ACER");
    Cancion *cancion4 = new Cancion("Arise - Sepultura", "C:\\Users\\ACER");
    lista->insertarCancion(cancion);
    lista->insertarCancion(cancion2);
    lista->insertarCancion(cancion3);
    lista->insertarCancion(cancion4);

    lista->graficarLista();
    
    lista->eliminarCancion(cancion->getNombre());

    lista->graficarLista();

    lista->buscarCancion(cancion3->getNombre());

    delete lista;
}