#include <iostream>
#include <string>
#include "Nodo.hpp"

int main(){
    Cancion *cancion = new Cancion("Diego", "sdfdsf");

    /*
    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;

    cancion->setNombre("JOse");
    cancion->setPath("132");

    cout<<"Nombre cancion: "<<cancion->getNombre()<<endl;
    cout<<"Path de la cancion: "<<cancion->getPath()<<endl;   
    */
    Nodo *nodo = new Nodo(cancion);

    cout<<"Abriendo desde nodo, nombre cancion: "<<nodo->getCancion()->getNombre()<<endl;
    delete nodo;
}