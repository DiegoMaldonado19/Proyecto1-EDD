#include "Nodo.hpp"

Nodo::Nodo(Cancion *cancion){
    this->cancion = cancion;
    this->siguiente = NULL;
}

Nodo::~Nodo(){
    cout<<"Eliminando Cancion "<<this->cancion->getNombre()<<endl;
}

Cancion* Nodo::getCancion(){
    return this->cancion;
}

void Nodo::setCancion(Cancion *cancion){
    this->cancion = cancion;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

